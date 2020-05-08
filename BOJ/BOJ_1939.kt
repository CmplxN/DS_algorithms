import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (N, M) = readLine()!!.split(' ').map { it.toInt() }
    val map: MutableMap<Int, MutableList<Pair<Int, Long>>> = mutableMapOf()
    repeat(M) {
        val st = StringTokenizer(readLine()!!)
        val info = Triple(st.nextToken().toInt() - 1, st.nextToken().toInt() - 1, st.nextToken().toLong())
        map.computeIfAbsent(info.first) { mutableListOf() }
        map[info.first]!!.add(Pair(info.second, info.third))
        map.computeIfAbsent(info.second) { mutableListOf() }
        map[info.second]!!.add(Pair(info.first, info.third))
    }
    val (from, to) = readLine()!!.split(' ').map { it.toInt() - 1 }
    fun bfs(weight: Long): Boolean {
        val q: Queue<Int> = ArrayDeque()
        val visited = BooleanArray(N) { false }
        q.add(from)
        visited[from] = true
        while (!q.isEmpty()) {
            val now = q.poll()!!
            if (now == to) return true
            map[now]!!.forEach {
                if (weight <= it.second && !visited[it.first]) {
                    q.add(it.first)
                    visited[it.first] = true
                }
            }
        }
        return false
    }

    var left = 1L
    var right = 1000000000L
    while (left <= right) {
        val mid = (left + right) / 2
        if (bfs(mid)) left = mid + 1
        else right = mid - 1
    }
    print(left - 1)
}
