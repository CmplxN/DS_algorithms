import java.io.BufferedReader
import java.io.InputStreamReader

fun main()=with(BufferedReader(InputStreamReader(System.`in`))) {
    val map = hashMapOf<String, Int>()
    val list = mutableListOf<String>()
    repeat(readLine()!!.toInt()) {
        val str = readLine()!!
        list.add(str)
        val set = hashSetOf<String>()
        for (i in str.indices) for (j in i until str.length)
            set.add(str.substring(i, j + 1))
        set.forEach { map[it] = map[it]?.plus(1) ?: 1 }
    }
    print(list.map { map[it]?.minus(1) ?: 0 }.sum())
}
