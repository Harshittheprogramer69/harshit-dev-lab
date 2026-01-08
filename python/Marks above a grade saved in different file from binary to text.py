def calculate_average(average_marks, threshold=90):
    if average_marks>=threshold:
        return "A"
    elif average_marks>=80:
        return "B"
    elif average_marks>=70:
        return "C"
    elif average_marks>=60:
        return "D"
    elif average_marks>=50:
        return "D-"
    else:
        return "Fail"

import pickle

f=open(r"D:\Codes\Files\Students\Students.dat","wb+")
studentsdata=[]

Total_students=int(input("Enter the number of students you want to add:- "))
Total_subjects=int(input("Enter the number of subjects you want to add:- "))

for i in range(1,Total_students+1):
    name=input("Enter the Name of the student:- ")
    age=int(input(f"Enter the Age of {name}:- "))
    gender=input(f"Enter the Gender of {name}:- ")
    Father_name=input(f"Enter the Father's name of {name}:- ")
    Mother_name=input(f"Enter the Mother's name of {name}:- ")
    marks=[]
    for j in range(1,Total_subjects+1):
        subject=float(input(f"Enter the marks of {name} in subject {j}:- "))
        marks.append(subject)
    studentsdata.append([name,age,gender,Father_name,Mother_name,marks])

f.seek(0)
pickle.dump(studentsdata, f)

with open(r"D:\Codes\Files\Students\Students_with_grade_above_A.txt","w") as file:
    for student in studentsdata:
        avg_marks=sum(student[5])/len(student[5])
        grade=calculate_average(avg_marks)
        if grade=="A":
            file.write(f"Name:- {student[0]}\n")
            file.write(f"Age:- {student[1]}\n")
            file.write(f"Gender:- {student[2]}\n")
            file.write(f"Father's Name:- {student[3]}\n")
            file.write(f"Mother's Name:- {student[4]}\n")
            file.write(f"Subjects and Marks:- \n")
            for i, subject_mark in enumerate(student[5], start=1):
                file.write(f"\tSubject {i}:- {subject_mark}\n")
            file.write("\n")

f.close()
