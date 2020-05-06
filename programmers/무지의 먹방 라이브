class Solution {
    fun solution(food_times: IntArray, k: Long): Int {
        var(cnt,foodLeft,cum)=Triple<Long,Int,Int>(k,food_times.size,0)
        val st = (0 until foodLeft).toHashSet()
        food_times.mapIndexed { index, i -> Pair(i, index) }
                .groupBy { it.first }
                .toSortedMap()
                .forEach {
                    if (cnt < foodLeft.toLong() * (it.key-cum)) {
                        return st.sorted().toList()[(cnt % foodLeft).toInt()] + 1
                    } else {
                        cnt -= foodLeft * (it.key-cum)
                        foodLeft -= it.value.size
                        it.value.forEach { st.remove(it.second) }
                        cum = it.key
                    }
                }
        return -1
    }
}
