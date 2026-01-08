def calculate_income(Income, Threshold=90000):
    if Income>=Threshold:
        return "Good_income"
    elif Income>=80000:
        return "Nice_income"
    elif Income>=75000:
        return "Average_income"
    else:
        return "Bad_income"

import pickle

f=open(r"D:\Codes\Files\Employess\Employess.dat","wb+")
employeesdata=[]

Total_employess=int(input("Enter The Number Of Employess You want to Add:- "))

for i in range(1,Total_employess+1):
    name=input("Enter the Name of the Employee:- ")
    age=int(input(f"Enter the age of {name}:- "))
    gender=input(f"Enter the gender of {name}:- ")
    work_in_organisation=input(f"Enter the Work in organisation of {name}:- ")
    salary=int(input(f"Enter the salary of {name}:- "))
    employeesdata.append([name,age,gender,work_in_organisation,salary])

f.seek(0)
pickle.dump(employeesdata, f)

with open(r"D:\Codes\Files\Employees_with_salary_above_75K.txt","w") as file:
    for employee in employeesdata:
        name, age, gender, work_in_organisation, salary = employee
        earnings=calculate_income(salary)
        if earnings=="Good_income" or earnings=="Nice_income" or earnings=="Averagencome":
            file.write(f"Name:- {name} \n")
            file.write(f"Age:- {age} \n")
            file.write(f"Gender:- {gender} \n")
            file.write(f"Work in Organisation:- {work_in_organisation} \n")
            file.write(f"Salary:- {salary} \n")
            file.write("\n")

f.close()

print("The file with employees of salary above 75k is saved now.")
print("Thank you")