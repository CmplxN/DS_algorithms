class Solution {
    fun rotate(key: Array<IntArray>): Array<IntArray> =
            Array(key[0].size) { It -> IntArray(key.size) { key[key.size - it - 1][It] } }

    fun check(key: Array<IntArray>, lock: Array<IntArray>, x: Int, y: Int, tar: Int): Boolean {
        var cnt = 0
        for (i in key.indices) {
            for (j in key[0].indices) {
                if (lock[i + y][j + x] == 1 && key[i][j] == 1) return false
                if (lock[i + y][j + x] == 0 && key[i][j] == 1) cnt++
            }
        }
        return tar == cnt
    }

    fun solution(key: Array<IntArray>, lock: Array<IntArray>): Boolean {
        var temp = key
        val exLock = Array(lock.size + 2 * (key.size - 1))
        { IntArray(lock[0].size + 2 * (key[0].size - 1)) { -1 } }
        for (i in key.size - 1 until key.size - 1 + lock.size) {
            for (j in key[0].size - 1 until key[0].size - 1 + lock[0].size) {
                exLock[i][j] = lock[i - (key.size - 1)][j - (key[0].size - 1)]
            }
        }
        val tar = lock.map { it.count { i -> i == 0 } }.sum()
        repeat(4) {
            temp = rotate(temp)
            for (i in 0 until key.size - 1 + lock.size)
                for (j in 0 until key[0].size - 1 + lock[0].size)
                    if (check(temp, exLock, j, i, tar)) return true
        }
        return false
    }
}
