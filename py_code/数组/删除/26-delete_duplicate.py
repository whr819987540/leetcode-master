from typing import List


# 给你一个升序排列的数组nums，请你原地删除重复出现的元素，
# 使每个元素只出现一次，返回删除后数组的新长度。
# 元素的相对顺序应该保持一致。
# 由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。
# 更规范地说，如果在删除重复项之后有k个元素，那么nums的前k个元素应该保存最终结果。
# 将最终结果插入nums的前k个位置后返回k。
# 不要使用额外的空间，你必须在原地修改输入数组并在使用O(1)额外空间的条件下完成。

# 用快慢指针来完成
# 如果slow==quick，则quick向后移动，slow不动
# 否则，将quick的值放到slow+1位置
# nums=[0,0,1,1,1,2,2,3,3,4]
# nums=[0,1,2,3,4]

def double_pointers(nums: List[int]) -> int:
    slow = 0
    for quick in range(len(nums)):
        if nums[slow] == nums[quick]:
            pass
        else:
            slow += 1
            nums[slow] = nums[quick]
    return slow + 1


res = double_pointers([0, 0, 1, 1, 1, 2, 2, 3, 3, 4])
print(res)
