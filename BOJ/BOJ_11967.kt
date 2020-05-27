import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val dx = intArrayOf(1,-1,0,0)
val dy = intArrayOf(0,0,-1,1)

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }
    val fake = Array(n) { Array(n) { false } }
    val on = Array(n) { Array(n) { false } }
    val visited = Array(n) { Array(n) { false } }
    val field = Array(n) { Array(n) { hashSetOf<Pair<Int, Int>>() } }

    repeat(m) {
        val st = StringTokenizer(readLine()!!)
        val from = Pair(st.nextToken()!!.toInt() - 1, st.nextToken()!!.toInt() - 1)
        val to = Pair(st.nextToken()!!.toInt() - 1, st.nextToken()!!.toInt() - 1)
        field[from.second][from.first].add(to)
    }
    val q: Queue<Pair<Int, Int>> = LinkedList()
    q.add(Pair(0, 0))
    on[0][0] = true
    visited[0][0] = true
    var ans = 1
    while (!q.isEmpty()) {
        val now = q.poll()

        for (it in field[now.second][now.first]) { // 현 자리서 킬 수 있는 것 킴
            if (!on[it.second][it.first])
                ans++
            on[it.second][it.first] = true
            if (!visited[it.second][it.first] && fake[it.second][it.first]) { // fake가 켜진거면 레알화
                visited[it.second][it.first] = true
                q.add(Pair(it.first, it.second))
            }
        }

        for (it in 0 until 4) {
            val nx = dx[it] + now.first
            val ny = dy[it] + now.second
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[ny][nx]) continue
            if (!on[ny][nx]) { // 아직 켜지지 않은 곳
                fake[ny][nx] = true
                continue
            }
            // 이미 켜진 곳
            visited[ny][nx] = true
            q.add(Pair(nx, ny))
        }
    }
    print(ans)
}
