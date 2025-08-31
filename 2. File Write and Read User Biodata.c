#include <stdio.h>

struct Person {
    char name[50];
    int age;
    char email[50];
    char phone[15];
};

int main() {
    struct Person person;
    FILE *file;
    int choice;
    
    printf("1. Write biodata to file\n");
    printf("2. Read biodata from file\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        file = fopen("biodata.txt", "w");
        if (file == NULL) {
            printf("Error opening file\n");
            return 1;
        }
        
        printf("Enter name: ");
        scanf("%s", person.name);
        printf("Enter age: ");
        scanf("%d", &person.age);
        printf("Enter email: ");
        scanf("%s", person.email);
        printf("Enter phone: ");
        scanf("%s", person.phone);
        
        fprintf(file, "%s %d %s %s\n", person.name, person.age, person.email, person.phone);
        fclose(file);
        printf("Biodata saved to file\n");
        
    } else if (choice == 2) {
        file = fopen("biodata.txt", "r");
        if (file == NULL) {
            printf("Error opening file\n");
            return 1;
        }
        
        if (fscanf(file, "%s %d %s %s", person.name, &person.age, person.email, person.phone) == 4) {
            printf("\nBiodata from file:\n");
            printf("Name: %s\n", person.name);
            printf("Age: %d\n", person.age);
            printf("Email: %s\n", person.email);
            printf("Phone: %s\n", person.phone);
        } else {
            printf("No data found in file\n");
        }
        
        fclose(file);
    } else {
        printf("Invalid choice\n");
    }
    
    return 0;
}
