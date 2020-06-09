import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

data class Shark(val x:Int, val y:Int, val no: Int, var dir: Int)
data class Coord(val x:Int, val y:Int)

val dx = intArrayOf(0,0,-1,1)
val dy = intArrayOf(-1,1,0,0)

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (N, M, K) = readLine()!!.split(' ').map { it.toInt() }
    val sharks = mutableListOf<Shark>()
    val field = Array(N) { i ->
        val st = StringTokenizer(readLine()!!)
        Array(N) { j ->
            val input = st.nextToken()!!.toInt()
            if (input != 0)
                sharks.add(Shark(j, i, input, 0))
            Pair(input, 0)
        }
    }
    sharks.sortBy { it.no }
    val st = StringTokenizer(readLine()!!)
    repeat(M) {
        sharks[it].dir = st.nextToken()!!.toInt() - 1
    }
    val moves = Array(M) {
        Array(4) {
            val st = StringTokenizer(readLine()!!)
            List(4) { st.nextToken()!!.toInt() - 1 }
        }
    }
    repeat(1001) {
        if (sharks.size == 1) {
            print(it)
            return
        }
        val set = mutableSetOf<Coord>()
        val next = mutableListOf<Shark>()
        FIRST@ for (shark in sharks) {
            for (dir in moves[shark.no - 1][shark.dir]) {
                val nx = shark.x + dx[dir]
                val ny = shark.y + dy[dir]
                if (nx < 0 || ny < 0 || nx >= N || ny >= N || (field[ny][nx].first != 0 && field[ny][nx].second + K > it)) continue
                if (!set.contains(Coord(nx, ny))) {
                    next.add(Shark(nx, ny, shark.no, dir))
                    set.add(Coord(nx, ny))
                }
                continue@FIRST
            }
            for (dir in moves[shark.no - 1][shark.dir]) {
                val nx = shark.x + dx[dir]
                val ny = shark.y + dy[dir]
                if (nx < 0 || ny < 0 || nx >= N || ny >= N || field[ny][nx].first != shark.no) continue
                if (!set.contains(Coord(nx, ny))) {
                    next.add(Shark(nx, ny, shark.no, dir))
                    set.add(Coord(nx, ny))
                }
                continue@FIRST
            }
        }
        sharks.clear()
        next.forEach { shark ->
            sharks.add(shark.copy())
        }
        sharks.sortBy { shark -> shark.no }
        sharks.forEach { shark ->
            if (field[shark.y][shark.x].second != it + 1 || field[shark.y][shark.x].second == 0)
                field[shark.y][shark.x] = Pair(shark.no, it + 1)
        }
    }
    print(-1)
}
