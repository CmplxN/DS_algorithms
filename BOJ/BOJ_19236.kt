import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

data class Fox(val x: Int, val y: Int, val dir: Int)
data class Mouse(val num: Int, var dir: Int)
data class Coord(var x: Int, var y: Int)

val dx = intArrayOf(0,-1,-1,-1,0,1,1,1)
val dy = intArrayOf(-1,-1,0,1,1,1,0,-1)
var ans = 0

fun dfs(acc: Int, fox: Fox, mMap: MutableMap<Coord, Mouse>) {
    var cnt = 1
    while (true) {
        if (fox.x == -1 && cnt != 1) break
        val nx = dx[fox.dir] * cnt + fox.x
        val ny = dy[fox.dir] * cnt + fox.y
        cnt++
        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) break
        if (mMap[Coord(nx, ny)] == null) continue
        val newFox = Fox(nx, ny, mMap[Coord(nx, ny)]!!.dir)
        val newAcc = acc + mMap[Coord(nx, ny)]!!.num
        val miceList = mMap.map {
            Pair(it.value.num, it.key)
        }.filter { !(it.second.x == nx && it.second.y == ny) }.toMap().toMutableMap()
        val newMap = mutableMapOf<Coord, Mouse>()
        mMap.forEach { if (!(it.key.x == nx && it.key.y == ny)) newMap[it.key] = it.value.copy() }
        for (i in 1..16) {
            if (miceList[i] == null) continue
            val x = miceList[i]!!.x
            val y = miceList[i]!!.y
            var mx: Int
            var my: Int
            val mouse = newMap[Coord(x, y)]!!.copy()
            while (true) {
                mx = x + dx[mouse.dir]
                my = y + dy[mouse.dir]
                if (mx < 0 || my < 0 || mx >= 4 || my >= 4 || (mx == nx && my == ny)) {
                    mouse.dir = (mouse.dir + 1) % 8
                    continue
                }
                break
            }
            if (!newMap.containsKey(Coord(mx, my))) {
                newMap.remove(Coord(x, y))
                newMap[Coord(mx, my)] = mouse
                miceList[i] = Coord(mx, my)
            } else {
                val prevMouseNum = newMap[Coord(mx, my)]!!.num
                val temp = newMap[Coord(mx, my)]!!.copy()
                newMap[Coord(mx, my)] = mouse
                newMap[Coord(x, y)] = temp
                miceList[i] = Coord(mx, my)
                miceList[prevMouseNum] = Coord(x, y)
            }
        }
        dfs(newAcc, newFox, newMap)
    }
    ans = max(ans, acc)
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val input = mutableMapOf<Coord, Mouse>()
    repeat(4) { i ->
        val st = StringTokenizer(readLine()!!)
        repeat(4) { j ->
            input[Coord(j, i)] = Mouse(st.nextToken().toInt(), st.nextToken().toInt() - 1)
        }
    }
    dfs(0, Fox(-1, -1, 5), input)
    print(ans)
}
