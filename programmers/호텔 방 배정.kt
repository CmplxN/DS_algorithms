class Solution {
    val next = hashMapOf<Long, Long>()
    val ans = mutableListOf<Long>()
    fun find(dest: Long): Long {
        if (next.containsKey(dest))
            next[dest] = find(next[dest]!!)
        else {
            next[dest] = next[dest + 1] ?: dest + 1
            ans.add(dest)
        }
        return next[dest]!!
    }

    fun solution(k: Long, room_number: LongArray): LongArray {
        room_number.forEach { find(it) }
        return ans.toLongArray()
    }
}
