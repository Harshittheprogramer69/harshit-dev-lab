def isempty(dictionary):
    if len(dictionary) == 0:
        return True
    else:
        return False

def Push(key, value, dictionary):
    if isempty(dictionary):
        print(f"{dictionary} is empty.")
    else:
        print(f"{dictionary} is not empty.")
    print(f"Adding {key} {value} to dictionary.")
    dictionary[key] = value
    print(f"Added {key} value ==>{value}")

def pop(key, dictionary):
    if isempty(dictionary):
        print(f"{dictionary} is empty.")
    elif key in dictionary:
        print(f"Removing {key} item from dictionary")
        removed_item = dictionary.pop(key)
        print(f"{key} item removed from dictionary")
    else:
        print(f"Key {key} not found.")

def peak(value, dictionary):
    if isempty(dictionary):
        print(f"{dictionary} is empty.")
    elif value in dictionary.values():
        for k,v in dictionary.items():
            if v == value:
                print(f"Found {value} at key {k} in Dictionray")
    else:
        print(f"No {value} exists in dictionary.")

def display(dictionary):
    if isempty(dictionary):
        print("Dictionary is empty.")
    else:
        print(dictionary)

dictionary = {1: 'APPLE', 2: 'BANANA', 3: 'CHERRY', 4: 'DATE', 5: 'ELDERBERRY', 6: 'FIG', 7: 'GRAPE', 8: 'HONEYDEW'}

while True:
    choice = int(input("Enter your choice:- \n"
                       "1.Push element\n"
                       "2.Pop element\n"
                       "3.Peak element\n"
                       "4.Display element\n"
                       "5.Exit\n"
                       "Enter your choice==>"))
    
    if choice == 1:
        key = int(input("Enter the key:- "))
        value = input(f"Enter value for {key}:- ")
        Push(key, value, dictionary)
    elif choice == 2:
        key = int(input("Enter the key:- "))
        pop(key, dictionary)
    elif choice == 3:
        value = input("Enter the value:- ").strip().upper()
        peak(value, dictionary)
    elif choice == 4:
        display(dictionary)
    elif choice == 5:
        print("<<<<<<<<<<<<<<<<EXITING>>>>>>>>>>>>>>>>")
        break
    else:
        print(f"{choice} is invalid. please choose from the above")