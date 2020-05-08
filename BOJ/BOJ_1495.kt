fun main() {
    val (N,S,M) = readLine()!!.split(' ').map{it.toInt()}
    val info = readLine()!!.split(' ').map{it.toInt()}
    val candidate = Array(N+1){Array(M+1){false} }
    candidate[0][S] = true
    for(i in 1 .. N) {
        candidate[i-1].forEachIndexed { index, b ->
            if(b){
                if(index-info[i-1]>=0) candidate[i][index-info[i-1]]=true
                if(index+info[i-1]<=M) candidate[i][index+info[i-1]]=true
            }
        }
    }
    print(candidate[N].dropLastWhile { !it }.size - 1)
}
