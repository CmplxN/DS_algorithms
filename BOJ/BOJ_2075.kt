import java.io.*
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
	val n = readLine().toInt()
	val pq : PriorityQueue<Int> = PriorityQueue<Int>()
	for(i in 1..n){
		val st = StringTokenizer(readLine())
		for(j in 1..n) {
			val input = st.nextToken().toInt()
			if (pq.size < n)
				pq.add(input)
			else if(pq.peek() < input){
				pq.poll()
				pq.add(input)
			}
		}
	}
	print(pq.peek())
}
