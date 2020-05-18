import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() = BufferedReader(InputStreamReader(System.`in`)).run {
    val (n, k) = readLine()!!.split(' ').map { it.toInt() }
    val input = Array(n) { readLine()!!.toInt() }
    val dp = Array(k+1) { 1111111 }
    dp[0] = 0
    for (i in 0 until n)
        for (j in input[i] .. k)
            dp[j] = min(dp[j], dp[j - input[i]] + 1)
    print(if (dp[k] == 1111111) -1 else dp[k])
}
