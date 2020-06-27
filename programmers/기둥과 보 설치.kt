data class Coord(val x: Int, val y: Int)
class Solution {
    fun solution(n: Int, build_frame: Array<IntArray>): Array<IntArray> {
        val gd = hashSetOf<Coord>()
        val bo = hashSetOf<Coord>()
        build_frame.forEach {
            val x = it[0]
            val y = it[1]
            if (it[2] == 0) {
                if (it[3] == 1) {
                    if (y == 0 || gd.contains(Coord(x, y - 1)) || bo.contains(Coord(x, y)) || bo.contains(Coord(x - 1, y)))
                        gd.add(Coord(x, y))
                } else {
                    if (gd.contains(Coord(x, y + 1)))
                        if (!bo.contains(Coord(x - 1, y + 1)) && !bo.contains(Coord(x, y + 1)))
                            return@forEach
                    if (bo.contains(Coord(x, y + 1)))
                        if (!gd.contains(Coord(x + 1, y)) && !(bo.contains(Coord(x - 1, y + 1)) && bo.contains(Coord(x + 1, y + 1))))
                            return@forEach
                    if (bo.contains(Coord(x - 1, y + 1)))
                        if (!gd.contains(Coord(x - 1, y)) && !(bo.contains(Coord(x - 2, y + 1)) && bo.contains(Coord(x, y + 1))))
                            return@forEach
                    gd.remove(Coord(x, y))
                }
            } else {
                if (it[3] == 1) {
                    if (gd.contains(Coord(x + 1, y - 1)) || gd.contains(Coord(x, y - 1)) || (bo.contains(Coord(x - 1, y)) && bo.contains(Coord(x + 1, y))))
                        bo.add(Coord(x, y))
                } else {
                    if (bo.contains(Coord(x + 1, y)))
                        if (!gd.contains(Coord(x + 1, y - 1)) && !gd.contains(Coord(x + 2, y - 1)))
                            return@forEach
                    if (bo.contains(Coord(x - 1, y)))
                        if (!gd.contains(Coord(x, y - 1)) && !gd.contains(Coord(x - 1, y - 1)))
                            return@forEach
                    if (gd.contains(Coord(x, y)))
                        if (!bo.contains(Coord(x - 1, y)) && !gd.contains(Coord(x, y - 1)))
                            return@forEach
                    if (gd.contains(Coord(x + 1, y)))
                        if (!bo.contains(Coord(x + 1, y)) && !gd.contains(Coord(x + 1, y - 1)))
                            return@forEach
                    bo.remove(Coord(x, y))
                }
            }
        }
        val ans = mutableListOf<IntArray>()
        gd.forEach { ans.add(intArrayOf(it.x, it.y, 0)) }
        bo.forEach { ans.add(intArrayOf(it.x, it.y, 1)) }
        return ans.sortedWith(compareBy({ it[0] }, { it[1] }, { it[2] })).toTypedArray()
    }
}
