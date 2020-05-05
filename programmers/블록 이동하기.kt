    import java.util.*

    val dx = intArrayOf(1,-1,0,0)
    val dy = intArrayOf(0,0,1,-1)
    val dcnx = arrayOf(intArrayOf(1,1,0,0),intArrayOf(1,-1,0,0))
    val dcny = arrayOf(intArrayOf(-1,1,0,0),intArrayOf(1,1,0,0))
    val dcsx = arrayOf(intArrayOf(0,0,-1,-1),intArrayOf(0,0,1,-1))
    val dcsy = arrayOf(intArrayOf(0,0,-1,1),intArrayOf(0,0,-1,-1))
    val checkerX = arrayOf(intArrayOf(0,0,1,1),intArrayOf(1,-1,1,-1))
    val checkerY = arrayOf(intArrayOf(-1,1,-1,1),intArrayOf(0,0,1,1))

    data class Robot(val northWest: Pair<Int,Int>, val southEast: Pair<Int,Int>, var dir: Int = 0)

    class Solution {
        private fun rotate(board: Array<IntArray>, robot: Robot): List<Robot> {
            val N = board.size
            val rtn = mutableListOf<Robot>()
            for (i in 0 until 4) {
                val nNW = Pair(robot.northWest.first + dcnx[robot.dir][i], robot.northWest.second + dcny[robot.dir][i])
                val nSE = Pair(robot.southEast.first + dcsx[robot.dir][i], robot.southEast.second + dcsy[robot.dir][i])
                if (nNW.second < 0 || nNW.first < 0 || nNW.first >= N || nNW.second >= N) continue
                if (nSE.second < 0 || nSE.first < 0 || nSE.first >= N || nSE.second >= N) continue
                if (board[robot.northWest.second + checkerY[robot.dir][i]][robot.northWest.first + checkerX[robot.dir][i]] == 1) continue
                if (board[nNW.second][nNW.first] == 1 || board[nSE.second][nSE.first] == 1) continue
                if (nNW.first < nSE.first || nNW.second < nSE.second) rtn.add(Robot(nNW, nSE, (robot.dir + 1) % 2))
                else rtn.add(Robot(nSE, nNW, (robot.dir + 1) % 2))
            }
            return rtn
        }
        fun solution(board: Array<IntArray>): Int {
            val N = board.size
            val visited = hashSetOf<Robot>()
            val q: Queue<Robot> = ArrayDeque()
            val firstInput = Robot(Pair(0, 0), Pair(1, 0))
            visited.add(firstInput)
            q.add(firstInput)
            var ans = 0
            while (true) {
                ans++
                repeat(q.size) {
                    val now = q.poll()
                    if (now.southEast.first == N - 1 && now.southEast.second == N - 1)
                        return ans - 1
                    for (i in 0 until 4) {
                        val newNorthWest = Pair(now.northWest.first + dx[i], now.northWest.second + dy[i])
                        val newSouthEast = Pair(now.southEast.first + dx[i], now.southEast.second + dy[i])
                        if (newNorthWest.second < 0 || newNorthWest.first < 0 || newSouthEast.first >= N || newSouthEast.second >= N) continue
                        if (board[newSouthEast.second][newSouthEast.first] == 1 || board[newNorthWest.second][newNorthWest.first] == 1) continue
                        val nextCandidate = Robot(newNorthWest, newSouthEast, now.dir)
                        if (visited.contains(nextCandidate)) continue
                        visited.add(nextCandidate)
                        q.add(nextCandidate)
                    }
                    rotate(board, now).forEach {
                        if (!visited.contains(it)) {
                            visited.add(it)
                            q.add(it)
                        }
                    }
                }
            }
        }
    }
