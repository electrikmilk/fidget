//
// Created by brandon on 8/13/23.
//

#ifndef FIDGET_STRING_H
#define FIDGET_STRING_H

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
void itoa(int num, char *number) {
    const int digit_count = count_digits(num);
    int index = digit_count - 1;
    if (num == 0 && digit_count == 1) {
        number[0] = '0';
        number[1] = '\0';
    } else{
        while(num != 0) {
            number[index] = (num % 10) + '0';
            index--;
            num = num / 10;
        }
        number[digit_count] = '\0';
    }
}

#endif //FIDGET_STRING_H
