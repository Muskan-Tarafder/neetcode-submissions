class Solution:

    def encode(self, strs: List[str]) -> str:
        parts=[]
        for s in strs:
            parts.append(f'-{s}')
        return "".join(parts)
    def decode(self, s: str) -> List[str]:
        m=[]
        if s=='':
            return []
        else:
            m=s.split('-')
            print(m)
            m=m[1::]
        return m