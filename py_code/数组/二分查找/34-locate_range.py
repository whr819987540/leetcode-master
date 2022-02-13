from typing import List


# 给定一个按照升序排列的整数数组 nums，和一个目标值 target。
# 找出给定目标值在数组中的开始位置和结束位置。
# 如果数组中不存在目标值 target，返回 [-1, -1]。

# 暴力
def enumeration(nums: List[int], target: int):
    for i in range(len(nums)):
        if target == nums[i]:
            j = i + 1
            while nums[j] == target:
                j += 1
            return (i, j - 1)
    return (-1, -1)


# 先通过一个二分查找，找到某个值
# 然后向两侧移动
def binary_enumeration(nums: List[int], target: int):
    left, right = 0, len(nums) - 1
    while 1:
        if left <= right:
            mid = (left + right) // 2
            mid_num = nums[mid]

            if target == mid_num:
                i, j = mid - 1, mid + 1
                # 防止越界
                while i >= 0 and nums[i] == mid_num:
                    i -= 1
                while j < len(nums) and nums[j] == mid_num:
                    j += 1
                return (i + 1, j - 1)
            elif target < mid_num:
                right = mid - 1
            else:
                left = mid + 1

        else:
            return (-1, -1)


def getLeftBorder(nums: List[int], target: int):
    left = 0
    right = len(nums) - 1  # 定义target在左闭右闭的区间里，[left, right]
    leftBorder = -2  # 记录一下leftBorder没有被赋值的情况
    while (left <= right):
        middle = (left + right) // 2
        if (nums[middle] >= target):  # // 寻找左边界，就要在nums[middle] == target的时候更新right
            right = middle - 1
            leftBorder = right
        else:
            left = middle + 1

    return leftBorder


# // 二分查找，寻找target的右边界（不包括target）
# // 如果rightBorder为没有被赋值（即target在数组范围的左边，例如数组[3,3]，target为2），为了处理情况一
def getRightBorder(nums: List[int], target: int):
    left = 0
    right = len(nums) - 1  # // 定义target在左闭右闭的区间里，[left, right]
    rightBorder = -2  # // 记录一下rightBorder没有被赋值的情况
    while (left <= right):  # // 当left==right，区间[left, right]依然有效
        middle = (left + right) // 2
        if (nums[middle] > target):
            right = middle - 1  # // target 在左区间，所以[left, middle - 1]
        else:  # // 当nums[middle] == target 的时候，更新left，这样才能得到target的右边界
            left = middle + 1
            rightBorder = left

    return rightBorder


def double_binary(nums: List[int], target: int):
    lm = left_margin(nums, target)
    rm = right_margin(nums, target)
    # target不在数组内
    if lm == -2 or rm == -2:
        return (-1, -1)
    # target在数组内
    else:
        # target没有匹配值
        if rm - lm < 2:
            return (-1, -1)
        else:
            return (lm + 1, rm - 1)


# 找到左边界
# 真正的左边界应该是返回值+1
def left_margin(nums: List[int], target: int):
    left, right = 0, len(nums) - 1
    ret = -2
    while left <= right:
        mid = (left + right) // 2
        mid_num = nums[mid]
        # target在mid右侧，直接更新left
        if target > mid_num:
            left = mid + 1
        # target < mid_num, 继续向左寻找
        # target == mid_num时，不是返回
        # 而是继续向左寻找
        else:
            right = mid - 1
            ret = right
    return ret


def right_margin(nums: List[int], target: int):
    left, right = 0, len(nums) - 1
    ret = -2
    while left <= right:
        mid = (left + right) // 2
        mid_num = nums[mid]
        # target在mid左侧，直接更新right
        if target < mid_num:
            right = mid - 1
        else:
            left = mid + 1
            ret = left
    return ret


# 通过一个二分查找，找到两个左右边界
def single_binary(nums: List[int], target: int):
    pass


res = enumeration([5, 7, 7, 8, 8, 10], 5)
print(res, type(res))

res = binary_enumeration([5, 7, 7, 8, 8, 10], 8)
print(res, type(res))

res = getLeftBorder([5, 7, 7, 8, 8, 10], 7)
print(res)

res = getRightBorder([5, 7, 7, 8, 8, 10], 7)
print(res)

res = left_margin([5, 7, 7, 8, 8, 10], 6)
print(res)

res = right_margin([5, 7, 7, 8, 8, 10], 6)
print(res)

res = double_binary([5, 7, 7, 8, 8, 10], 7)
print(res)