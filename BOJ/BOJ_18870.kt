import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main()=with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine()!!.toInt()
    val st = StringTokenizer(readLine()!!)
    val input = List(n) { Pair(st.nextToken().toInt(), it) }
    val temp = input.asSequence().distinctBy { it.first }.sortedBy { it.first }
    val map = hashMapOf<Int, Int>()
    temp.forEachIndexed { index, pair -> map[pair.first] = index }
    print(input.map { map[it.first]!! }.joinToString(" "))
}
