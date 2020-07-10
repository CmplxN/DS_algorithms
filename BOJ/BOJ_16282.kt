import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val N = readLine().toLong()
    var ans = 1
    while (true) {
        var temp = ans.toLong()
        for (i in 0..ans) 
            temp += temp + 1
        if (temp >= N)
            break
        ans++
    }
    print(ans)
}
