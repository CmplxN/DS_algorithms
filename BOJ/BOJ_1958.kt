import kotlin.math.max
fun main() {
    val (s1, s2, s3) = Triple(readLine()!!, readLine()!!, readLine()!!)
    val dp = Array<Array<IntArray>>(s1.length + 1) { Array<IntArray>(s2.length + 1) { IntArray(s3.length + 1) { 0 } } }
    for (i in s1.withIndex()) {
        for (j in s2.withIndex()) {
            for (k in s3.withIndex()) {
                if (i.value == j.value && j.value == k.value)
                    dp[i.index + 1][j.index + 1][k.index + 1] = dp[i.index][j.index][k.index] + 1
                else
                    dp[i.index + 1][j.index + 1][k.index + 1] = max(
                        dp[i.index + 1][j.index + 1][k.index],
                        max(dp[i.index][j.index + 1][k.index + 1], dp[i.index + 1][j.index][k.index + 1])
                    )
            }
        }
    }
    print(dp[s1.length][s2.length][s3.length])
}
