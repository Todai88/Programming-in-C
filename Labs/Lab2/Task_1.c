#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const char NON_NUMERIC_ERROR [] = "You have entered a non-numeric input.\n\
Please restart and try again!\n";
int MAXLINE = 1000;
int prompt_and_return_value(char prompt[]) {
    // Print prompt
    printf("%s", prompt);

    /*
        Asks user for input.
        If input is non-numerical or non-positive, print error and terminate with
        code 1.
        Else return number.
    */
    int number;
    char break_line;

    if(scanf("%d%c", &number, &break_line) != 2 || break_line != '\n') {
        printf("%s\n", NON_NUMERIC_ERROR);
        exit(1);
    }

    if (number < 0) {
        printf("Sorry, only positive numbers!\n");
        exit(1);
    }

    return number;
}

int sum (int x, int y, int z) {
    return x + y + z;
}

int product (int x, int y) {
    return (x * y);
}

void print_header(int size) {
    int header_length = 2;
    printf(" x   |\t");
    unsigned int index = 1;
    while (index <= size) {
        printf("%d\t", index);
        header_length = header_length + 8;
        index = index + 1;
    }
    index = 0;
    printf("\n");
    while (index < header_length) {
        printf("-");
        index = index + 1;
    }
    printf("\n");
}

void get_index(int number) {
    int nDigits = floor(log10(abs(number))) + 1;
    printf("%d", nDigits);
}

int main() {
    int size = prompt_and_return_value("Please enter the size of the multiplication table.\n");
    int iterator_y = 1;
    int iterator_x = 1;
    print_header(size);
    int index = 0;
    while (iterator_y <= size) {
        iterator_x = 1;
        if (iterator_y < 10) {
            printf(" %d   |\t", iterator_y);
        } else {
            printf(" %d  |\t", iterator_y);
        }

        while (iterator_x <= size) {
            printf("%d\t", iterator_y * iterator_x);
            iterator_x = iterator_x + 1;
        }
        iterator_y = iterator_y + 1;
        printf("\n");
    }

}
