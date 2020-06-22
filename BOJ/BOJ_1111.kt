import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val N = readLine().toInt()
    val input = readLine().split(' ').map { it.toInt() }
    if (N == 1)
        print("A")
    if (N == 2)
        print(if (input[0] == input[1]) input[1] else "A")
    if (N >= 3) {
        if (input[0] == input[1]) {
            if (input.all { it == input[0] })
                print(input[0])
            else
                print("B")
        } else if ((input[2] - input[1]) % (input[1] - input[0]) != 0)
            print("B")
        else {
            val a = (input[2] - input[1]) / (input[1] - input[0])
            val b = if (a != 0) input[1] - a * input[0] else input[1]
            print(if (input.drop(1).fold(Pair(input[0], true)) { pair: Pair<Int, Boolean>, i: Int ->
                        if (a * pair.first + b == i) Pair(a * pair.first + b, pair.second)
                        else Pair(a * pair.first + b, false)
                    }.second) a * input.last() + b else "B")
        }
    }
}
