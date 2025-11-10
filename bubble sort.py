salaries = [45000.0, 38000.5, 52000.75, 61000.0, 47000.0, 70000.0, 56000.0, 49000.5]
def bubble_sort(salary_list):
    n = len(salary_list)
    for i in range(n):
        for j in range(0, n - i - 1):
            if salary_list[j] > salary_list[j + 1]:
                salary_list[j], salary_list[j + 1] = salary_list[j + 1], salary_list[j]
    return salary_list

sorted_salaries_bubble = bubble_sort(salaries.copy())
print("Top 5 salaries (Bubble Sort):", sorted_salaries_bubble[-5:][::-1])
