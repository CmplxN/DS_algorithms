class Solution {
    fun solution(citations: IntArray): Int {
        var idx = 0
        val list = citations.sortedByDescending{it}
        for(i in citations.size downTo 1){
            while(idx<citations.size&&i<=list[idx])
                idx++
            if(i<=idx)
                return i
        }
        return 0
    }
}
