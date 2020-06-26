import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val dx = intArrayOf(0, 0, -1, 1)
val dy = intArrayOf(-1, 1, 0, 0)

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (N, M) = readLine().split(' ').map { it.toInt() }
    val height = Array(N) {
        val st = StringTokenizer(readLine())
        IntArray(M) { st.nextToken().toInt() }
    }
    val dp = Array(N) { IntArray(M) { -1 } }

    fun dfs(x: Int, y: Int): Int {
        if (x == M - 1 && y == N - 1)
            return 1
        if (dp[y][x] != -1)
            return dp[y][x]
        var rtn = 0
        for (i in 0 until 4) {
            val nx = dx[i] + x
            val ny = dy[i] + y
            if (nx < 0 || ny < 0 || nx >= M || ny >= N || height[ny][nx] >= height[y][x])
                continue
            rtn += dfs(nx, ny)
        }
        dp[y][x] = rtn
        return rtn
    }

    print(dfs(0, 0))
}
