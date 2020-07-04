class Solution {
    val dx = arrayOf(intArrayOf(1, 2, 1, 2, 0, 0), intArrayOf(0, 0, 1, 1, 1, 0))
    val dy = arrayOf(intArrayOf(0, 0, 1, 1, 1, 0), intArrayOf(1, 2, 1, 2, 0, 0))
    fun solve(board: Array<IntArray>, x: Int, y: Int): Boolean {
        val N = board.size
        (0..1).forEach {
            var zero = 0
            var other = -1
            for (i in 0 until 6) {
                val nx = x + dx[it][i]
                val ny = y + dy[it][i]
                if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                    return@forEach
                if (board[ny][nx] == 0) {
                    var Ny = ny
                    while (Ny >= 0 && board[Ny][nx] == 0)
                        Ny--
                    if (Ny != -1)
                        return@forEach
                    zero++
                } else {
                    if (other == -1)
                        other = board[ny][nx]
                    else if(other != board[ny][nx])
                        return@forEach
                }
            }
            if (zero != 2)
                return@forEach
            for (i in 0 until 6) {
                val nx = x + dx[it][i]
                val ny = y + dy[it][i]
                board[ny][nx] = 0
            }
            return true
        }
        return false
    }

    fun solution(board: Array<IntArray>): Int {
        var answer = 0
        val N = board.size
        while (true) {
            var cnt = 0
            (0 until N).forEach { i ->
                (0 until N).forEach { j ->
                    if (solve(board, j, i))
                        cnt++
                }
            }
            if (cnt == 0)
                break
            answer += cnt
        }
        return answer
    }
}
