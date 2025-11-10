customer_ids = [102, 205, 150, 123, 301, 110, 175]

def linear_search(customer_list, target_id):
    for i in range(len(customer_list)):
        if customer_list[i] == target_id:
            return True
    return False

search_id = int(input("Enter Customer ID to search: "))
found_linear = linear_search(customer_ids, search_id)
print("Linear Search: Found" if found_linear else "Linear Search: Not Found")