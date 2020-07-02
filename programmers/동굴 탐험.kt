import java.util.*

class Solution {
    fun solution(n: Int, path: Array<IntArray>, order: Array<IntArray>): Boolean {
        val edges = Array(n) { mutableListOf<Int>() }
        val visited = Array(n) { false }
        val opener = mutableMapOf<Int, Int>()
        val blocker = mutableSetOf<Int>()
        val waiting = mutableSetOf<Int>()
        val q: Queue<Int> = LinkedList()
        path.forEach {
            edges[it[0]].add(it[1])
            edges[it[1]].add(it[0])
        }
        order.forEach {
            if (it[1] == 0)
                return false
            opener[it[0]] = it[1]
            blocker.add(it[1])
        }
        q.add(0)
        visited[0] = true
        if (opener.containsKey(0))
            blocker.remove(opener[0])
        while (q.isNotEmpty()) {
            val now = q.poll()
            edges[now].forEach {
                if (visited[it])
                    return@forEach
                if (blocker.contains(it)) {
                    waiting.add(it)
                    return@forEach
                }
                q.add(it)
                visited[it] = true
                if (opener.containsKey(it)) {
                    blocker.remove(opener[it])
                    if (waiting.contains(opener[it])) {
                        q.add(opener[it])
                        visited[opener[it]!!] = true
                        waiting.remove(opener[it])
                    }
                }
            }
        }
        return blocker.isEmpty()
    }
}
