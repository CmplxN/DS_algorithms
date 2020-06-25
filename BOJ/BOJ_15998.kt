import java.io.BufferedReader
import java.io.InputStreamReader
import java.math.BigDecimal
import java.util.*
import kotlin.math.max

fun gcd(a: Long, b: Long): Long {
    if (b == 0L)
        return a
    return gcd(b, a % b)
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    var balance = 0L
    var candidate = 0L
    var atLeast = 0L
    var cnt = 0L
    repeat(readLine().toInt()) {
        val (a, b) = readLine().split(' ').map { it.toLong() }
        if (!(a > 0L || balance + a >= 0L)) {
            cnt++
            val now = gcd(-a - balance + b, candidate)
            atLeast = max(atLeast, b)
            if (candidate != 0L && now < atLeast) {
                print(-1)
                return
            }
            candidate = now
        } else if (balance + a != b) {
            print(-1)
            return
        }
        balance = b
    }
    print(if (cnt > 1L && candidate == 1L) -1 else if(candidate == 0L) 1 else candidate)
}
