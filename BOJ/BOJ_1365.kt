import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

typealias Index = Int

val lis = mutableListOf<Int>()

fun <T:Comparable<T>> lowerBound(elements: List<T>, l: Index, r: Index, value: T) : Index {
    var left = l
    var right = r
    var mid: Index
    while (left < right) {
        mid = (left + right) shr 1
        if (mid == r)
            return r
        if (elements[mid] < value)
            left = mid + 1
        else
            right = mid
    }
    return left
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine()!!.toInt()
    val st = StringTokenizer(readLine()!!)
    repeat(n) {
        val input = st.nextToken()!!.toInt()
        if (lis.size == 0 || input > lis.last())
            lis.add(input)
        val idx = lowerBound(lis, 0, lis.size - 1, input)
        lis[idx] = input
    }
    print(n - lis.size)
}
