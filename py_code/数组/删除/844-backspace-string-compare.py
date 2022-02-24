# 给定s和t两个字符串，当它们分别被输入到空白的文本编辑器后，
# 如果两者相等，返回true。#代表退格字符。
# 注意：如果对空文本输入退格字符，文本继续为空。
from queue import LifoQueue


def double_pointer_failed(s: str, t: str) -> bool:
    s_quick, s_slow = len(s) - 1, len(s) - 1
    t_quick, t_slow = len(t) - 1, len(t) - 1
    while 1:
        # 处理#号
        while s_slow >= 0 and s[s_slow] == '#':
            s_slow -= 1
            s_quick -= 2
        s_slow = s_quick

        while t_slow >= 0 and t[t_slow] == '#':
            t_slow -= 1
            t_quick -= 2
        t_slow = t_quick

        # 两个字符串都扫描完毕
        if s_quick < 0 and t_quick < 0:
            return True
        # s扫描完毕，检查t中的退格符
        elif s_quick < 0:
            while t[t_slow] == '#':
                t_slow -= 1
                t_quick -= 2
            if t_quick < 0:
                return True
            else:
                return False
        # t扫描完毕，检查s中的退格符
        elif t_quick < 0:
            while s[s_slow] == '#':
                s_slow -= 1
                s_quick -= 2
            if s_quick < 0:
                return True
            else:
                return False
        # 都没有扫描完毕，比较字符
        else:
            if s[s_quick] != t[t_quick]:
                return False
            # 指针前移
            elif s[s_quick] == t[t_quick]:
                s_slow -= 1
                s_quick -= 1
                t_quick -= 1
                t_slow -= 1


def stack(s: str, t: str) -> bool:
    s_q = scan(s)
    t_q = scan(t)
    if s_q.qsize() == t_q.qsize():
        while not s_q.empty():
            if s_q.get() != t_q.get():
                return False
        return True
    else:
        return False


def scan(s: str) -> LifoQueue:
    q = LifoQueue()
    for i in s:
        # if i == '#' and not q.empty()
        # else:
        # bug exists
        if i == '#':
            if not q.empty():
                q.get()
        else:
            q.put(i)
    return q


def double_pointer(s: str, t: str) -> bool:
    pointer_s, pointer_t = len(s) - 1, len(t) - 1
    skip_s, skip_t = 0, 0  # 退格数目
    while pointer_s >= 0 or pointer_t >= 0:
        # 扫描退格符
        while pointer_s >= 0:
            # 退格，退格数++，指针--
            if s[pointer_s] == '#':
                skip_s += 1
                pointer_s -= 1
            else:
                # 一般字符，需要退格
                if skip_s:
                    skip_s -= 1
                    pointer_s -= 1
                # 一般字符，不退格
                else:
                    break

        # 扫描退格符
        while pointer_t >= 0:
            # 退格，退格数++，指针--
            if t[pointer_t] == '#':
                skip_t += 1
                pointer_t -= 1
            else:
                # 一般字符，需要退格
                if skip_t:
                    skip_t -= 1
                    pointer_t -= 1
                # 一般字符，不退格
                else:
                    break
        if pointer_s >= 0 and pointer_t >= 0:
            if s[pointer_s] != t[pointer_t]:
                return False
            else:
                pointer_s -= 1
                pointer_t -= 1
        else:
            return False

    return True

res = double_pointer_failed("bxj##tw", "bxo#j##tw")
print(res)

res = stack("bxj##tw", "bxo#j##tw")
print(res)

res = double_pointer("bxj##tw", "bxo#j##tw")
print(res)