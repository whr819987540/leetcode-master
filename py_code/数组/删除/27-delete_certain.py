from typing import List


# 给你一个数组 nums和一个值 val，你需要 原地 移除所有数值等于val的元素，并返回移除后数组的新长度。
# 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
# 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。


def double_pointers(nums: List[int], val: int) -> int:
    slow = 0
    for quick in range(len(nums)):
        # 不相等，应该移动
        # 不移动就是把这个元素删除了
        if nums[quick] != val:
            nums[slow] = nums[quick]
            slow += 1
    print(nums, type(nums))
    return slow


res = double_pointers([0, 1, 2, 2, 3, 0, 4, 2], 2)
print(res)
