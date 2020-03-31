import kotlin.math.min

fun main() {
    val str = readLine()!!
    val manacher = IntArray(str.length) { 0 }
    var (r, p) = Pair(0, 0)
    for (c in str.withIndex()) {
        if (c.index <= r) manacher[c.index] = min(manacher[2 * p - c.index], r - c.index)
        else manacher[c.index] = 0
        while (c.index - manacher[c.index] - 1 >= 0 && c.index + manacher[c.index] + 1 < str.length &&
            str[c.index - manacher[c.index] - 1] == str[c.index + manacher[c.index] + 1]
        )
            manacher[c.index]++
        if (r < c.index + manacher[c.index]) {
            r = c.index + manacher[c.index]
            p = c.index
        }
    }
    print(manacher.toList().joinToString(" "))
}
