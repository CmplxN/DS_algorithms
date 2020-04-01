import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main()=with(BufferedReader(InputStreamReader(System.`in`))) {
    var st = StringTokenizer(readLine())
    val (N, M, K) = Triple(st.nextToken().toInt(), st.nextToken().toInt(), st.nextToken().toInt())
    val plate = Array(N) { IntArray(M) { 0 } }
    repeat(K) {
        st = StringTokenizer(readLine())
        var (R, C) = Pair(st.nextToken().toInt(), st.nextToken().toInt())
        val outer = Array(10) { IntArray(10) { 0 } }
        fun test(x: Int, y: Int): Boolean {
            for (i in 0 until R) for (j in 0 until C) if (outer[i][j] == 1 && plate[i + y][j + x] == 1) return false
            for (i in 0 until R) for (j in 0 until C) if (outer[i][j] == 1) plate[i + y][j + x] = 1
            return true
        }
        for (i in 0 until R) {
            st = StringTokenizer(readLine())
            for (j in 0 until C) outer[i][j] = st.nextToken().toInt()
        }
        var cnt = 0
        h@ while (cnt++ < 4) {
            for (i in 0..N - R) for (j in 0..M - C) if (test(j, i)) break@h
            val temp = Array(10) { IntArray(10) }
            for (i in 0 until R) for (j in 0 until C) temp[i][j] = outer[i][j]
            for (i in 0 until C) for (j in 0 until R) outer[i][j] = temp[R - 1 - j][i]
            R = C.also { C = R }
        }
    }
    var ans = 0
    for (i in 0 until N) for (j in 0 until M) if (plate[i][j] == 1) ans++
    print(ans)
}
