def check(x):
    return False

def bsearch_1(l, r):
    while(l < r):
        mid = ( l + r ) / 2
        if (check(mid)): r = mid
        else: l = mid + 1
    return l

def bsearch_2(l, r):
    while(l < r):
        mid = (l + r + 1) / 2
        if (check(mid)): l = mid
        else: r = mid - 1
    return l
