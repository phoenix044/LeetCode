def check(x):
    return False

def bsearch(l, r):
    while(l < r):
        mid = (l + r) / 2
        if(check(mid)): r = mid
        else: l = mid
    return l