#include <stdio.h>

struct Account {
    int accountNumber;
    float balance;
};

int main() {
    FILE *file;
    struct Account account;
    int searchAccount, found = 0;
    float newBalance;
    long position;
    
    file = fopen("accounts.dat", "r+b");
    if (file == NULL) {
        file = fopen("accounts.dat", "w+b");
        if (file == NULL) {
            printf("Error creating file\n");
            return 1;
        }
        
        printf("Creating sample accounts...\n");
        account.accountNumber = 1001;
        account.balance = 5000.00;
        fwrite(&account, sizeof(account), 1, file);
        
        account.accountNumber = 1002;
        account.balance = 7500.00;
        fwrite(&account, sizeof(account), 1, file);
        
        account.accountNumber = 1003;
        account.balance = 3200.00;
        fwrite(&account, sizeof(account), 1, file);
    }
    
    printf("Enter account number to update: ");
    scanf("%d", &searchAccount);
    
    rewind(file);
    
    while (fread(&account, sizeof(account), 1, file)) {
        if (account.accountNumber == searchAccount) {
            found = 1;
            printf("Current balance: %.2f\n", account.balance);
            printf("Enter new balance: ");
            scanf("%f", &newBalance);
            
            position = ftell(file) - sizeof(account);
            fseek(file, position, SEEK_SET);
            
            account.balance = newBalance;
            fwrite(&account, sizeof(account), 1, file);
            
            printf("Balance updated successfully\n");
            break;
        }
    }
    
    if (!found) {
        printf("Account not found\n");
    }
    
    fclose(file);
    return 0;
}
