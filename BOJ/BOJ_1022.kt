import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.abs
import kotlin.math.max

val lookUp = Array(5001) { 4 * it * it - 4 * it + 2 }

fun converter(x: Int, y: Int):String {
    if (x == 0 && y == 0) return "1"
    val nth = max(abs(y), abs(x))
    val start = Pair(nth, nth - 1)
    return (when {
        x == nth && y <= start.second -> start.second - y
        y == -nth -> 2 * nth - 1 + start.first - x
        x == -nth -> 4 * nth - 1 + y - (-nth)
        else -> 6 * nth - 1 + x - (-nth)
    } + lookUp[nth]).toString()
}

fun lengthener(str: String, len: Int):String {
    var rtn = str
    for (i in 0 until len - str.length) rtn = rtn.prependIndent(" ")
    return rtn
}

fun main()=with(BufferedReader(InputStreamReader(System.`in`))) {
    val st = StringTokenizer(readLine()!!)
    val start = Pair(st.nextToken().toInt(), st.nextToken().toInt())
    val end = Pair(st.nextToken().toInt(), st.nextToken().toInt())
    val answer = Array(end.first - start.first + 1) {
        Array(end.second - start.second + 1) { "" }
    }
    for (i in start.first..end.first) for (j in start.second..end.second)
        answer[i - start.first][j - start.second] = converter(j, i)
    var maxLen = 0
    answer.forEach {
        it.forEach { str ->
            maxLen = max(maxLen, str.length)
        }
    }
    for (i in start.first..end.first) {
        for (j in start.second..end.second)
            print(lengthener(answer[i - start.first][j - start.second], maxLen) + " ")
        println()
    }
}
