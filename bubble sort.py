def bubble_sort(salary_list):
    n = len(salary_list)
    for i in range(n):
        for j in range(0, n - i - 1):
            if salary_list[j] > salary_list[j + 1]:
                salary_list[j], salary_list[j + 1] = salary_list[j + 1], salary_list[j]
    return salary_list


salaries = []

while True:
    print("\n---- Salary Management Menu ----")
    print("1. Add Salaries")
    print("2. Display All Salaries")
    print("3. Sort Salaries using Bubble Sort")
    print("4. Show Top 5 Salaries")
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
            print("\nAll Salaries:")
            for s in salaries:
                print(s)

    elif choice == 3:
        if not salaries:
            print("No salary data available to sort.")
        else:
            sorted_salaries = bubble_sort(salaries.copy())
            print("Salaries sorted successfully (ascending):")
            print(sorted_salaries)

    elif choice == 4:
        if len(salaries) < 1:
            print("No salary data available.")
        else:
            sorted_salaries = bubble_sort(salaries.copy())
            top5 = sorted_salaries[-5:][::-1]
            print("Top 5 Salaries:")
            for s in top5:
                print(s)

    elif choice == 5:
        print("Exiting program... Goodbye!")
        break

    else:
        print("Invalid choice. Please try again.")
