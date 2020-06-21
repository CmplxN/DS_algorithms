import kotlin.math.sqrt

data class Ans(val x: Long, val y: Long)

val repository = mutableSetOf<Ans>()
val S = mutableSetOf(0L, 1L, 2L)

fun solve(N: Long) {
    val temp = sqrt(N.toDouble()).toLong()
    val x = if (temp * temp == N) temp else temp + 1
    val y = x * x - N
    if (!S.contains(x)) {
        solve(x)
        S.add(x)
    }
    if (!S.contains(y)) {
        solve(y)
        S.add(y)
    }
    if (!repository.contains(Ans(x, y))) {
        repository.add(Ans(x, y))
        println("$x $y")
    }
}

fun main() = solve(readLine()!!.toLong())
