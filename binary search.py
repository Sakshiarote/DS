customer_ids = [102, 205, 150, 123, 301, 110, 175]
def binary_search(sorted_list, target_id):
    low = 0
    high = len(sorted_list) - 1

    while low <= high:
        mid = (low + high) // 2
        if sorted_list[mid] == target_id:
            return True
        elif sorted_list[mid] < target_id:
            low = mid + 1
        else:                                                                                                               
            high = mid - 1
    return False
102
search_id = int(input("Enter Customer ID to search: "))
sorted_ids = sorted(customer_ids)
found_binary = binary_search(sorted_ids, search_id)
print("Binary Search: Found" if found_binary else "Binary Search: Not Found")
