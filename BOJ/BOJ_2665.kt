import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val dx = intArrayOf(1,-1,0,0)
val dy = intArrayOf(0,0,1,-1)

fun main()=with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine()!!.toInt()
    val field = Array(n) { readLine()!! }
    val visited = Array(n) { Array(n) { false } }
    val pq = PriorityQueue<Triple<Int, Int, Int>>(compareBy {it.third})
    pq.add(Triple(0, 0, 0))
    visited[0][0] = true
    while (!pq.isEmpty()) {
        val now = pq.poll()
        if (now.first == n - 1 && now.second == n - 1) {
            print(now.third)
            break
        }
        for (i in 0 until 4) {
            val nx = dx[i] + now.first
            val ny = dy[i] + now.second
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[ny][nx]) continue
            visited[ny][nx] = true
            if (field[ny][nx] == '1') pq.add(Triple(nx, ny, now.third))
            else pq.add(Triple(nx, ny, now.third + 1))
        }
    }
}
