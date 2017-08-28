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

int main() {
    int iterations, in_value, max;
    iterations = prompt_and_return_value("How many times should I loop?\n");
    in_value = prompt_and_return_value("What's my initial value?\n");
    max = in_value;

    int count = 0;
    while(count < iterations) {
        in_value = prompt_and_return_value("Please enter a new numerical value\n");
        if(in_value > max) {
            max = in_value;
        }
        count = count + 1;
    }

    printf("The highest value is: %d\n", max);
}
