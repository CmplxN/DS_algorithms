import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main()=with(BufferedReader(InputStreamReader(System.`in`))) {
    val (N, S) = readLine()!!.split(' ').map { it.toInt() }
    val st = StringTokenizer(readLine()!!)
    val arr = IntArray(N) { st.nextToken()!!.toInt() }
    val mp = mutableMapOf<Int, Long>()
    var ans = 0L
    fun subSumF(sum:Int, now: Int, end :Int){
        if(now==end){
            if(mp.contains(sum)) mp[sum] = mp[sum]!! + 1L
            else mp[sum] = 1L
            return
        }
        subSumF(sum+arr[now],now+1,end)
        subSumF(sum,now+1,end)
    }
    fun subSumR(sum:Int, now: Int, end :Int){
        if(now==end){
            if(mp.contains(S-sum)) ans += mp[S-sum]!!
            return
        }
        subSumR(sum+arr[now],now+1,end)
        subSumR(sum,now+1,end)
    }
    subSumF(0,0,N/2)
    subSumR(0,N/2,N)
    print(if(S==0) ans - 1L else ans)
}

/*
fun main()=with(BufferedReader(InputStreamReader(System.`in`))) {
    val (N, S) = readLine()!!.split(" ").map{ it.toInt() }
    val st = StringTokenizer(readLine()!!)
    val A = List(N){st.nextToken()!!.toInt()}

    val L = A.subList(0, N/2)
    val R = A.subList(N/2, N)

    val tbL = (0 until (1 shl N/2))
        .map{ mask -> L.filterIndexed { i, _ -> mask and (1 shl i) != 0 }.sum() }
        .groupBy { it }
        .map { (x, y) -> x to y.size }
        .toMap()

    println((0 until (1 shl R.size))
        .map { mask -> tbL.getOrElse(S - R.filterIndexed { i, _ -> mask and (1 shl i) != 0 }.sum()) { 0 }.toLong() }
        .sum() - (if(S == 0) 1 else 0))
}
*/
