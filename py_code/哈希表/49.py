from collections import defaultdict
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # key=str, value=dict
        map_res_str_dict = []
        for s in strs:
            my_dict = self.map(s)
            map_res_str_dict.append([s,my_dict])

        res = []
        for i in map_res_str_dict[:]:
            tmp_res = []
            try:
                map_res_str_dict.remove(i)
                tmp_res.append(i[0])
            except:
                continue
            for j in map_res_str_dict[:]:
                if i[1] == j[1]:
                    try:
                        map_res_str_dict.remove(j)
                        tmp_res.append(j[0])
                    except:
                        continue
            print('-'*10)
            res.append(tmp_res)
        return res
    def map(self, s: str) -> defaultdict:
        tmp = defaultdict(int)
        for i in s:
            tmp[i] += 1
        return tmp


s = Solution()
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
res = s.groupAnagrams(strs)
print(res)