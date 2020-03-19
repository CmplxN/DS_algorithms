import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

data class Coord(val x: Int, val y: Int)
val dx = intArrayOf(1, -1, 0, 0)
val dy = intArrayOf(0, 0, 1, -1)
fun main()=BufferedReader(InputStreamReader(System.`in`)).run {
    var st = StringTokenizer(readLine())
    val r=Integer.parseInt(st.nextToken())
    val c=Integer.parseInt(st.nextToken())
    val mp = mutableMapOf<Coord, Int>()
    val ice = Array<IntArray>(r) { IntArray(c){0} }
    for (i in 0 until r) {
        st= StringTokenizer(readLine())
        for (j in 0 until c) {
            ice[i][j]=Integer.parseInt(st.nextToken())
            if (ice[i][j] != 0) mp[Coord(j, i)] = ice[i][j]
        }
    }
    var ans = 0
    while (++ans > 0) {
        mp.forEach {
            for (i in 0 until 4) {
                val nx = it.key.x + dx[i]
                val ny = it.key.y + dy[i]
                if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue
                if (ice[ny][nx] == 0) mp[it.key] = it.value - 1
            }
        }
        val list = mutableListOf<Coord>()
        var tx = 0
        var ty = 0
        mp.forEach {
            if (it.value <= 0) {
                ice[it.key.y][it.key.x] = 0
                list.add(it.key)
            } else {
                tx = it.key.x
                ty = it.key.y
            }
        }
        list.forEach { mp.remove(it) }
        if (mp.isEmpty()) {
            print(0)
            break
        }
        val visited = Array<BooleanArray>(r) { BooleanArray(c) { false } }
        val q : Queue<Coord> = LinkedList()
        var cnt=0
        q.add(Coord(tx,ty))
        visited[ty][tx]=true
        while(!q.isEmpty()){
            cnt++
            val now = q.poll()
            for(i in 0 until 4){
                val nx = now.x + dx[i]
                val ny = now.y + dy[i]
                if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue
                if (ice[ny][nx] == 0 || visited[ny][nx]) continue
                visited[ny][nx]=true
                q.add(Coord(nx,ny))
            }
        }
        if (mp.size != cnt) {
            print(ans)
            break
        }
    }
}
