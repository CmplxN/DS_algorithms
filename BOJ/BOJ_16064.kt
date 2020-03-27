import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.Comparator
import kotlin.math.max

data class Info(val to : Int, val score : Int)
const val NO_TOUCH = -99999999
val fcmp : Comparator<Info> = compareByDescending { it.score }
fun main()=BufferedReader(InputStreamReader(System.`in`)).run{
    val (n,m)=readLine()!!.split(' ').map{it.toInt()}
    val data=Array<MutableList<Info>>(n){ mutableListOf()}
    val noIn=Array(n){true}
    for(i in 1..m){
        val st=StringTokenizer(readLine()!!)
        val(from,to,score)=Triple(st.nextToken().toInt()-1,
            st.nextToken().toInt()-1,st.nextToken().toInt())
        data[from].add(Info(to,score))
        noIn[to] = false
    }
    var ans = 0
    for(i in noIn.indices){
        if(!noIn[i]) continue
        val pq = PriorityQueue(fcmp)
        val save = IntArray(n){NO_TOUCH}
        pq.add(Info(i,0))
        while(!pq.isEmpty()){
            val now = pq.poll()
            if(save[now.to]>now.score) continue
            save[now.to]=now.score
            for(next in data[now.to]) pq.add(Info(next.to,now.score+next.score))
        }
        var hereMax=0
        for(elm in save) if(elm!=NO_TOUCH&&elm>hereMax) hereMax=elm
        ans=max(hereMax,ans)
    }
    print(ans)
}
