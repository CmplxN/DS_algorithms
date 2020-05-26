import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val dx = intArrayOf(0,0,-1,1)
val dy = intArrayOf(1,-1,0,0)

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val st = StringTokenizer(readLine()!!)
    val n = st.nextToken()!!.toInt()
    val field = Array(2*n+1){Array(2*n+1){false} }
    val prob = Array(4){st.nextToken().toInt()/100.0}
    fun dfs(x:Int, y:Int, nth:Int): Double{
        var rtn = 0.0
        if(nth == n) return 1.0
        field[y][x]=true
        for(i in 0 until 4){
            val nx = x + dx[i]
            val ny = y + dy[i]
            if(field[ny][nx]) continue
            rtn += dfs(nx,ny,nth+1) * prob[i]
        }
        field[y][x]=false
        return rtn
    }
    print(dfs(n,n,0))
}
