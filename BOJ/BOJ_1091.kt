import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun Array<Int>.isEqual(list: Array<Int>): Boolean {
    if (list.size != size)
        return false
    forEachIndexed { index, t ->
        if (list[index] != t % 3)
            return false
    }
    return true
}

fun Array<Int>.shuffle(list: Array<Int>): Array<Int> {
    val rtn = Array(size) { 0 }
    list.forEachIndexed { index, i ->
        rtn[index] = this[list[index]]
    }
    return rtn
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val N = readLine().toInt()
    var st = StringTokenizer(readLine())
    val P = Array(N) { st.nextToken().toInt() }
    st = StringTokenizer(readLine())
    val S = Array(N) { st.nextToken().toInt() }
    var cards = Array(N) { it }
    var ans = 0
    while (!cards.isEqual(P)) {
        cards = cards.shuffle(S)
        ans++
        if (ans > 122222) {
            print(-1)
            return
        }
    }
    print(ans)
}
