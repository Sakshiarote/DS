books = []
borrow_counts = []
members = []

while True:
    print("\n---- Library Borrowing Management Menu ----")
    print("1. Add Book Borrowing Records")
    print("2. Compute Average Books Borrowed by Members")
    print("3. Find Book with Highest and Lowest Borrowings")
    print("4. Count Members Who Haven’t Borrowed Any Book")
    print("5. Display Most Frequently Borrowed Book")
    print("6. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        n = int(input("Enter number of records to add: "))
        for i in range(n):
            member = input(f"\nEnter member name {i+1}: ")
            book = input("Enter book title: ")
            count = int(input("Enter number of times borrowed: "))

            members.append(member)
            books.append(book)
            borrow_counts.append(count)
        print("Records added successfully!")

    elif choice == 2:
        if not borrow_counts:
            print("No records available.")
        else:
            avg = sum(borrow_counts) / len(borrow_counts)
            print(f"Average number of books borrowed: {avg:.2f}")

    elif choice == 3:
        if not books:
            print("No records available.")
        else:
            max_borrow = max(borrow_counts)
            min_borrow = min(borrow_counts)
            max_index = borrow_counts.index(max_borrow)
            min_index = borrow_counts.index(min_borrow)
            print(f"\nMost Borrowed Book: '{books[max_index]}' ({max_borrow} times)")
            print(f"Least Borrowed Book: '{books[min_index]}' ({min_borrow} times)")

    elif choice == 4:
        if not borrow_counts:
            print("No records available.")
        else:
            zero_count = borrow_counts.count(0)
            print(f"Number of members who have not borrowed any book: {zero_count}")

    elif choice == 5:
        if not books:
            print("No records available.")
        else:
            book_freq = {}
            for i in range(len(books)):
                book_freq[books[i]] = book_freq.get(books[i], 0) + borrow_counts[i]

            most_frequent = max(book_freq, key=book_freq.get)
            print(f"Most Frequently Borrowed Book: '{most_frequent}' ({book_freq[most_frequent]} times)")

    elif choice == 6:
        print("Exiting program... Goodbye!")
        break

    else:
        print("Invalid choice. Please try again.")
