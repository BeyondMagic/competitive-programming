def get_truthy_ranges(s):
    ranges = []
    start = None
    for i in range(len(s)):
        if s[i] == 'T':
            if start is None:
                start = i + 1  # Convert to 1-based index
        else:
            if start is not None:
                end = i  # Current index is 0-based, end in 1-based is i
                ranges.append((start, end))
                start = None
    # Check if the string ends with 'T's
    if start is not None:
        end = len(s)  # 1-based end
        ranges.append((start, end))
    return ranges

def is_in_truthy_ranges(x, ranges):
    low = 0
    high = len(ranges) - 1
    while low <= high:
        mid = (low + high) // 2
        s, e = ranges[mid]
        if s > x:
            high = mid - 1
        elif e < x:
            low = mid + 1
        else:
            return True
    return False

# Example usage:
input_string = "FFFFFTTTFFTTFTTTFFFFFFFFFFFFFFFTTTTTTTTTTTTTTTTTFFF"
truthy_ranges = get_truthy_ranges(input_string)
print(truthy_ranges)  # Output: [(6, 8), (11, 12), (14, 16)]

position_3 = 3
position_15 = 40
print(is_in_truthy_ranges(position_3, truthy_ranges))  # Output: False
print(is_in_truthy_ranges(position_15, truthy_ranges))  # Output: True
