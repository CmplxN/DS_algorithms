class Solution {
    fun solution(s: String): IntArray = 
        s.drop(2)
        .dropLast(2)
        .split("},{")
        .map{it.split(",")
        .map{k->k.toInt()}}
        .sortedBy{it.size}
        .fold(mutableSetOf<Int>()){st,lst->
            st.union(lst).toMutableSet()}
        .toIntArray()
}
