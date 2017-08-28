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
    int number;
    char break_line;

    if(scanf("%d%c", &number, &break_line) != 2 || break_line != '\n') {
        printf("%s\n", NON_NUMERIC_ERROR);
        exit(1);
    }
    return number;
}

int sum (int x, int y, int z) {
    return x + y + z;
}

int product (int x, int y, int z) {
    return (x * y) * z;
}
int main() {
    int x = prompt_and_return_value("Please give X a non-decimal numerical value.\n");
    int y = prompt_and_return_value("Please give Y a non-decimal numerical value.\n");
    int z = prompt_and_return_value("Please give Z a non-decimal numerical value.\n");

    printf("The  SUM of x + y + z is: %d\n", sum(x, y, z));
    printf("The PROD of x + y + z is: %d\n", product(x, y, z));
}
