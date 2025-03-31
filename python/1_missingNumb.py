def find_missing_number(nums):
    expected_sum = 5050
    actual_sum = 0
    for i in range(len(nums)):
        actual_sum += nums[i]
    return expected_sum - actual_sum

# Example usage
nums = [i for i in range(1, 101) if i != 50]  # Missing number is 42
missing_number = find_missing_number(nums)
print(f"The missing number is: {missing_number}")
