"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def __init__(self):
        self.m = {}
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        if node not in self.m:
            self.m[node] = Node(node.val)
            for i in node.neighbors:
                self.m[node].neighbors.append(self.cloneGraph(i))
        return self.m[node]