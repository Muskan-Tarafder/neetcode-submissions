"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        n=len(intervals)
        st,en=[],[]
        for i in range(len(intervals)):
            st.append(intervals[i].start)
            en.append(intervals[i].end)
        
        st.sort()
        en.sort()
        i,j=0,0
        cnt=0
        maxR=0
        while i<len(intervals):
            if(st[i]<en[j]):
                cnt+=1
                maxR=max(maxR,cnt)
                i+=1
            else:
                cnt-=1
                j+=1
        return maxR