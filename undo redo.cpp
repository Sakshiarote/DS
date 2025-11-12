undo_stack = []   
redo_stack = []  
document = ""    


def make_change(change):
    global document
    undo_stack.append(document) 
    document += change
    redo_stack.clear() 
    print("Change applied successfully!")


def undo_action():
    global document
    if not undo_stack:
        print("Nothing to undo!")
    else:
        last_state = undo_stack.pop()
        redo_stack.append(document)
        document = last_state
        print("Undo completed!")


def redo_action():
    global document
    if not redo_stack:
        print("Nothing to redo!")
    else:
        last_state = redo_stack.pop()
        undo_stack.append(document)
        document = last_state
        print("Redo completed!")


def display_document():
    print("\n--- Current Document State ---")
    print(document if document else "[Document is empty]")


while True:
    print("\n---- Text Editor Undo/Redo Menu ----")
    print("1. Make a Change")
    print("2. Undo Last Change")
    print("3. Redo Last Change")
    print("4. Display Document State")
    print("5. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        change = input("Enter text to add to the document: ")
        make_change(change)

    elif choice == 2:
        undo_action()

    elif choice == 3:
        redo_action()

    elif choice == 4:
        display_document()

    elif choice == 5:
        print("Exiting... Goodbye!")
        break

    else:
        print("Invalid choice. Please try again.")
