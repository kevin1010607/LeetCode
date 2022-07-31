class NumArray:

    def __init__(self, nums: List[int]):
        self.sz = len(nums)
        self.A = [0]*(self.sz+1)
        for i, v in enumerate(nums):
            self.update(i, v)
            
    def query(self, idx: int) -> int:
        idx += 1; res = 0
        while idx > 0:
            res += self.A[idx]
            idx -= idx&-idx
        return res

    def update(self, idx: int, val: int) -> None:
        dval = val-(self.query(idx)-self.query(idx-1))
        idx += 1
        while idx <= self.sz:
            self.A[idx] += dval
            idx += idx&-idx

    def sumRange(self, left: int, right: int) -> int:
        return self.query(right)-self.query(left-1)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)