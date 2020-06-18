import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.sqrt

data class Info(val dist: Double, val from: Int, val to: Int)

fun find(a: Int, parent: Array<Int>): Int {
    if (parent[a] == a) return a
    var rtn = a
    while (parent[rtn] != rtn)
        rtn = parent[rtn]
    return rtn
}

fun doUnion(a: Int, b: Int, parent: Array<Int>, height: Array<Int>) {
    val A = find(a, parent)
    val B = find(b, parent)
    if (A == B)
        return
    if (height[A] > height[B])
        parent[B] = A
    else if (height[A] < height[B])
        parent[A] = B
    else {
        parent[A] = B
        height[B] = height[B] + 1
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    repeat(readLine().toInt()) {
        val (S, P) = readLine().split(' ').map { it.toInt() }
        val pq = PriorityQueue<Info>(compareBy { it.dist })
        val input = mutableListOf<Pair<Int, Int>>()
        repeat(P) {
            val st = StringTokenizer(readLine())
            input.add(Pair(st.nextToken().toInt(), st.nextToken().toInt()))
        }
        for (i in 0 until input.size) {
            for (j in i + 1 until input.size) {
                val x = input[i].first - input[j].first
                val y = input[i].second - input[j].second
                val dist = sqrt((x * x + y * y).toDouble())
                pq.add(Info(dist, i, j))
            }
        }
        var cnt = 0
        var ans = 0.0
        val parent = Array(P) { it }
        val height = Array(P) { 0 }
        while (!pq.isEmpty()) {
            val now = pq.poll()
            if (find(now.from, parent) == find(now.to, parent))
                continue
            doUnion(now.from, now.to, parent, height)
            cnt++
            if (cnt == P - S + 1) break
            ans = now.dist
        }
        println("%.2f".format(ans))
    }
}
