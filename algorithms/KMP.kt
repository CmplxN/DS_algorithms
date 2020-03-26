fun main() {
    val (str, tar) = Pair(readLine()!!, readLine()!!)
    val fail: List<Int> = run {
        val rtn = mutableListOf<Int>()
        var j = 0
        rtn.add(0)
        for (i in 1 until tar.length) {
            while (j > 0 && tar[i] != tar[j]) j = rtn.get(j - 1)
            if (tar[i] == tar[j]) rtn.add(++j)
            else rtn.add(0)
        }
        rtn
    }
    val kmp: List<Int> = run {
        val rtn = mutableListOf<Int>()
        var j = 0
        for (i in str.indices) {
            while (j > 0 && str[i] != tar[j]) j = fail[j - 1]
            if (str[i] == tar[j]) {
                if (j == tar.length - 1) {
                    rtn.add(i - tar.length + 2)
                    j = fail[j]
                } else j++
            }
        }
        rtn
    }
    println(kmp.size)
    print(kmp.joinToString(" "))
}
