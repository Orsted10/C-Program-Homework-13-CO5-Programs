#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

void addStudent() {
    FILE *file;
    struct Student student;
    
    file = fopen("students.dat", "ab");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    
    printf("Enter student ID: ");
    scanf("%d", &student.id);
    printf("Enter student name: ");
    scanf("%s", student.name);
    printf("Enter marks: ");
    scanf("%f", &student.marks);
    
    fwrite(&student, sizeof(student), 1, file);
    fclose(file);
    printf("Student added successfully\n");
}

void searchStudent() {
    FILE *file;
    struct Student student;
    int searchId, found = 0;
    
    file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("No student records found\n");
        return;
    }
    
    printf("Enter student ID to search: ");
    scanf("%d", &searchId);
    
    while (fread(&student, sizeof(student), 1, file)) {
        if (student.id == searchId) {
            found = 1;
            printf("Student found:\n");
            printf("ID: %d\n", student.id);
            printf("Name: %s\n", student.name);
            printf("Marks: %.2f\n", student.marks);
            break;
        }
    }
    
    if (!found) {
        printf("Student not found\n");
    }
    
    fclose(file);
}

void deleteStudent() {
    FILE *file, *temp;
    struct Student student;
    int deleteId, found = 0;
    
    file = fopen("students.dat", "rb");
    temp = fopen("temp.dat", "wb");
    
    if (file == NULL) {
        printf("No student records found\n");
        return;
    }
    
    printf("Enter student ID to delete: ");
    scanf("%d", &deleteId);
    
    while (fread(&student, sizeof(student), 1, file)) {
        if (student.id != deleteId) {
            fwrite(&student, sizeof(student), 1, temp);
        } else {
            found = 1;
        }
    }
    
    fclose(file);
    fclose(temp);
    
    remove("students.dat");
    rename("temp.dat", "students.dat");
    
    if (found) {
        printf("Student deleted successfully\n");
    } else {
        printf("Student not found\n");
    }
}

void displayAllStudents() {
    FILE *file;
    struct Student student;
    
    file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("No student records found\n");
        return;
    }
    
    printf("\nAll Students:\n");
    printf("ID\tName\t\tMarks\n");
    printf("----------------------------\n");
    
    while (fread(&student, sizeof(student), 1, file)) {
        printf("%d\t%s\t\t%.2f\n", student.id, student.name, student.marks);
    }
    
    fclose(file);
}

int main() {
    int choice;
    
    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Delete Student\n");
        printf("4. Display All Students\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                searchStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                displayAllStudents();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
