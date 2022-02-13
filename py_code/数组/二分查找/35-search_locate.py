from typing import List

# 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
# 如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

def enumeration(nums:List[int],target:int)->int:
    # 处理最左侧，找到，两个数之间三种情况
    for i in range(len(nums)):
        if target <= nums[i]:
            return i
    # 处理最右侧一种情况
    return len(nums)

def binary(nums: List[int], target: int) -> int:
    left, right = 0, len(nums) - 1
    while 1:
        if left <= right:
            mid = (left+right)//2
            mid_num = nums[mid]
            if target == mid_num:
                return mid
            elif target < mid_num:
                right = mid - 1
            else:
                left = mid + 1
        else:
            return right + 1

res = binary([-1,0,3,5,9,12],1)
# res = binary_search(list(range(0,10,2)),4)
print(res)

res = enumeration([-1,0,3,5,9,12],1)
# res = binary_search(list(range(0,10,2)),4)
print(res)