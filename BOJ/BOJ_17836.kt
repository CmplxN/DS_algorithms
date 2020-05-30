import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

data class Info(val x: Int, val y: Int, val sword: Int, val t: Int = 0)

val dx = intArrayOf(0,0,1,-1)
val dy = intArrayOf(1,-1,0,0)

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (N, M, T) = readLine()!!.split(' ').map { it.toInt() }
    val field = Array(N) {
        val st = StringTokenizer(readLine()!!)
        Array(M) { st.nextToken().toInt() }
    }
    val visited = Array(N) { Array(M) { Array(2) { false } } }
    val q: Queue<Info> = LinkedList()
    q.add(Info(0, 0, 0))
    visited[0][0][0] = true
    while (!q.isEmpty()) {
        val now = q.poll()
        if (now.x == M - 1 && now.y == N - 1) {
            print(now.t)
            return
        }
        if (now.t == T + 1)
            break
        for (i in 0 until 4) {
            val nx = dx[i] + now.x
            val ny = dy[i] + now.y
            if (nx < 0 || ny < 0 || nx >= M || ny >= N || visited[ny][nx][now.sword]) continue
            if (now.sword == 0 && field[ny][nx] == 1) continue
            visited[ny][nx][now.sword] = true
            if (field[ny][nx] == 2)
                q.add(Info(nx, ny, 1, now.t + 1))
            else
                q.add(Info(nx, ny, now.sword, now.t + 1))
        }
    }
    print("Fail")
}
