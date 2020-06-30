typealias Index = Int

fun <T : Comparable<T>> lowerBound(elements: List<T>, l: Index, r: Index, value: T): Index {
    var left = l
    var right = r
    var mid: Index
    while (left < right) {
        mid = (left + right) shr 1
        if (mid == r)
            return r
        if (elements[mid] < value)
            left = mid + 1
        else
            right = mid
    }
    return left
}

fun isOk(rocks: List<Int>, dist: Int, n: Int): Boolean {
    var idx = 0
    var cnt = 0
    while (idx < rocks.lastIndex) {
        val lb = lowerBound(rocks, 0, rocks.lastIndex, rocks[idx] + dist)
        if (lb - idx != 1) 
            cnt += lb - idx - 1
        idx = lb
    }
    return cnt <= n
}

class Solution {
    fun solution(distance: Int, rocks: IntArray, n: Int): Int {
        var answer = 0
        var left = 1
        var right = distance
        val paramRock = (rocks.toList() + listOf(0, distance)).sorted()
        while (left <= right) {
            val mid = (left + right) / 2
            if (isOk(paramRock, mid, n)) {
                answer = mid
                left = mid + 1
            } else {
                right = mid - 1
            }
        }
        return answer
    }
}
