#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const char NON_NUMERIC_ERROR [] = "You have entered a non-numeric input.\n\
Please restart and try again!\n";

int prompt_and_return_value(char prompt[]) {
    // Print prompt
    printf("%s", prompt);

    /*
        Asks user for input.
        If input is non-numerical, print error and terminate with
        code 1.
        Else return number.
    */
    float number;
    char break_line;

    if(!scanf("%f", &number)) {
        printf("%s\n", NON_NUMERIC_ERROR);
        exit(1);
    }
    return round(number);
}

void divisable_by(int *number, int divisor, int *change) {
    if (*number >= divisor && *number != 0) {
       *change = (*number / divisor);
       *number = *number - (*change * divisor);
    }
}

int main() {
    int cost, pay, difference, change, count = 0;
    cost = round(prompt_and_return_value("Cost?\n"));
    pay = round(prompt_and_return_value("What are you paying?\n"));
    difference = pay - cost;
    if (cost > pay) {
        printf("You haven't got enough money to buy that!\n");
        exit(1);
    }
    printf("------------------\n");
    for (unsigned int divisor = 10; divisor >= 1; divisor = round(divisor / 2)){
        change = 0;
        divisable_by(&difference, divisor, &change);
        count = count + change;
        printf("%d \t:\t %d\n", divisor, change);
    }
    printf("------------------\n");
    printf("Total\t:\t %d\n", count);
}

