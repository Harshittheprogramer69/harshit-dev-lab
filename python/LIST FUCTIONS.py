def isempty(Stack):
    if len(Stack) == 0:
        return True
    else:
        return False
    
def Push(value, Stack):
    if isempty(Stack):
        print("Stack is empty")
    else:
        print("List is not empty. Proceeding to push item.")
    Stack.append(value)

def pop(Stack):
    if isempty(Stack):
        print(f"{Stack} is empty")
    else:
        popped_item = Stack.pop()
        print(f"Popped item {popped_item}")

def top_item(Stack): #to display only top value
    if isempty(Stack):
        print("Stack is empty")
    else:
        top_item = Stack[-1]
        print(f"Top item ==> {top_item}")

def find_element(Value, Stack):
    if isempty(Stack):
        print("Stack is empty")
        print("Nothing to find")
    else:
        index = Stack.index(Value)
        print(f"Item {Value} found at Index:- {index}")

def display(Stack):
    if isempty(Stack):
        print("Stack is empty")
    else:
        print(f"{Stack}")
    
list1 = []
while True:
    choice = int(input(
        "==========Stack Operations==========\n"
        "Following functions you can perfrom:- \n"
        "1.Push element\n"
        "2.Pop element\n"
        "3.Peak top element\n"
        "4.Find element"
        "5.Display stack\n"
        "6.Exit\n"
        "====================================\n"
        "Enter your choice(1-6)==>"
    ))
    if choice == 1:
        Value = input("Enter the data you want to push in stack=>")
        Push(Value, list1)
    elif choice == 2:
        pop(list1)
    elif choice == 3:
        top_item(list1)
    elif choice == 4:
        Value = input("Enter the data you want to find in stack=>")
        find_element(Value, list1)
    elif choice == 5:
        display(list1)
    elif choice == 6:
        print("<<<<<<<<<<<<<<<<EXITING>>>>>>>>>>>>>>>>")
        break
    else:
        print("Wrong Choice")