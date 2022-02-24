class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        from collections import defaultdict
        # 完全用magazine中的字符来构成ransomNote
        my_dict = defaultdict(int)
        for i in magazine:
            my_dict[i] += 1
        for i in ransomNote:
            my_dict[i] -= 1
            if my_dict[i] < 0:
                return False
        return True

s = Solution()
print(s.canConstruct('aaab','aabb'))