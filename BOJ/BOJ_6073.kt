import java.io.*
import java.util.*

class Trie(var fin: Int, var cnt : Int) {
    val next = arrayOfNulls<Trie>(2)
    tailrec fun insert(key: String, idx: Int, trie: Trie): Boolean {
        trie.cnt++
        if (key.length == idx) {
            trie.fin++
            return true
        }
        trie.next[key[idx].toInt() - 48] ?: run { trie.next[key[idx].toInt() - 48] = Trie(0, 0) }
        return insert(key, idx + 1, trie.next[key[idx].toInt() - 48]!!)
    }

    tailrec fun search(key: String, idx: Int, save: Int, trie: Trie): Int {
        if (key.length == idx) return trie.cnt + save
        trie.next[key[idx].toInt() - 48] ?: return trie.fin + save
        return search(key, idx + 1, save + trie.fin, trie.next[key[idx].toInt() - 48]!!)
    }
}

fun main()=with(BufferedReader(InputStreamReader(System.`in`))) {
    val trie = Trie(0, 0)
    val list = mutableListOf<Int>()
    val (M, N) = readLine()!!.split(' ').map { it.toInt() }
    for (i in 1..M) {
        val tk = StringTokenizer(readLine())
        val lst = mutableListOf<Char>()
        repeat(Integer.parseInt(tk.nextToken())) { lst.add(tk.nextToken()[0]) }
        trie.insert(lst.joinToString(""), 0, trie)
    }
    for (i in 1..N) {
        val tk = StringTokenizer(readLine())
        val lst = mutableListOf<Char>()
        repeat(Integer.parseInt(tk.nextToken())) { lst.add(tk.nextToken()[0]) }
        list.add(trie.search(lst.joinToString(""), 0, 0, trie))
    }
    print(list.joinToString("\n"))
}
