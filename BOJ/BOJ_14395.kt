import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val ops = charArrayOf('*', '+', '-', '/')
val visited = hashSetOf<Long>()

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (s, t) = readLine()!!.split(' ').map { it.toLong() }
    if (s == t) {
        print(0)
        return
    }
    val q: Queue<Pair<Long, String>> = LinkedList()
    var solved = false
    q.add(Pair(s, ""))
    visited.add(s)
    while (!q.isEmpty()) {
        val now = q.poll()
        if (now.first == t) {
            solved = true
            print(now.second)
            break
        }
        ops.forEach {
            val result = when (it) {
                '*' -> now.first * now.first
                '+' -> now.first + now.first
                '-' -> now.first - now.first
                else -> {
                    if (now.first == 0L) return@forEach
                    now.first / now.first
                }
            }
            if (visited.contains(result)) return@forEach
            visited.add(result)
            q.add(Pair(result, now.second + it))
        }
    }
    if (!solved) print(-1)
}
