import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun myPow(a: Int): Int {
    var rtn = 1
    var temp = a
    while (temp > 0) {
        rtn *= 2
        temp--
    }
    return rtn
}

fun myLog(a: Int): Int {
    var temp = a - 1
    var rtn = 0
    while (temp > 0) {
        temp /= 2
        rtn++
    }
    return rtn
}

fun main()= with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = readLine()!!.toInt()
    var st = StringTokenizer(readLine()!!)
    val arr = IntArray(4 * n) { 0 }
    val start = myPow(myLog(n))
    for (i in start until start + n) arr[i] = if (st.nextToken().toInt() % 2 == 0) 0 else 1
    for (i in start - 1 downTo 1) arr[i] = arr[i * 2] + arr[i * 2 + 1]
    val m = readLine()!!.toInt()
    fun query(l: Int, r: Int): Int {
        var rtn = 0
        var left = l
        var right = r
        while (left <= right) {
            if (left % 2 == 1) rtn += arr[left]
            if (right % 2 == 0) rtn += arr[right]
            left = (left + 1) / 2
            right = (right - 1) / 2
        }
        return rtn
    }
    repeat(m) {
        st = StringTokenizer(readLine()!!)
        val (cmd, l, r) = Triple(st.nextToken().toInt(), st.nextToken().toInt(), st.nextToken().toInt())
        when (cmd) {
            1 -> Pair(start + l - 1, r % 2 - arr[start + l - 1]).run{
                var i = first
                while (i > 0) {
                    arr[i] += second
                    i /= 2
                }
            }
            else -> {
                val result = Pair(start+l-1,start+r-1).run {
                    var rtn = 0
                    var left = first
                    var right = second
                    while (left <= right) {
                        if (left % 2 == 1) rtn += arr[left]
                        if (right % 2 == 0) rtn += arr[right]
                        left = (left + 1) / 2
                        right = (right - 1) / 2
                    }
                    rtn
                }
                bw.write(if (cmd == 3) result.toString() else (r - l + 1 - result).toString())
                bw.write("\n")
            }
        }
    }
    bw.flush()
    bw.close()
}
