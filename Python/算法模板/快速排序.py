n = int(input())
nums = list(map(int, input().split()))

def quick_sort(q, l, r):
    if l < r:
        i, j, x = l - 1, r + 1, q[(l + r) // 2]
        while(i < j):
            while 1:
                i += 1
                if q[i] >= x: break
            while 1:
                j -= 1
                if q[j] <= x: break
            if (i < j): 
            q[i], q[j] = q[j], q[i]
        quick_sort(q, l, j)
        quick_sort(q, j+1, r)

def quick_sort_2(nums):
    if (len(nums) <= 1): return nums

    pivot = nums[len(nums) // 2]
    left = [x for x in nums if x < pivot] # 利用列表推导式生成小于pivot的列表
    mid = [x for x in nums if x == pivot]
    right = [x for x in nums if x > pivot]
    return quick_sort(left) + mid + quick_sort(right)

if __name__ == '__main__':
    nums = quick_sort(nums)
    print(" ".join(list(map(str, nums))))
