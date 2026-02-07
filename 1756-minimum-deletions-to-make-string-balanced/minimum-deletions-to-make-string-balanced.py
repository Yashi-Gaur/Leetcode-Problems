class Solution:
    def minimumDeletions(self, s: str) -> int:
        a_after = [0] * len(s)
        for i in range(len(s)-2, -1, -1):
            a_after[i] = a_after[i+1] + 1 if s[i+1] == 'a' else a_after[i+1]
        
        b_before = 0
        min_delete = a_after[0]
        for i in range(1, len(s)):
            b_before = b_before + 1 if s[i-1] == 'b' else b_before
            min_delete = min(min_delete, b_before+a_after[i])

        return min_delete
            
                