typealias Index = Int

fun <T:Comparable<T>> lowerBound(elements: List<T>, l: Index, r: Index, value: T) : Index {
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

fun <T:Comparable<T>> upperBound(elements: List<T>, l: Index, r: Index, value: T) : Index {
    var left = l
    var right = r
    var mid: Index
    while (left < right) {
        mid = (left + right) shr 1
        if (mid == r)
            return r
        if (elements[mid] <= value)
            left = mid + 1
        else
            right = mid
    }
    return left
}
