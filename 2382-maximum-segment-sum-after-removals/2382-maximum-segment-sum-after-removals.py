from sortedcontainers import SortedDict

class Solution(object):
    def maximumSegmentSum(self, nums, removeQueries):
        """
        :type nums: List[int]
        :type removeQueries: List[int]
        :rtype: List[int]
        """
        r, p, s, t = [0] * len(nums), [0] * len(nums), 0, SortedDict({0: len(nums) - 1})
        for i in range(len(nums)):
            s, p[i] = s + nums[i], s + nums[i]
        u, i = SortedDict({s: 1}), 0
        for q in removeQueries:
            l, v = t.keys()[t.bisect_left(q + .1) - 1], t[t.keys()[t.bisect_left(q + .1) - 1]]
            t.pop(l)
            if u[p[v] - (p[l - 1] if l > 0 else 0)] == 1:
                u.pop(p[v] - (p[l - 1] if l > 0 else 0))
            else:
                u[p[v] - (p[l - 1] if l > 0 else 0)] = u[p[v] - (p[l - 1] if l > 0 else 0)] - 1
            if q > l:
                u[p[q - 1] - (p[l - 1] if l > 0 else 0)], t[l] = (u[p[q - 1] - (p[l - 1] if l > 0 else 0)] if p[q - 1] - (p[l - 1] if l > 0 else 0) in u else 0) + 1, q - 1
            if q < v:
                u[p[v] - p[q]], t[q + 1] = (u[p[v] - p[q]] if p[v] - p[q] in u else 0) + 1, v
            r[i], i = u.keys()[-1] if u else 0, i + 1
        return r