# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

class NestedIterator:
    def __init__(self, A: [NestedInteger]):
        self.g = self.gnt(A)
        self.val = None
        self.next()
    
    def next(self) -> int:
        res = self.val
        try:
            self.val = next(self.g)
        except StopIteration:
            self.val = None
        return res
    
    def hasNext(self) -> bool:
        return self.val is not None
        
    def gnt(self, A):
        for i in A:
            if i.isInteger():
                yield i.getInteger()
            else:
                yield from self.gnt(i.getList())
         

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())