/*  Program that will play a Lotto game. The program will allow the user to enter their 6 selected numbers and give them a set of options, each performing a specific requirement.  This program will be modularised and each task should be dealt in a separate function. The program will display a simple menu to the user and each option in the menu will be implemented by calling a separate function.
 
 Author: James McArdle, Date: 03/03/2018, Compiler: Xcode.
 */

//Prototypes
int menu(void);
int* enter_numbers(int*);
void display_numbers(int*);
int* insertion_sort(int[]);
void frequency(int[]);
void display_frequency(void);
void exit_function(int);
void score(int[]);

#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

//Static Arrays used in Functions
static int winning_numbers[7] = {1, 3, 5, 7, 9, 11, 42};
static int frequency_table[42] = {};

int main() {
    
    //Starts Main Menu Function
    menu();
    
    return 0;
    
}

//Main Menu Function
int menu() {
    
    static int lotto_numbers[SIZE];
    float menu_answer = 0;
    char ch;
    int *ptr;
    int *sort;
    int num = 0;
    
    //Points at first element in array and will later be returned from function.
    ptr = lotto_numbers;
    
    //Do.. while loop waits for user to choose menu options.
    do {
        //Main Menu Options
        printf("Main Menu!\n");
        
        printf("1. Enter your 6 lotto numbers (1-42 inclusive).\n");
        
        printf("2. Display your lotto numbers.\n");
        
        printf("3. Sort lotto numbers.(Smallest-Largest)\n");
        
        printf("4. Compare your lotto numbers with Winning numbers!\n");
        
        printf("5. Display the frequency of the numbers entered each round.\n");
        
        printf("6. Exit program\n");
        
        //Menu option choice
        scanf("%f", &menu_answer);
        
        //Error checking for main menu input
        if (menu_answer>6 || menu_answer<1) {
            
            printf("Invalid Input! Try again!\n");
            
        }
        
        //Reads characters in scanf buffer to stop infitie looping when character is entered.
        while((ch = getchar()) != '\n' && ch != -1);
        
        //Switch statement in which the users input will move them into correlating function.
        switch ((int)menu_answer) {
            case 1:
                
                //Pointing at users lotto numbers array.
                ptr = enter_numbers(lotto_numbers);
                
                frequency(lotto_numbers);
                
                break;
                
            case 2:
                
                //Sends pointer and displays users lotto numbers.
                display_numbers(ptr);
                
                break;
                
            case 3:
                
                //Sorting algorithm
                sort = insertion_sort(lotto_numbers);
                
                display_numbers(sort);
                
                break;
                
            case 4:
                
                //Compares user's numbers to winning numbers
                score(lotto_numbers);
                
                break;
                
            case 5:
                
                //Displays frequency table
                display_frequency();
                
                break;
                
            default: {
                
                //Exit function
                exit_function(num);
                
            }
                
        }
        
        
    } while (menu_answer!=6);
    
    exit_function(num);
    
    return 0;
    
}//End menu function.

//Implementing Menu Option 1
int* enter_numbers(int lotto[]) {
    
    int i;
    char ch;
    int user_input;
    
    printf("1. Enter your 6 lotto numbers (1-42 inclusive).\n");
    
    for (i=0; i<SIZE; i++) {
        
        scanf("%d", &user_input);
        
        //Reads characters in scanf buffer to stop infitie looping when character is entered.
        while((ch = getchar()) != '\n' && ch != -1);
        
        //Entering numbers into array
        lotto[i] = user_input;
        
        //Error Checking: (1-42 inclusive)
        if(lotto[i]>42 || lotto[i]<1) {
            
            printf("Invalid input! Lotto numbers must be 1-42 inclusive!\n");
            i--;
            
        }
        
    }
    
    //Returning Array to menu function
    return lotto;
    
}//End enter_numbers function.

//Implementing Menu Option 2
void display_numbers(int *point) {
    
    int i;
    
    for (i=0; i<SIZE; i++) {
        
        printf("%d\n", *(point + i));
        
    }
    
    menu();
    
}

//Implementing Menu Option 3
int* insertion_sort(int lotto[]) {
    
    int i;
    int j;
    int current;
    
    i = j = 0;
    
    for (i=1; i<SIZE; i++) {
        
        current = lotto[i];
        j = i;
        
        while (lotto[j-1] > current) {
            
            lotto[j] = lotto[j-1];
            
            j = j-1;
            
        }
        
        lotto[j] = current;
        
    }
    
    return lotto;

}

//Implementing Menu Option 4
void score(int lotto[]) {
    
    int i;
    int j;
    int counter = 0;
    int bonus = 0;
    
    for (i=0; i<SIZE; i++) {
        
        if (lotto[i] == winning_numbers[i]) {
            
            counter++;
            
        } else {
            
        }
    }
        
    for(j=0; j<SIZE; j++) {
            
        if (lotto[i] == winning_numbers[6]) {
                
            bonus++;
                
        }
            
    }

    switch(counter) {
            
        case 4:
            
            printf("You won a Night Out!\n");
            
            break;
            
        case 5:
            
            printf("You won a Holiday!\n");
            
            break;
        
        case 6:
            
            printf("JACKPOT!\n");
            
            break;
            
        default: {
            
            printf("No Prize!\n");
            break;
            
        }
            
    }
    
    if(bonus == 1) {
        
        if (counter == 3) {
            
            printf("You won a Cinema Ticket\n");
            
        }
        
        if (counter == 4) {
            
            printf("You won a Weekend Away\n");
            
        }
        
        if (counter == 5) {
            
            printf("You won a New Car\n");
            
        }
        
    }

}

//Implementing frequency array
void frequency(int lotto[]) {
    
    int i;
    int j;
    
    for (i=0; i<SIZE; i++) {
        
        j = lotto[i];
        
        frequency_table[j]++;
        
    }
    
}

//Implementing Menu Option 5
void display_frequency(void) {
    
    int i;
    
    for (i=0; i<42; i++) {
        
        if (frequency_table[i] > 0) {
            
            printf("The number %d was entered %d times.\n", i, frequency_table[i]);
            
        }
        
    }
    
}

//Implementing Menu Option 6
void exit_function(int ex) {
    
    printf("Are you sure you want to exit the program? (1 = yes, 0 = no)\n");
    
    scanf("%d", &ex);
    
    if (ex == 1) {
        
        printf("Program ending...\n");
        
        exit(0);
        
    } else if (ex == 0) {
        
        menu();
        
    }
    
}
