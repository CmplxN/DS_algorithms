import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

data class Edge(val to: Int, val dist: Int)

const val MAX = 1111111111

fun dij(edges: Array<MutableList<Edge>>, s: Int): Array<Int> {
    val pq = PriorityQueue<Edge>(compareBy { it.dist })
    val rtn = Array(edges.size) { MAX }
    pq.add(Edge(s, 0))
    while (pq.isNotEmpty()) {
        val now = pq.poll()
        if (rtn[now.to] != MAX) continue
        else rtn[now.to] = now.dist
        edges[now.to].forEach { pq.add(Edge(it.to, it.dist + now.dist)) }
    }
    return rtn
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    repeat(readLine().toInt()) {
        val (n, m, t) = readLine().split(' ').map { it.toInt() }
        var (s, g, h) = readLine().split(' ').map { it.toInt() - 1 }
        val edges = Array(n) { mutableListOf<Edge>() }
        repeat(m) {
            val st = StringTokenizer(readLine())
            val (a, b, d) =
                    Triple(st.nextToken().toInt() - 1, st.nextToken().toInt() - 1, st.nextToken().toInt())
            edges[a].add(Edge(b, d))
            edges[b].add(Edge(a, d))
        }
        val btw = edges[h].find { it.to == g }!!.dist
        val target = List(t) { readLine().toInt() - 1 }.sorted()
        val temp = dij(edges, s)
        if (temp[h] > temp[g])
            g = h.also { h = g }
        val result = dij(edges, g)
        val ans = mutableListOf<Int>()
        target.forEach {
            if (temp[h] + btw + result[it] <= temp[it])
                ans.add(it + 1)
        }
        println(ans.joinToString(" "))
    }
}
