import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main()=with(BufferedReader(InputStreamReader(System.`in`))) {
    var ans = 0
    var st = StringTokenizer(readLine())
    val (N, M) = Pair(st.nextToken()!!.toInt(), st.nextToken()!!.toInt())
    val (G, R) = Pair(st.nextToken()!!.toInt(), st.nextToken()!!.toInt())
    val garden = Array(N) { IntArray(M) }
    val fertil = mutableListOf<Pair<Int, Int>>()
    val GRList = mutableListOf<Int>()
    val ActList = mutableListOf<Int>()
    val dx = intArrayOf(0, 0, -1, 1)
    val dy = intArrayOf(-1, 1, 0, 0)

    fun bfs() {
        var Try = 0
        var t = 0
        val gardenT=Array(N) { IntArray(M) }
        val Time=Array(N) { IntArray(M){-1} }
        for(i in 0 until N) for(j in 0 until M) gardenT[i][j]=garden[i][j]
        val q: Queue<Triple<Int, Int, Int>> = LinkedList()
        for (i in 0 until G + R) {
            q.add(Triple(fertil[ActList[i]].first, fertil[ActList[i]].second, GRList[i] + 2))
            gardenT[fertil[ActList[i]].second][fertil[ActList[i]].first] = GRList[i]+2
            Time[fertil[ActList[i]].second][fertil[ActList[i]].first] = 0
        }
        while (!q.isEmpty()) {
            var size = q.size
            t++
            while (size > 0) {
                val now = q.poll()
                if(gardenT[now.second][now.first]==-1){
                    size--
                    continue
                }
                for (i in 0 until 4) {
                    val nx = now.first + dx[i]
                    val ny = now.second + dy[i]
                    if (nx < 0 || ny < 0 || nx >= M || ny >= N || gardenT[ny][nx] <= 0) continue
                    if (now.third == gardenT[ny][nx]) continue
                    if (now.third == 2 && gardenT[ny][nx]==3 && Time[ny][nx]==t) {
                        gardenT[ny][nx]=-1
                        Try++
                        continue
                    }
                    if (now.third == 3 && gardenT[ny][nx]==2 && Time[ny][nx]==t) {
                        gardenT[ny][nx]=-1
                        Try++
                        continue
                    }
                    if(Time[ny][nx]<t&&Time[ny][nx]!=-1) continue
                    q.add(Triple(nx, ny, now.third))
                    gardenT[ny][nx] = now.third
                    Time[ny][nx]=t
                }
                size--
            }
        }
        ans = max(ans, Try)
    }

    fun GRSel(g: Int, r: Int) {
        if (g == 0 && r == 0) {
            bfs()
            return
        }
        if (g > 0) {
            GRList.add(0)
            GRSel(g - 1, r)
            GRList.removeAt(GRList.size - 1)
        }
        if (r > 0) {
            GRList.add(1)
            GRSel(g, r - 1)
            GRList.removeAt(GRList.size - 1)
        }
    }

    fun ActSel(d: Int) {
        if (ActList.size == G + R) {
            GRSel(G, R)
            return
        }
        for (i in d until fertil.size) {
            if (ActList.size < G + R) {
                ActList.add(i)
                ActSel(i + 1)
                ActList.removeAt(ActList.size - 1)
            }
        }
    }
    for (i in 0 until N) {
        st = StringTokenizer(readLine())
        for (j in 0 until M) {
            garden[i][j] = st.nextToken().toInt()
            if (garden[i][j] == 2) {
                fertil.add(Pair(j, i))
                garden[i][j] = 1
            }
        }
    }
    ActSel(0)
    print(ans)
}
