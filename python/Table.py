def table(x: int):
    x: int
    result = []
    for i in range(11):
        A = f"{x} X {i} = {x*i}"
        result.append([A])
    return result

while True:
    number = int(input("Enter number for table: "))

    TAB = table(number)
    for i in TAB:
        print(i)

    while True:
        AB = input("Do you wish to continue?\n"
                    "1. Yes\n"
                    "2. No\n"
                    "=====> ").strip()

        if AB == "2":
            print("Exiting.........")
            break  
        
        elif AB == "1":
            break  
        
        else:
            print("Please choose 1 or 2 only.....")
            continue  

    if AB == "2":
        break  
