from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        
        for i in range(len(nums)):
            for j in range(len(nums)):
                if i != j and nums[i] == nums[j]:
                    return True
        return False

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:

        nums.sort()
        for i in range(len(nums) - 1):
            if (nums[i] == nums[i + 1]):
                return True
        return False
    
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        
        nmap = {}
        for num in nums:
            if num in nmap:
                return True
            nmap[num] = True
        return False