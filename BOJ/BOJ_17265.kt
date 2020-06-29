import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val dx = intArrayOf(2, 1, 1, 0)
val dy = intArrayOf(0, 1, 1, 2)
val ox = intArrayOf(1, 1, 0, 0)
val oy = intArrayOf(0, 0, 1, 1)

data class Coord(val x: Int, val y: Int, val value: Int)

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val N = readLine().toInt()
    val field = Array(N) {
        val st = StringTokenizer(readLine())
        Array(N) { st.nextToken() }
    }
    val ans = mutableListOf<Int>()
    val q: Queue<Coord> = LinkedList()
    q.add(Coord(0, 0, field[0][0].toInt()))
    while (true) {
        val size = q.size
        repeat(size) {
            val now = q.poll()
            if (now.x == N - 1 && now.y == N - 1)
                ans.add(now.value)
            for (i in 0 until 4) {
                val nx = dx[i] + now.x
                val ny = dy[i] + now.y
                val nox = ox[i] + now.x
                val noy = oy[i] + now.y
                if (nx >= N || ny >= N)
                    continue
                val nv = when (field[noy][nox]) {
                    "+" -> now.value + field[ny][nx].toInt()
                    "-" -> now.value - field[ny][nx].toInt()
                    else -> now.value * field[ny][nx].toInt()
                }
                q.add(Coord(nx, ny, nv))
            }
        }
        if (ans.isNotEmpty())
            break
    }
    ans.sort()
    print("${ans.last()} ${ans.first()}")
}
