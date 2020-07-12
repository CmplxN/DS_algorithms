import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.collections.HashSet

fun MutableList<Int>.copy() : List<Int> {
    return map { it }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    var sa = readLine()
    var sb = readLine()
    val comparator = kotlin.Comparator<List<Int>> { o1, o2 ->
        for (idx in o1.indices) {
            if (o1[idx] != o2[idx])
                return@Comparator o1[idx] - o2[idx]
        }
        0
    }
    var ans = 0
    if (sa.length > sb.length)
        sa = sb.also { sb = sa }
    loop@ for (len in sa.length downTo 0) {
        ans = len
        if (ans == 0)
            break
        val list = MutableList(26) { 0 }
        sa.substring(0 until len).forEach { list[it.toInt() - 97]++ }
        val set = sortedSetOf(comparator, list.copy())
        for (i in 0 until sa.length - len) {
            list[sa[i].toInt() - 97]--
            list[sa[i + len].toInt() - 97]++
            set.add(list.copy())
        }
        val compareList = MutableList(26) { 0 }
        sb.substring(0 until len).forEach { compareList[it.toInt() - 97]++ }
        if (set.contains(compareList))
            break
        for (i in 0 until sb.length - len) {
            compareList[sb[i].toInt() - 97]--
            compareList[sb[i + len].toInt() - 97]++
            if (set.contains(compareList))
                break@loop
        }
    }
    print(ans)
}
