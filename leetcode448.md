# 448. Find All Numbers Disappeared in an Array

## Problem Description

Given an array `nums` of `n` integers where `nums[i]` is in the range `[1, n]`, return an array of all the integers in the range `[1, n]` that do not appear in `nums`.

---

## Examples

### Example 1:
- **Input:** `nums = [4,3,2,7,8,2,3,1]`
- **Output:** `[5,6]`
- **Explanation:** The numbers 5 and 6 do not appear in the array.

### Example 2:
- **Input:** `nums = [1,1]`
- **Output:** `[2]`
- **Explanation:** The number 2 does not appear in the array.

---

## Constraints

- `n == nums.length`
- `1 <= n <= 10^5`
- `1 <= nums[i] <= n`

---

## Follow up
Could you do it without extra space and in `O(n)` runtime? You may assume the returned list does not count as extra space.
