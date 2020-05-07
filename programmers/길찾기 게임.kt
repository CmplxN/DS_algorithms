class Solution {
    val pre = mutableListOf<Int>()
    val post = mutableListOf<Int>()

    inner class Node(val name: Int, val x: Int, val y: Int, var left: Node?, var right: Node?) {
        fun insert(iName: Int, ix: Int, iy: Int): Unit =
                if (ix > x) right?.insert(iName, ix, iy) ?: run { right = Node(iName, ix, iy, null, null) }
                else left?.insert(iName, ix, iy) ?: run { left = Node(iName, ix, iy, null, null) }

        fun preorder() {
            pre.add(name)
            left?.preorder()
            right?.preorder()
        }

        fun postorder() {
            left?.postorder()
            right?.postorder()
            post.add(name)
        }
    }

    fun solution(nodeinfo: Array<IntArray>): Array<IntArray> {
        val sorted = nodeinfo.mapIndexed { index, ints -> Triple(index + 1, ints[0], ints[1]) }.sortedWith(compareBy({ -it.third }, { it.second }))
        val rootNode = Node(sorted[0].first, sorted[0].second, sorted[0].third, null, null)
        sorted.forEachIndexed { index, it -> if (index != 0) rootNode.insert(it.first, it.second, it.third) }
        rootNode.preorder()
        rootNode.postorder()
        return arrayOf(pre.toIntArray(), post.toIntArray())
    }
}
