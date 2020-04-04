import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() = BufferedReader(InputStreamReader(System.`in`)).run{
    var st = StringTokenizer(readLine())
    val n = st.nextToken().toInt()
    val dp = IntArray(1.shl(n)){-1}
    val costs = Array(n){st = StringTokenizer(readLine());IntArray(n){st.nextToken().toInt()} }
    var initStatus = 0
    var initOnNo=0
    st = StringTokenizer(readLine())
    val input = st.nextToken()!!
    for(c in input.reversed()){
        initStatus=initStatus.shl(1)
        if(c=='Y'){
            initStatus++
            initOnNo++
        }
    }
    val target = readLine().toInt()
    if(target<=initOnNo){
        print(0)
        return
    }
    if(target!=0&&initOnNo==0){
        print(-1)
        return
    }
    fun dfs(onNo:Int, status: Int): Int{
        if(onNo>=target) return 0
        if(dp[status]!=-1) return dp[status]
        dp[status]=2147483647
        for(i in 0 until n){
            if(status.and(1.shl(i))!=0){
                for(j in 0 until n){
                    if(i==j) continue
                    if(status.and(1.shl(j))==0)
                        dp[status]=min(dp[status],costs[i][j]+dfs(onNo+1,status.or(1.shl(j))))
                }
            }
        }
        return dp[status]
    }
    print(dfs(initOnNo,initStatus))
}
