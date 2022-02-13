from typing import List

# 给定一个n个元素有序的（升序）整型数组nums 和一个目标值target ，
# 写一个函数搜索nums中的 target，如果目标值存在返回下标，否则返回 -1。

def binary_search(nums:List[int],target:int)->int:
    print(nums,target)
    i,j = 0,len(nums)-1
    while 1:
        if i<=j:
            mid = (i + j) // 2
            if target == nums[mid]:
                return mid
            elif target < nums[mid]:
                j = mid - 1
            elif target > nums[mid]:
                i = mid + 1
        else:
            return -1


res = binary_search([-1,0,3,5,9,12],9)
# res = binary_search(list(range(0,10,2)),4)
print(res)