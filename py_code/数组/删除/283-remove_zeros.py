# 给定一个数组nums，编写一个函数将所有0移动到数组的末尾，同时保持非零元素的相对顺序。
# 请注意，必须在不复制数组的情况下原地对数组进行操作。

# 目的是将后面的非零值都移动到前端
# 快指针扫描到非零值且慢指针为零值时，交换
from typing import List


def double_pointers(nums: List[int]) -> None:
    slow = 0
    for quick in range(len(nums)):
        if nums[quick] != 0:
            if nums[slow] == 0:
                nums[slow] = nums[quick]
                nums[quick] = 0
            slow += 1
    print(nums)

res = double_pointers([0,1,2,0,0,3,0])