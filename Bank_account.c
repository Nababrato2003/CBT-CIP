#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 200

typedef struct {
    int accountNumber;
    char accountHolderName[40];
    char accountType[30]; // "Savings" or "Fixed Deposit"
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int acc_Count = 0;

// Function to create a new account
void Account_creation() {
    if (acc_Count >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Maximum limit reached.\n");
        return;
    }

    printf("\n New Account creation \n");
    printf("Enter the name of account holder:- ");
    getchar(); // Clear the newline character
    fgets(accounts[acc_Count].accountHolderName, 50, stdin);
    accounts[acc_Count].accountHolderName[strcspn(accounts[acc_Count].accountHolderName, "\n")] = '\0';

    printf("Enter account type (Savings/Fixed):- ");
    scanf("%s", accounts[acc_Count].accountType);

    printf("Enter Initial Deposit Amount: ");
    scanf("%f", &accounts[acc_Count].balance);

    accounts[acc_Count].accountNumber = 100 + acc_Count;
    printf("Account created successfully! Account Number: %d\n", accounts[acc_Count].accountNumber);
    acc_Count++;
}

// Function to find an account by account number
int AccountFind(int accountNum) {
    for (int i = 0; i < acc_Count; i++) {
        if (accounts[i].accountNumber == accountNum) {
            return i;
        }
    }
    return -1; // Account not found
}

// Function to deposit money
void deposit() {
    int accountNumber;
    float amount;

    printf("\n Deposition of money\n");
    printf("Enter  the account number : ");
    scanf("%d", &accountNumber);

    int index = AccountFind(accountNumber);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid deposit amount!\n");
        return;
    }

    accounts[index].balance += amount;
    printf("Deposit is successful, updated balance is : %.2f\n", accounts[index].balance);
}

// Function to withdraw money
void withdraw() {
    int accountNumber;
    float amount;

    printf("\nWithdrawing  money \n");
    printf("Enter the  account number: ");
    scanf("%d", &accountNumber);

    int index = AccountFind(accountNumber);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0 || amount > accounts[index].balance) {
        printf("Invalid withdrawal amount!\n");
        return;
    }

    accounts[index].balance -= amount;
    printf("Withdrawal completion , now the updated balance is : %.2f\n", accounts[index].balance);
}

// Function to check balance
void checkBalance() {
    int accountNumber;

    printf("\n Checking balance in account  \n");
    printf("Enter  the account number: ");
    scanf("%d", &accountNumber);

    int index = AccountFind(accountNumber);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Account Holder name : %s\n", accounts[index].accountHolderName);
    printf("Account Type : %s\n", accounts[index].accountType);
    printf("Current Balance in account : %.2f\n", accounts[index].balance);
}

// Function to calculate interest
void calculateInterest() {
    int accountNumber;
    float rate, years;

    printf("\nCalculate interest\n");
    printf("Enter the account number: ");
    scanf("%d", &accountNumber);

    int index = AccountFind(accountNumber);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    if (strcmp(accounts[index].accountType, "Savings") == 0) {
        rate = 5; 
    } else if (strcmp(accounts[index].accountType, "Fixed Deposit") == 0) {
        rate = 7.5;
    } else {
        printf("Account type is unknown,  cannot calculate interest!.\n");
        return;
    }

    printf("Enter the number of years: ");
    scanf("%f", &years);

    float interest = accounts[index].balance * (rate / 100) * years;
    printf("Interest for %.2f years at %.2f%%: %.2f\n", years, rate, interest);
}

int main() {
    int choice;

    while (1) {
        printf("\n Bank Account Management System \n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n"); 
        printf("4. Check Balance\n");
        printf("5. Calculate Interest\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Account_creation();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                calculateInterest();
                break;
            case 6:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
