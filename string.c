#include "string.h"

unsigned long strlen(const char *str) {
    unsigned long i = 0;
    while(str[i] != '\0') {
        ++i;
    }
    return i;
}

// Count the number of digits in a number.
int count_digits(int num) {
    int count = 0;
    if(num == 0) {
        return 1;
    }
    while(num > 0){
        count++;
        num = num/10;
    }
    return count;
}

// Convert integer to ASCII.
void iota(int n, char *str) {
    const int digit_count = count_digits(n);
    int index = digit_count - 1;
    if (n == 0 && digit_count == 1) {
        str[0] = '0';
        str[1] = '\0';
    } else{
        while(n != 0) {
            str[index] = (n % 10) + '0';
            index--;
            n = n / 10;
        }
        str[digit_count] = '\0';
    }
}
