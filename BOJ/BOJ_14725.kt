import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

data class Tree(val map: SortedMap<String,Tree>, val str: String) {
    fun insert(list: List<String>){
        if(list.isEmpty()) return
        if(!map.containsKey(list.first()))
            map[list.first()] = Tree(sortedMapOf(), list.first())
        map[list.first()]?.insert(list.drop(1))
    }
    fun search(depth: Int){
        repeat(if(depth==0) 0 else depth-1){
            print("--")
        }
        if(depth!=0) println(str)
        map.forEach{
            it.value.search(depth+1)
        }
    }
}

fun main()=BufferedReader(InputStreamReader(System.`in`)).run{
    val tree = Tree(sortedMapOf(), "")
    repeat(readLine()!!.toInt()){
        val st = StringTokenizer(readLine()!!)
        tree.insert(List(st.nextToken().toInt()){st.nextToken()!!})
    }
    tree.search(0)
}
