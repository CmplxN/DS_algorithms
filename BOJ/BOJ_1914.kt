import java.io.BufferedReader
import java.io.InputStreamReader
import java.math.BigInteger
import kotlin.math.min

data class Answer(val from: Int, val to: Int){
    override fun toString(): String = "$from $to"
}

val ans = mutableListOf<Answer>()

fun hanoi(n: Int, l: Int, m: Int, r: Int) {
    if (n == 0) return
    hanoi(n - 1, l, r, m)
    ans.add(Answer(l, r))
    hanoi(n - 1, m, l, r)
}

fun main() = BufferedReader(InputStreamReader(System.`in`)).run {
    val input = readLine()!!.toInt()
    println(BigInteger("2").pow(input) - BigInteger.ONE)
    if(input<=20){
        hanoi(input,1,2,3)
        print(ans.joinToString("\n"))
    }
}
