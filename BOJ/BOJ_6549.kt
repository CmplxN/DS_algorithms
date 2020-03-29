import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

tailrec fun myLog(a: Int, now: Int): Int {
    if (a <= 1) return now
    return myLog(a / 2, now + 1)
}
tailrec fun myPow(a: Int,now: Int): Int {
    if (a == 0) return now
    return myPow(a - 1, now * 2)
}
fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val ans = mutableListOf<Long>()
    while (true) {
        val st = StringTokenizer(readLine()!!)
        val n = st.nextToken()!!.toInt()
        if (n == 0) break
        if (n==1){
            ans.add(st.nextToken()!!.toLong())
            continue
        }
        val s = 2*myPow(myLog(n-1,0),1)
        val tree = IntArray(4*myPow(myLog(n-1,0),1)) { 0 }
        val h = IntArray(2*n) { if(it<n) st.nextToken()!!.toInt() else 1000000010}
        for (i in s until 2*s) tree[i] = i - s
        for (i in s-1 downTo 1) tree[i] = if(h[tree[2*i]]<=h[tree[2*i+1]]) tree[2*i] else tree[2*i+1]
        fun query(left: Int, right: Int): Int{
            var l = left
            var r = right
            var rtn = tree[l]
            while(l<=r){
                if(l%2==1) rtn=if(h[rtn]<=h[tree[l]]) rtn else tree[l]
                if(r%2==0) rtn=if(h[rtn]<=h[tree[r]]) rtn else tree[r]
                l=(l+1)/2
                r=(r-1)/2
            }
            return rtn
        }
        fun getMax(left: Int, right: Int): Long{
            if(left==right) return h[tree[left]].toLong()
            else if(left>right) return 0
            val mid = query(left,right) + s
            val rtn = max((right-left+1).toLong() * h[tree[mid]].toLong(),getMax(left,mid-1))
            return max(rtn, getMax(mid+1,right))
        }
        ans.add(getMax(s, s+n-1))
    }
    print(ans.joinToString("\n"))
}
