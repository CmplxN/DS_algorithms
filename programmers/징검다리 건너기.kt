import java.util.*
import kotlin.math.*
class Solution {
    fun solution(stones: IntArray, k: Int): Int {
        var answer=2000000000
        val pq = PriorityQueue<Pair<Int,Int>>(compareBy({-it.first},{-it.second}))
        var maxi = 0
        repeat(k){
            maxi=max(maxi,stones[it])
            pq.add(Pair(stones[it],it))
            answer=maxi
        }
        for(i in 1 .. stones.size-k){
            pq.add(Pair(stones[i+k-1],i+k-1))
            while(!pq.isEmpty()){
                val now = pq.peek()
                if(now.second<i) pq.poll()
                else break
            }
            maxi=pq.peek().first
            answer=min(maxi,answer)
        }
        return answer
    }
}
