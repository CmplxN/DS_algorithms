import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val N = readLine().toInt()
    val st = StringTokenizer(readLine())
    val input = Array(N) { st.nextToken().toInt() }.sorted()
    var max = 0
    input.forEach {
        if (max + 1 < it)
            return@forEach
        max += it
    }
    print(max + 1)
}
