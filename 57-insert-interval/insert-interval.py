class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        new_i_pushed = 0
        ans = []
        for i in range(len(intervals)):
            if intervals[i][1] < newInterval[0] or new_i_pushed:
                ans.append(intervals[i])
            elif ((intervals[i][0] <= newInterval[0] and  intervals[i][1] >= newInterval[0]) or (intervals[i][0] <= newInterval[1] and  intervals[i][1] >= newInterval[1])):
                newInterval[0] = min(intervals[i][0], newInterval[0])
                newInterval[1] = max(intervals[i][1], newInterval[1])
            elif intervals[i][0] > newInterval[1]:
                ans.append(newInterval)
                ans.append(intervals[i])
                new_i_pushed = 1
        if new_i_pushed == 0:
            ans.append(newInterval)
        return ans