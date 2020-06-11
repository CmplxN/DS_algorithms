import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (N, M) = readLine().split(' ').map { it.toInt() }
    val visited = Array(N + 1) { Array(M + 1) { 0 } }
    val field = Array(N) {
        val st = StringTokenizer(readLine())
        Array(M) {
            st.nextToken().toInt()
        }
    }
    for (i in 1..N) for (j in 1..M)
        visited[i][j] = max(visited[i - 1][j], visited[i][j - 1]) + field[i - 1][j - 1]
    print(visited[N][M])
}
