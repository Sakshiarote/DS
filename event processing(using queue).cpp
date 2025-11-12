from collections import deque

event_queue = deque()  

def add_event(event):
    event_queue.append(event)
    print(f"Event '{event}' added successfully!")

def process_event():
    if not event_queue:
        print("No events to process!")
    else:
        event = event_queue.popleft() 
        print(f"Processed event: '{event}'")

def display_pending_events():
    if not event_queue:
        print("No pending events in the queue.")
    else:
        print("\n--- Pending Events ---")
        for i, event in enumerate(event_queue, start=1):
            print(f"{i}. {event}")

def cancel_event(event_name):
    if event_name in event_queue:
        event_queue.remove(event_name)
        print(f"Event '{event_name}' canceled successfully!")
    else:
        print(f"Event '{event_name}' not found in queue.")


# Menu-driven system
while True:
    print("\n---- Real-Time Event Processing Menu ----")
    print("1. Add an Event")
    print("2. Process Next Event")
    print("3. Display Pending Events")
    print("4. Cancel an Event")
    print("5. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        event = input("Enter event name to add: ")
        add_event(event)

    elif choice == 2:
        process_event()

    elif choice == 3:
        display_pending_events()

    elif choice == 4:
        event_name = input("Enter event name to cancel: ")
        cancel_event(event_name)

    elif choice == 5:
        print("Exiting system... Goodbye!")
        break

    else:
        print("Invalid choice. Please try again.")
