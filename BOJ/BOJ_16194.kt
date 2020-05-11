import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main()=BufferedReader(InputStreamReader(System.`in`)).run {
    val N = readLine()!!.toInt()
    val st = StringTokenizer(readLine()!!)
    val input = Array(N + 1) { if (it != 0) st.nextToken()!!.toInt() else 0 }
    val dp = Array(N + 1) { 999999999 }
    dp[0] = 0
    dp[1] = input[1]
    for (i in 2..N) for (j in 1..i)
        dp[i] = min(dp[i - j] + input[j], dp[i])
    print(dp[N])
}
