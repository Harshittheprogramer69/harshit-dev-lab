def isempty(tuple_object):
    if len(tuple_object) == 0:
        return True
    else:
        return False

def push(value, tuple_object):
    if isempty(tuple_object):
        print("Tuple is empty.")
    else:
        return tuple_object
    new_tuple_object += tuple_object + (value,)

def pop(value, tuple_object):
    if isempty(tuple_object):
        print("Tuple is empty.")
    elif value in tuple_object:
        new_tuple_object = ()
        for item in tuple_object:
            if item != value:
                new_tuple_object += (value,)
        print(f"New tuple after poping {value} is {new_tuple_object}")
    else:
        print(f"{value} in tuple doesnt exist.")
        
def peak(value, tuple_object):
    if isempty(tuple_object):
        print("Tuple is empty.")
        print("Nothing to see")
    elif value in tuple_object:
        print(f"{value} index is {tuple_object.index(value)}")
    else:
        print(f"No value {value} exits in tuple.")

def display(tuple_object):
    if isempty(tuple_object):
        print("Tuple is empty.")
    else:
        print(tuple_object)

tuple_object = ("TUPLE", 3, "32", "FSD", 45, "HELLO", "WORLD", 9, "HARSHIT")

while True:
    choice = int(input("Enter your choice:- \n"
                       "1.Push element\n"
                       "2.Pop element\n"
                       "3.Peak element\n"
                       "4.Display element\n"
                       "5.Exit\n"
                       "Enter your choice==>"))
    if choice == 1:
        value = input("Enter value for tuple:- ")
        push(value, tuple_object)
        print(f"Value {value} added to tuple.")
    elif choice == 2:
        value = input("Enter value for tuple:- ").strip().upper()
        pop(value, tuple_object)
    elif choice == 3:
        value = input("Enter the value:- ").strip().upper()
        peak(value, tuple_object)
    elif choice == 4:
        display(tuple_object)
    elif choice == 5:
        print("<<<<<<<<<<<<<<<<EXITING>>>>>>>>>>>>>>>>")
        break
    else:
        print(f"{choice} is invalid. please choose from the above")