import java.io.BufferedReader
import java.io.InputStreamReader

fun test(str: StringBuilder): Boolean {
    val lastIdx = str.length - 1
    if (lastIdx == 0) return true
    for (i in 0 until str.length / 2) {
        if (str.substring(lastIdx - i..lastIdx)
                .compareTo(str.substring(lastIdx - i - 1 - i until lastIdx - i)) == 0
        )
            return false
    }
    return true
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val N = readLine()!!.toInt()
    var solved = false
    fun dfs(dep: Int, str: StringBuilder) {
        if (solved) return
        if (dep == N) {
            print(str)
            solved = true
            return
        }
        for (i in 1..3) {
            str.append(i)
            if (test(str))
                dfs(dep + 1, str)
            str.deleteCharAt(str.length - 1)
        }
    }
    dfs(0, StringBuilder(""))
}
