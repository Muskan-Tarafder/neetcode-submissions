class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expand(l,r):
            while l>=0 and r<len(s) and s[l]==s[r]:
                l-=1
                r+=1
            return l+1,r-1
        if len(s)<2:
            return s
        
        st=0
        max_l=1

        for i in range(len(s)):
            l1,r1=expand(i,i)
            l2,r2=expand(i,i+1)
            if r1-l1+1>max_l:
                st=l1
                max_l=r1-l1+1
            if r2-l2+1>max_l:
                st=l2
                max_l=r2-l2+1
        return s[st:st+max_l]