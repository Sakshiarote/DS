def selection_sort(salary_list):
    n = len(salary_list)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if salary_list[j] < salary_list[min_index]:
                min_index = j
        salary_list[i], salary_list[min_index] = salary_list[min_index], salary_list[i]
    return salary_list


salaries = []

while True:
    print("\n---- Employee Salary Management Menu ----")
    print("1. Add Employee Salaries")
    print("2. Display All Salaries")
    print("3. Sort Salaries using Selection Sort")
    print("4. Display Top 5 Highest Salaries")
    print("5. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        n = int(input("Enter number of employees: "))
        for i in range(n):
            sal = float(input(f"Enter salary of employee {i+1}: "))
            salaries.append(sal)
        print("Salaries added successfully!")

    elif choice == 2:
        if not salaries:
            print("No salary data available.")
        else:
            print("\nAll Employee Salaries:")
            for s in salaries:
                print(s)

    elif choice == 3:
        if not salaries:
            print("No salary data available to sort.")
        else:
            sorted_salaries = selection_sort(salaries.copy())
            print("\nSalaries sorted in ascending order:")
            print(sorted_salaries)

    elif choice == 4:
        if not salaries:
            print("No salary data available.")
        else:
            sorted_salaries = selection_sort(salaries.copy())
            top5 = sorted_salaries[-5:][::-1]
            print("\nTop 5 Highest Salaries:")
            for s in top5:
                print(s)

    elif choice == 5:
        print("Exiting program... Goodbye!")
        break

    else:
        print("Invalid choice. Please try again.")
