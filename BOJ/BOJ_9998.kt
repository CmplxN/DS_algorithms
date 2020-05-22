import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.abs
import kotlin.math.min

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val N = readLine()!!.toInt()
    var st = StringTokenizer(readLine()!!)
    val l1 = List(N) { st.nextToken()!!.toLong() }
    st = StringTokenizer(readLine()!!)
    val l2 = List(N) { st.nextToken()!!.toLong() }
    fun countBlocks(start: Long): Long {
        var (l, r) = Pair(N / 2 - 1, N / 2 + 1)
        var next = start
        var rtn = abs(l1[N / 2] - next) + abs(l2[N / 2] - next)
        while (l >= 0 && r < N) {
            next++
            rtn += abs(l1[l] - next) + abs(l1[r] - next)
            rtn += abs(l2[l] - next) + abs(l2[r] - next)
            l--
            r++
        }
        return rtn
    }

    var left = 0L
    var right = 1000000000000L - N / 2
    var ans = 1000000000000000000L
    while (left <= right) {
        val mid = (left + right) / 2L
        val leftCount = countBlocks(left)
        val rightCount = countBlocks(right)
        ans = min(ans, min(leftCount, rightCount))
        if (leftCount < rightCount)
            right = mid - 1
        else
            left = mid + 1
    }
    ans = min(ans, min(countBlocks(left), countBlocks(right)))
    print(ans)
}
