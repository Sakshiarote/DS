customer_ids = []

def linear_search(customer_list, target_id):
    for cid in customer_list:
        if cid == target_id:
            return True
    return False

while True:
    print("\n---- E-Commerce Customer Account Menu ----")
    print("1. Add Customer Account IDs")
    print("2. Display All Customer Account IDs")
    print("3. Search for a Customer ID (Linear Search)")
    print("4. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        n = int(input("Enter number of customers to add: "))
        for i in range(n):
            cid = int(input(f"Enter Customer ID {i+1}: "))
            customer_ids.append(cid)
        print("Customer IDs added successfully!")

    elif choice == 2:
        if not customer_ids:
            print("No customer IDs available.")
        else:
            print("\nCustomer Account IDs:")
            for cid in customer_ids:
                print(cid)

    elif choice == 3:
        if not customer_ids:
            print("No customer data available for search.")
        else:
            search_id = int(input("Enter Customer ID to search: "))
            found = linear_search(customer_ids, search_id)
            print("Linear Search: Found" if found else "Linear Search: Not Found")

    elif choice == 4:
        print("Exiting program... Goodbye!")
        break

    else:
        print("Invalid choice. Please try again.")
