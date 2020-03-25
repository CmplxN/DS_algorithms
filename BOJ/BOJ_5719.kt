import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.Comparator
data class Data(val first : Int, var second : Int)
fun main()=with(BufferedReader(InputStreamReader(System.`in`))) {
    val ans = mutableListOf<Int>()
    val MAX = 99999999
    val fcmp: Comparator<Data> = compareBy { it.second }
    while (true) {
        var st = StringTokenizer(readLine())
        val (n, m) = Pair(st.nextToken().toInt(), st.nextToken().toInt())
        if (n == m && n == 0) break
        var table = IntArray(n) { MAX }
        val info = Array<MutableList<Data>>(n) { mutableListOf() }
        val s_from = Array<MutableList<Int>>(n) { mutableListOf() }
        var pq: PriorityQueue<Data> = PriorityQueue(fcmp)
        st = StringTokenizer(readLine())
        val (s, d) = Pair(st.nextToken().toInt(), st.nextToken().toInt())
        repeat(m) {
            st = StringTokenizer(readLine())
            info[st.nextToken().toInt()].add(Data(st.nextToken().toInt(), st.nextToken().toInt()))
        }
        pq.add(Data(s, 0))
        while (!pq.isEmpty()) {
            val now = pq.poll()!!
            if (table[now.first] < now.second) continue
            for (next in info[now.first]) {
                if (now.second + next.second < table[next.first]) {
                    pq.add(Data(next.first, now.second + next.second))
                    table[next.first] = next.second + now.second
                    s_from[next.first].clear()
                    s_from[next.first].add(now.first)
                    continue
                }
                if (now.second + next.second == table[next.first]) s_from[next.first].add(now.first)
            }
        }
        fun delete(node: Int) {
            if (node == s) return
            for (from in s_from[node]) for (dels in info[from]) if (dels.first == node) {
                dels.second = -MAX
                delete(from)
            }
        }
        delete(d)
        table = IntArray(n) { MAX }
        pq = PriorityQueue(fcmp)
        pq.add(Data(s, 0))
        while (!pq.isEmpty()) {
            val now = pq.poll()!!
            if (table[now.first] != MAX) continue
            table[now.first] = now.second
            for (next in info[now.first]) {
                if (next.second == -MAX) continue
                pq.add(Data(next.first, now.second + next.second))
            }
        }
        ans.add(if (table[d] == MAX) -1 else table[d])
    }
    print(ans.joinToString("\n"))
}
