import java.io.BufferedReader
import java.io.InputStreamReader
import java.math.BigInteger
import kotlin.random.Random
import kotlin.random.nextUInt

val random = Random(6523)

fun function(x: BigInteger):BigInteger = x * x

tailrec fun gcd(x:BigInteger,y:BigInteger):BigInteger {
    if (y == BigInteger.ZERO) return x
    return gcd(y, x.mod(y))
}

val tester = arrayOf(BigInteger("17"),BigInteger("13"),BigInteger("11"),
    BigInteger("5"),BigInteger("3"),BigInteger("2"),BigInteger("7"),BigInteger("19"),
    BigInteger("23"),BigInteger("29"),BigInteger("31"),BigInteger("37"),BigInteger("41"))

fun millerRabin(n:BigInteger, a:BigInteger):Boolean {
    var temp = n - BigInteger.ONE
    while (temp % BigInteger("2") == BigInteger.ZERO) {
        if (a.modPow(temp, n) == n - BigInteger.ONE)
            return true
        temp /= BigInteger("2")
    }
    val rst = a.modPow(temp, n)
    return rst == n - BigInteger.ONE || rst == BigInteger.ONE
}

fun primeTester(num : BigInteger):Boolean {
    if (num <= BigInteger.ONE) return false
    if (num.mod(BigInteger("2")) == BigInteger.ZERO) return false
    if (num <= BigInteger("10000")) {
        val i = num.toInt()
        var j = 2
        while (j * j <= i) {
            if (i % j == 0)
                return false
            j++
        }
        return true
    }
    for (test in tester)
        if (!millerRabin(num, test))
            return false
    return true
}

fun PollardRho(n: BigInteger):BigInteger {
    if(primeTester((n))) return n
    if(n== BigInteger.ONE) return BigInteger.ONE
    if(n.mod(BigInteger("2"))== BigInteger.ZERO) return BigInteger("2")
    var x = BigInteger((random.nextUInt()).toString()).mod(n - BigInteger("2")) + BigInteger("2")
    var y = x
    var p = BigInteger.ONE
    val k = BigInteger((random.nextUInt()).toString()).mod(n - BigInteger("1")) + BigInteger("1")
    while (p == BigInteger.ONE) {
        x = (function(x) + k).mod(n)
        y = (function(y) + k).mod(n)
        y = (function(y) + k).mod(n)
        p = gcd((x - y).abs(), n)
        if (p == n) return PollardRho(n)
    }
    if(!primeTester(p)) return PollardRho(p)
    return p
}

fun main()=BufferedReader(InputStreamReader(System.`in`)).run {
    var number = BigInteger(readLine()!!)
    if(number == BigInteger.ONE){
        print(1)
        return
    }
    val list = mutableListOf<BigInteger>()
    while(number > BigInteger.ONE){
        val rst = PollardRho(number)
        list.add(rst)
        number /= rst
    }
    list.sort()
    println(list.joinToString("\n"))
}
