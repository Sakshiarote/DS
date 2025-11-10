# Library Borrow Manager

library_data = {
    "M001": ["Book A", "Book B"],
    "M002": ["Book C"],
    "M003": [],
    "M004": ["Book A", "Book A"],
    "M005": [],
    "M006": ["Book B", "Book D"]
}

# 1. Average number of books borrowed
total_books = sum(len(b) for b in library_data.values())
average = total_books / len(library_data)
print("Average books borrowed:", average)

# 2. Most & least borrowed books
all_books = [book for books in library_data.values() for book in books]

book_counts = {}
for book in all_books:
    book_counts[book] = book_counts.get(book, 0) + 1

most_borrowed = max(book_counts, key=book_counts.get)
least_borrowed = min(book_counts, key=book_counts.get)

print("Most borrowed book:", most_borrowed)
print("Least borrowed book:", least_borrowed)

# 3. Members with 0 borrowings
zero_borrowers = sum(1 for books in library_data.values() if len(books) == 0)
print("Members with 0 borrowings:", zero_borrowers)

# 4. Mode (same as most borrowed)
print("Most frequently borrowed book (mode):", most_borrowed)