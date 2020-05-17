import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() = BufferedReader(InputStreamReader(System.`in`)).run {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val st = StringTokenizer(readLine()!!)
        val arr = Array(n) { 0 }
        var ans = -2147483648
        repeat(n){
            if(it==0) arr[it] = st.nextToken().toInt()
            else arr[it] = max(0,arr[it-1]) + st.nextToken().toInt()
            ans = max(ans,arr[it])
        }
        println(ans)
    }
}
