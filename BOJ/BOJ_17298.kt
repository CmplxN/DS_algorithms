import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val N = readLine().toInt()
    val arr = readLine().split(' ').map { it.toInt() }
    val ans = Array(N) { -1 }
    val pq = PriorityQueue<Pair<Int, Int>>(compareBy { it.first })
    arr.forEachIndexed { index, i ->
        while (pq.isNotEmpty() && pq.peek().first < i) {
            val now = pq.poll()
            ans[now.second] = i
        }
        pq.add(Pair(i, index))
    }
    print(ans.toList().joinToString(" "))
}
