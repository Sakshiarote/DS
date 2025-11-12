customer_ids = []
customer_salaries = []

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

while True:
    print("\n---- Customer Management Menu ----")
    print("1. Add Customer ID and Salary")
    print("2. Display All Customers")
    print("3. Search Customer ID (Binary Search)")
    print("4. Exit")
    
    choice = int(input("Enter your choice: "))
    
    if choice == 1:
        n = int(input("Enter number of customers: "))
        for i in range(n):
            cid = int(input(f"Enter Customer ID {i+1}: "))
            sal = float(input(f"Enter Salary for Customer {cid}: "))
            customer_ids.append(cid)
            customer_salaries.append(sal)
        print("Customer data added successfully!")
    
    elif choice == 2:
        if not customer_ids:
            print("No customer data available.")
        else:
            print("\nCustomer ID\tSalary")
            for i in range(len(customer_ids)):
                print(f"{customer_ids[i]}\t\t{customer_salaries[i]}")
    
    elif choice == 3:
        if not customer_ids:
            print("No customer data available for search.")
        else:
            search_id = int(input("Enter Customer ID to search: "))
            sorted_ids = sorted(customer_ids)
            found = binary_search(sorted_ids, search_id)
            print("Binary Search: Found" if found else "Binary Search: Not Found")
    
    elif choice == 4:
        print("Exiting program... Goodbye!")
        break
    
    else:
        print("Invalid choice. Please try again.")
