import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.abs
import kotlin.math.max

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().toInt()
    val st = StringTokenizer(readLine())
    val arr = Array(1 shl (n + 1)) { if (it < 2) 0 else st.nextToken().toInt() }
    var ans = arr.sum()
    for (i in ((1 shl (n + 1)) - 1) downTo 3 step 2) {
        arr[i / 2] += max(arr[i], arr[i - 1])
        ans += abs(arr[i] - arr[i - 1])
    }
    print(ans)
}
