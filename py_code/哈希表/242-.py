class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_dict,t_dict = self.map(s),self.map(t)
        return s_dict == t_dict

    # def map(self,s:str):
    #     s_dict = {}
    #     for i in s:
    #         if not s_dict.get(i):
    #             s_dict[i] = 1
    #         else:
    #             s_dict[i] += 1
    #     return s_dict

    def map(self,s:str):
        from collections import defaultdict
        dict_s = defaultdict(int)
        for i in s:
            dict_s[i] += 1
        return dict_s

s = Solution()
res = s.isAnagram('abbb','bbba')
print(res)