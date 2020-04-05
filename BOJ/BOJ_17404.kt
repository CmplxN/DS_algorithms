import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main()=with(BufferedReader(InputStreamReader(System.`in`))){
    val n = readLine()!!.toInt()
    val dp=Array(n){Array(3){IntArray(3){0}}}
    var st = StringTokenizer(readLine())
    dp[0][0][0]=st.nextToken().toInt()
    dp[0][0][1]=999999999
    dp[0][0][2]=999999999
    dp[0][1][1]=st.nextToken().toInt()
    dp[0][1][0]=999999999
    dp[0][1][2]=999999999
    dp[0][2][2]=st.nextToken().toInt()
    dp[0][2][0]=999999999
    dp[0][2][1]=999999999
    repeat(n-1){
        st = StringTokenizer(readLine())
        val temp = Triple(st.nextToken().toInt(),st.nextToken().toInt(),st.nextToken().toInt())
        dp[it+1][0][0]=min(dp[it][0][1],dp[it][0][2])+temp.first
        dp[it+1][0][1]=min(dp[it][0][0],dp[it][0][2])+temp.second
        dp[it+1][0][2]=min(dp[it][0][1],dp[it][0][0])+temp.third
        dp[it+1][1][0]=min(dp[it][1][1],dp[it][1][2])+temp.first
        dp[it+1][1][1]=min(dp[it][1][0],dp[it][1][2])+temp.second
        dp[it+1][1][2]=min(dp[it][1][1],dp[it][1][0])+temp.third
        dp[it+1][2][0]=min(dp[it][2][1],dp[it][2][2])+temp.first
        dp[it+1][2][1]=min(dp[it][2][0],dp[it][2][2])+temp.second
        dp[it+1][2][2]=min(dp[it][2][1],dp[it][2][0])+temp.third
    }
    print(min(min(dp[n-1][0][1],dp[n-1][0][2]),min(min(dp[n-1][1][0],dp[n-1][1][2]),min(dp[n-1][2][0],dp[n-1][2][1]))))
}
