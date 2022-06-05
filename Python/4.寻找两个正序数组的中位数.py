#
# @lc app=leetcode.cn id=4 lang=python3
#
# [4] 寻找两个正序数组的中位数
#

# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums3 = nums1 + nums2
        nums3.sort()
        l = len(nums3)
        index = int(l/2)
        if l % 2 == 1:
            return nums3[index]
        else:
            return (nums3[index-1] + nums3[index]) / 2

# @lc code=end

