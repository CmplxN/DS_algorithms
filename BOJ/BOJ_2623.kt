import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main()=with(BufferedReader(InputStreamReader(System.`in`))) {
    val (N, M) = readLine()!!.split(' ').map { it.toInt() }
    val pres = IntArray(N) { 0 }
    val q: Queue<Int> = LinkedList()
    val ans = mutableListOf<Int>()
    val nexts = Array(N) { mutableListOf<Int>() }
    repeat(M) {
        val st = StringTokenizer(readLine()!!)
        val input = Array(st.nextToken()!!.toInt()) { st.nextToken()!!.toInt() - 1 }
        input.reduce { acc, i ->
            pres[i]++
            nexts[acc].add(i)
            i
        }
    }
    pres.forEachIndexed { index, i -> if (i == 0) {q.add(index)} }
    while (!q.isEmpty()) {
        val now = q.poll()!!
        ans.add(now+1)
        nexts[now].forEach {
            pres[it]--
            if (pres[it] == 0) {
                q.add(it)
            }
        }
    }
    print(if(ans.size==N) ans.joinToString("\n") else 0)
}
