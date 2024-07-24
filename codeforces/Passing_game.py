import bisect

def min_time(n, k, x, s):
    speeds = [(i, 1 / s[i]) for i in range(n)]
    speeds.sort(key=lambda x: x[1])
    res = float('inf')
    r = n - 1
    l = 0
    for i in range(n):
        while r > i and x[i] + 1 / s[i] < x[r]:
            r -= 1
        while l < i and x[i] - 1 / s[i] > x[l]:
            l += 1
        for _ in range(i):
            l += 1
            r -= 1
        time = max(1 / s[i] * (x[r] - x[l - 1]), 1 / s[i] * (x[l] - x[r - 1]))
        time += 1 / s[i] * min(abs(x[i] - x[j]), abs(x[i] - x[l]), abs(x[i] - x[r]))
        res = min(res, time)
    return res

def binary_search(l, r, x, s, k):
    if l == r:
        return l
    if r - l == 1:
        return min(l, r)
    m = (l + r) // 2
    if min_time(m, k, x, s) > min_time(m + 1, k, x, s):
        return binary_search(l, m, x, s, k)
    else:
        return binary_search(m, r, x, s, k)

T = int(input())
for _ in range(T):
    n, k = map(int, input().split())
    x = list(map(int, input().split()))
    s = list(map(int, input().split()))
    l = bisect.bisect_left(x, 1)
    r = n - bisect.bisect_right(x, 1)
    res = float('inf')
    for i in range(l, r + 1):
        time = min_time(i, k, x, s)
        res = min(res, time)
    print(res)