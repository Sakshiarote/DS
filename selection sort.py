salaries = [45000.0, 38000.5, 52000.75, 61000.0, 47000.0, 70000.0, 56000.0, 49000.5]

def selection_sort(salary_list):
    n = len(salary_list)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if salary_list[j] < salary_list[min_index]:
                min_index = j
        salary_list[i], salary_list[min_index] = salary_list[min_index], salary_list[i]
    return salary_list
sorted_salaries_selection = selection_sort(salaries.copy())
print("Top 5 salaries (Selection Sort):", sorted_salaries_selection[-5:][::-1])

