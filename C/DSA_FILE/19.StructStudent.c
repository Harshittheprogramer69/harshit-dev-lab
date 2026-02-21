#include <stdio.h>
#include <string.h>

struct Marks {
    int subject_1;
    int subject_2;
    int subject_3;
};

struct Student {
    int student_id;
    char student_name[50];
    char branch[50];
    struct Marks marks;
};

int main() {

    struct Student students[100];
    int student_count = 0;
    int choice;

    while(1) {

        printf("\n1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display All Students\n");
        printf("4. Display Student with Best Mark\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {

            printf("Enter student_id: ");
            scanf("%d", &students[student_count].student_id);

            printf("Enter student_name: ");
            scanf("%s", students[student_count].student_name);

            printf("Enter branch: ");
            scanf("%s", students[student_count].branch);

            printf("Enter marks of 3 subjects: ");
            scanf("%d %d %d",
                  &students[student_count].marks.subject_1,
                  &students[student_count].marks.subject_2,
                  &students[student_count].marks.subject_3);

            student_count++;
        } else if(choice == 2) {

            int delete_id;
            printf("Enter student_id to delete: ");
            scanf("%d", &delete_id);

            int found = 0;

            for(int i = 0; i < student_count; i++) {
                if(students[i].student_id == delete_id) {

                    for(int j = i; j < student_count - 1; j++) {
                        students[j] = students[j + 1];
                    }

                    student_count--;
                    found = 1;
                    break;
                }
            }

            if(found)
                printf("Student deleted successfully\n");
            else
                printf("Student not found\n");
        } else if(choice == 3) {

            if(student_count == 0) {
                printf("No student records available\n");
            }
            else {
                for(int i = 0; i < student_count; i++) {

                    int total =
                        students[i].marks.subject_1 +
                        students[i].marks.subject_2 +
                        students[i].marks.subject_3;

                    printf("\nStudent ID: %d\n", students[i].student_id);
                    printf("Name: %s\n", students[i].student_name);
                    printf("Branch: %s\n", students[i].branch);
                    printf("Marks: %d %d %d\n",
                           students[i].marks.subject_1,
                           students[i].marks.subject_2,
                           students[i].marks.subject_3);
                    printf("Total: %d\n", total);
                }
            }
        } else if(choice == 4) {

            if(student_count == 0) {
                printf("No student records available\n");
            }
            else {

                int best_index = 0;
                int best_total =
                    students[0].marks.subject_1 +
                    students[0].marks.subject_2 +
                    students[0].marks.subject_3;

                for(int i = 1; i < student_count; i++) {

                    int current_total =
                        students[i].marks.subject_1 +
                        students[i].marks.subject_2 +
                        students[i].marks.subject_3;

                    if(current_total > best_total) {
                        best_total = current_total;
                        best_index = i;
                    }
                }

                printf("Student with Best Marks: %s\n",
                       students[best_index].student_name);
                printf("Total Marks: %d\n", best_total);
            }
        } else if(choice == 5) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}