import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine()!!.toInt()
    val edge = Array(n) { mutableListOf<Int>() }
    repeat(n - 1) {
        val st = StringTokenizer(readLine()!!)
        val input = Pair(st.nextToken()!!.toInt(), st.nextToken()!!.toInt())
        edge[input.first - 1].add(input.second - 1)
        edge[input.second - 1].add(input.first - 1)
    }
    val dp = Array(n) { Array(18) { 0 } }
    val visited = Array(n) { false }
    val depth = Array(n) { 0 }

    fun depthMarker(a: Int, d: Int) {
        visited[a] = true
        depth[a] = d
        for (i in edge[a]) {
            if (!visited[i]) {
                dp[i][0] = a
                depthMarker(i, d + 1)
            }
        }
    }
    depthMarker(0, 0)
    for(j in 1 .. 17) for(i in 0 until n) dp[i][j] = dp[dp[i][j-1]][j-1]

    fun LCA(a: Int, b: Int): Int {
        var deeper = if (depth[a] > depth[b]) a else b
        var shallower = if (depth[a] > depth[b]) b else a
        if (depth[deeper] != depth[shallower]) {
            for (i in 17 downTo 0)
                if (depth[dp[deeper][i]] > depth[shallower])
                    deeper = dp[deeper][i]
            deeper = dp[deeper][0]
        }
        if (deeper == shallower) return shallower
        for (i in 17 downTo 0)
            if (dp[deeper][i] != dp[shallower][i]) {
                deeper = dp[deeper][i]
                shallower = dp[shallower][i]
            }
        return dp[shallower][0]
    }
    var ans = 0L
    for(i in 0 until n){
        for(j in (i+i+1) until n step (i+1)){            
            val lca = LCA(i,j)            
            ans+=depth[i] + depth[j] - depth[lca] - depth[lca] + 1
        }
    }
    print(ans)
}
