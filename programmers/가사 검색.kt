data class Trie(val next:HashMap<Char,Trie>, var cnt: Int = 0, var fin:Boolean = false) {
    fun insert(str: String, idx: Int, end: Int) {
        cnt++
        if (idx == end) {
            fin = true
            return
        }
        next.computeIfAbsent(str[idx]) { Trie(hashMapOf()) }
        next[str[idx]]!!.insert(str, idx + 1, end)
    }

    fun search(str: String, idx: Int, end: Int): Int {
        if (idx == end) return cnt
        if (str[idx] != '?') return next[str[idx]]?.search(str, idx + 1, end) ?: 0
        return next.map { it.value.cnt }.sum()
    }
}
class Solution {
    fun solution(words: Array<String>, queries: Array<String>): IntArray {
        val nTrie = Array(10001) { Trie(hashMapOf()) }
        val rTrie = Array(10001) { Trie(hashMapOf()) }
        words.forEach {
            nTrie[it.length].insert(it, 0, it.length)
            rTrie[it.length].insert(it.reversed(), 0, it.length)
        }
        return queries.map {
            when {
                it.last() == '?' -> nTrie[it.length].search(it, 0, it.length)
                else -> rTrie[it.length].search(it.reversed(), 0, it.length)
            }
        }.toIntArray()
    }
}
