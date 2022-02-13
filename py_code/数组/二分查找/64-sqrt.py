# 给你一个非负整数 x ，计算并返回x的 算术平方根 。
# 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
# 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

# 二分查找
# 在[0,x]之间找到i，使得i*i<=x，且这样的i最大
# [0,x]即为排序好的数组
def binary(x: int) -> int:
    left, right, res = 0, x, 0
    while left <= right:
        mid = (left + right) // 2
        if mid * mid <= x:
            res = mid
            left = mid + 1
        else:
            right = mid - 1
    return res


# 牛顿法求解平方根
# 对于函数f(x) = x^2 - a, 不断用切线逼近，找到零点
def Newton(a: int) -> int:
    # 这个要有，因为后面有/x0，可能出现ZeroDivide
    if a == 0:
        return 0

    x0 = a
    while 1:
        x1 = 0.5 * (x0 + 1.0 * a / x0)
        if abs(x1 - x0) < 1e-7:
            return int(x1)
        else:
            x0 = x1


res = binary(1)
print(res)

res = Newton(0)
print(res)
