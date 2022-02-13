# 给定一个 正整数 num ，编写一个函数，
# 如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
# 进阶：不要 使用任何内置的库函数，如sqrt 。

def binary(num: int) -> int:
    left, right = 1, num
    while left <= right:
        mid = (left + right) // 2
        if mid * mid == num:
            return True
        elif mid * mid < num:
            left = mid + 1
        elif mid * mid > num:
            right = mid - 1
    return False

print(binary(121))
print(binary(122))