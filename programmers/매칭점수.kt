class Solution {
    fun solution(word: String, pages: Array<String>): Int {
        val ans = Array(pages.size) { 0.0 }
        val urls = hashMapOf<String, Int>()
        pages.forEachIndexed { index, it ->
            urls["""<meta property="og:url" content="(.+?)"\/>""".toRegex()
                .find(it)?.groupValues!![1]] = index
        }
        val temp = pages.map { s ->
            val str = s.toLowerCase()
            var rtn = 0
            word.toLowerCase().toRegex()
                .findAll(str)
                .forEach { if (!str[it.range.first - 1].isLowerCase() && !str[it.range.last + 1].isLowerCase()) rtn++ }
            rtn
        }
        pages.forEachIndexed { index, it ->
            val t = """<a href="(.+?)">""".toRegex().findAll(it).toList()
            t.forEach { str ->
                if (urls.contains(str.groupValues[1]))
                    ans[urls[str.groupValues[1]]!!] += temp[index].toDouble() / t.size.toDouble()
            }
        }
        for (i in ans.indices) ans[i] += temp[i].toDouble()
        val maxVal = ans.max()!!
        return ans.indexOfFirst { it == maxVal }
    }
}
