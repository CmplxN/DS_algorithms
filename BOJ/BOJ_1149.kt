import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main()=with(BufferedReader(InputStreamReader(System.`in`))){
    val n = readLine()!!.toInt()
    val dp=Array(n){IntArray(3){0} }
    var st = StringTokenizer(readLine())
    dp[0][0]=st.nextToken().toInt()
    dp[0][1]=st.nextToken().toInt()
    dp[0][2]=st.nextToken().toInt()
    repeat(n-1){
        st = StringTokenizer(readLine())
        dp[it+1][0]=min(dp[it][1],dp[it][2])+st.nextToken().toInt()
        dp[it+1][1]=min(dp[it][0],dp[it][2])+st.nextToken().toInt()
        dp[it+1][2]=min(dp[it][1],dp[it][0])+st.nextToken().toInt()
    }
    print(min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2])))
}
