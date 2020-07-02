import java.util.*
import kotlin.math.abs

data class Coord(val x: Int, val y: Int)

val dx = intArrayOf(1, 0, 0, -1)
val dy = intArrayOf(0, 1, -1, 0)

fun bfs(visited: Array<BooleanArray>, group: Array<IntArray>, land: Array<IntArray>, coord: Coord, height: Int, groupNumber: Int) {
    val size = visited.size
    val q: Queue<Coord> = LinkedList()
    q.add(coord)
    visited[coord.y][coord.x] = true
    group[coord.y][coord.x] = groupNumber
    while (q.isNotEmpty()) {
        val now = q.poll()
        for (i in 0 until 4) {
            val nx = dx[i] + now.x
            val ny = dy[i] + now.y
            if (nx < 0 || ny < 0 || nx >= size || ny >= size || visited[ny][nx] || abs(land[now.y][now.x] - land[ny][nx]) > height)
                continue
            q.add(Coord(nx, ny))
            visited[ny][nx] = true
            group[ny][nx] = groupNumber
        }
    }
}

tailrec fun find(node: Int, parent: IntArray): Int {
    if (parent[node] == node)
        return node
    return find(parent[node], parent)
}

fun doUnion(nodeA: Int, nodeB: Int, parent: IntArray) {
    val A = find(nodeA, parent)
    val B = find(nodeB, parent)
    if (A == B)
        return
    parent[A] = B
}

class Solution {
    fun solution(land: Array<IntArray>, height: Int): Int {
        val N = land.size
        val visited = Array(N) { BooleanArray(N) { false } }
        val group = Array(N) { IntArray(N) { -1 } }
        val temp = hashMapOf<Pair<Int, Int>, Int>()
        var groupNumber = 1
        for (i in 0 until N) for (j in 0 until N) if (!visited[i][j])
            bfs(visited, group, land, Coord(j, i), height, groupNumber++)
        for (i in 0 until N) for (j in 0 until N) for (k in 0 until 2) {
            val nx = dx[k] + j
            val ny = dy[k] + i
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || group[i][j] == group[ny][nx])
                continue
            val diff = abs(land[i][j] - land[ny][nx])
            val first = if (group[i][j] > group[ny][nx]) group[i][j] else group[ny][nx]
            val second = if (group[i][j] > group[ny][nx]) group[ny][nx] else group[i][j]
            temp.computeIfAbsent(Pair(first, second)) { diff }
            if (temp[Pair(first, second)]!! > diff)
                temp[Pair(first, second)] = diff
        }

        val edges = temp.map { Triple(it.key.first - 1, it.key.second - 1, it.value) }.sortedBy { it.third }
        val parent = IntArray(3) { it }
        var answer = 0
        edges.forEach {
            if (find(it.first, parent) == find(it.second, parent))
                return@forEach
            doUnion(it.first, it.second, parent)
            answer += it.third
        }
        return answer
    }
}
