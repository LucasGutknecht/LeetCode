#include <stdio.h>
#include <stdlib.h>

int get_value(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char* s) {
    typedef struct
    {
      char key[7];
      int value;
    } roman;

    roman romans[] = {
      {"I", 1},
      {"V", 5},
      {"X", 10},
      {"L", 50},
      {"C", 100},
      {"D", 500},
      {"M", 1000}
    };

    int total = 0;
    int prev_value = 0;
    int current_value = 0;
    for (int i = 0; s[i] != '\0'; i++) {

      current_value = get_value(s[i]);
        if (current_value > prev_value) {
            total += current_value - 2 * prev_value;
        } else {
            total += current_value;
        }
        prev_value = current_value;
    }
    return total;
}
