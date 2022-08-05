from sortedcontainers import SortedList
from bisect import bisect_right
class MyCalendar:

    def __init__(self):
        self.m = SortedList()

    def book(self, start: int, end: int) -> bool:
        idx = bisect_right(self.m, (start, inf))
        if idx != len(self.m) and self.m[idx][1] < end:
            return False
        self.m.add((end, start))
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)