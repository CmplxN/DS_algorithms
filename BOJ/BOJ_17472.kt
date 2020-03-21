fun main() {
    data class Info(val f: Int, val t: Int, val d: Int)

    var ans = 0
    var cnt = 0
    var ino = 2
    val dx = intArrayOf(1, -1, 0, 0)
    val dy = intArrayOf(0, 0, -1, 1)
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }
    val map = Array<IntArray>(n) { readLine()!!.split(' ').map { it.toInt() }.toIntArray() }
    val parent = mutableListOf<Int>()
    val height = mutableListOf<Int>()
    val list = mutableListOf<Info>()
    fun dfs(x: Int, y: Int, no: Int) {
        map[y][x] = no
        for (i in 0 until 4) {
            val nx = x + dx[i]
            val ny = y + dy[i]
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || map[ny][nx] != 1) continue
            dfs(nx, ny, no)
        }
    }

    fun find(a: Int): Int {
        if (parent[a] == a) return a
        var A = a
        while (parent[A] != A) A = parent[A]
        return A
    }

    fun union(a: Int, b: Int) {
        val A = find(a)
        val B = find(b)
        if (A == B) return
        else if (height[A] < height[B]) parent[A] = B
        else if (height[A] > height[B]) parent[B] = A
        else {
            parent[B] = A
            height[A]++
        }
    }
    for (i in 0 until n) for (j in 0 until m) if (map[i][j] == 1) {
        dfs(j, i, ino++)
        height.add(0)
        parent.add(ino - 3)
    }
    for (i in 0 until n) for (j in 0 until m) {
        if (map[i][j] < 2) continue
        for (k in 0 until 4) {
            var nx = j + dx[k]
            var ny = i + dy[k]
            var dist = 0
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue
            val from = map[i][j]
            while (nx >= 0 && ny >= 0 && nx < m && ny < n && map[ny][nx] == 0) {
                dist++
                nx += dx[k]
                ny += dy[k]
            }
            if (dist >= 2 && nx >= 0 && ny >= 0 && nx < m && ny < n) list.add(Info(from - 2, map[ny][nx] - 2, dist))
        }
    }
    list.sortBy { it.d }
    list.forEach {
        if (find(it.f) == find(it.t)) return@forEach
        cnt++
        union(it.f, it.t)
        ans += it.d
    }
    print(if (cnt + 3 == ino) ans else -1)
}
