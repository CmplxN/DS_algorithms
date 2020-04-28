import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

data class Info(val dist:Int, val x: Int, val y: Int, val dir:Int)
val dx = intArrayOf(0,1,0,-1)
val dy = intArrayOf(-1,0,1,0)

fun main()=BufferedReader(InputStreamReader(System.`in`)).run {
    val (c, r) = readLine()!!.split(' ').map { it.toInt() }
    val field = Array(r) { readLine()!! }
    val visited = Array(r) { Array(c) { IntArray(4){999999999} } }
    val pq = PriorityQueue<Info>(compareBy { it.dist })
    var x = 0
    var y = 0
    field.forEachIndexed { index, s ->
        s.forEachIndexed { i, c ->
            if (c == 'C' && pq.isEmpty()) {
                pq.add(Info(0, i, index, -1))
                visited[index][i][0] = 0
                visited[index][i][1] = 0
                visited[index][i][2] = 0
                visited[index][i][3] = 0
            } else if (c == 'C') {
                x = i
                y = index
            }
        }
    }
    while (!pq.isEmpty()) {
        val now = pq.poll()
        for (it in 0..3) {
            val nx = now.x + dx[it]
            val ny = now.y + dy[it]
            if (nx < 0 || ny < 0 || nx >= c || ny >= r || field[ny][nx] == '*' || visited[ny][nx][it] <= now.dist) continue
            if (now.dir != it) {
                pq.add(Info(now.dist + 1, nx, ny, it))
                visited[ny][nx][it] = now.dist + 1
            } else {
                pq.add(Info(now.dist, nx, ny, it))
                visited[ny][nx][it] = now.dist
            }
        }
    }
    print(visited[y][x].min()?.minus(1))
}
