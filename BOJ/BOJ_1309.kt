import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 9901

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val N = readLine().toInt()
    val dp = Array(N) { Array(3) { 0 } }
    dp[0][0] = 1
    dp[0][1] = 1
    dp[0][2] = 1
    for (i in 1 until N) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD
    }
    print(dp[N - 1].sum() % MOD)
}
