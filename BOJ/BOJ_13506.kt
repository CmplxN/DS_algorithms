fun main() {
    val str = readLine()!!
    val fail: List<Int> = run {
        val rtn = mutableListOf<Int>(0)
        var j = 0
        for (i in 1 until str.length) {
            while (j > 0 && str[i] != str[j]) j = rtn.get(j - 1)
            if (str[i] == str[j]) rtn.add(++j)
            else rtn.add(0)
        }
        rtn
    }
    var len= fail[fail.lastIndex]
    here@while(len>0){
        for(i in 1..str.length-2) if(fail[i]==len) break@here
        len=fail[len-1]
    }
    print(if(len==0) -1 else str.take(len))
}
