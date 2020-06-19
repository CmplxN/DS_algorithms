import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.abs

data class Coord(val x: Int, val y: Int)
data class Info(val coord: Coord, val t: Int)

val dx = intArrayOf(1, -1, 0, 0)
val dy = intArrayOf(0, 0, -1, 1)

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    var (N, M, K) = readLine().split(' ').map { it.toInt() }
    val field = Array(N) {
        val st = StringTokenizer(readLine())
        IntArray(N) { st.nextToken().toInt() }
    }
    var (y, x) = readLine().split(' ').map { it.toInt() - 1 }
    val candidate = mutableMapOf<Coord, Coord>()
    repeat(M) {
        val (y1, x1, y2, x2) = readLine().split(' ').map { it.toInt() - 1 }
        candidate[Coord(x1, y1)] = Coord(x2, y2)
    }
    while (candidate.isNotEmpty()) {
        var q: Queue<Info> = LinkedList()
        var visited = Array(N) { BooleanArray(N) { false } }
        val picked = mutableListOf<Coord>()
        var t1 = 0
        visited[y][x] = true
        q.add(Info(Coord(x, y), 0))
        while (true) {
            var size = q.size
            var enough = false
            while (size-- > 0) {
                val now = q.poll()
                if (candidate.containsKey(Coord(now.coord.x, now.coord.y))) {
                    t1 = now.t
                    enough = true
                    picked.add(Coord(now.coord.x, now.coord.y))
                    continue
                }
                for (i in 0 until 4) {
                    val nx = dx[i] + now.coord.x
                    val ny = dy[i] + now.coord.y
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[ny][nx] || field[ny][nx] == 1)
                        continue
                    visited[ny][nx] = true
                    q.add(Info(Coord(nx, ny), now.t + 1))
                }
            }
            if (q.size == 0 || enough)
                break
        }
        if (picked.size == 0) {
            print(-1)
            return
        }
        picked.sortWith(compareBy({ it.y }, { it.x }))
        x = candidate[picked[0]]!!.x
        y = candidate[picked[0]]!!.y
        candidate.remove(picked[0])

        q = LinkedList()
        visited = Array(N) { BooleanArray(N) { false } }
        visited[picked[0].y][picked[0].x] = true
        q.add(Info(Coord(picked[0].x, picked[0].y), 0))
        var t2 = -1
        while (q.isNotEmpty()) {
            val now = q.poll()
            if (now.coord.x == x && now.coord.y == y) {
                t2 = now.t
                break
            }
            for (i in 0 until 4) {
                val nx = now.coord.x + dx[i]
                val ny = now.coord.y + dy[i]
                if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[ny][nx] || field[ny][nx] == 1)
                    continue
                visited[ny][nx] = true
                q.add(Info(Coord(nx, ny), now.t + 1))
            }
        }
        if (t2 == -1 || K < t1 + t2) {
            print(-1)
            return
        } else {
            K = K - t1 + t2
        }
    }
    print(K)
}
