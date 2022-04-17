def merge_sort(nums):
    if (len(nums) <= 1):return nums

    mid = len(nums) // 2
    L = nums[:mid]
    R = nums[mid:]
    merge_sort(L)
    merge_sort(R)

    i = j= k = 0

    while i < len(L) and j < len(R):
        if L(i) < R[j]:
            nums[k] = L[i]
            i += 1
        else:
            nums[k] = R[j]
            j += 1
        k += 1
    while i < len(L):
        nums[k] = L[i]
        k += 1
        i += 1
    while j < len(R):
        nums[k] = R[j]
        k += 1
        j += 1
