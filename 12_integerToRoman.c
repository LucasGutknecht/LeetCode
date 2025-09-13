char* intToRoman(int num) {
    int units;
    int tens;
    int hundreds;
    int thousands;

    units = num % 10;
    tens = (num / 10) % 10;
    hundreds = (num / 100) % 10;
    thousands = (num / 1000) % 10;

    char *result = (char *)malloc(20 * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < thousands; i++) {
        strcat(result, "M");
    }

    if (hundreds == 9) {
        strcat(result, "CM");
    } else if (hundreds >= 5) {
        strcat(result, "D");
        for (int i = 0; i < hundreds - 5; i++) {
            strcat(result, "C");
        }
    } else if (hundreds == 4) {
        strcat(result, "CD");
    } else {
        for (int i = 0; i < hundreds; i++) {
            strcat(result, "C");
        }
    }

    if (tens == 9) {
        strcat(result, "XC");
    } else if (tens >= 5) {
        strcat(result, "L");
        for (int i = 0; i < tens - 5; i++) {
            strcat(result, "X");
        }
    } else if (tens == 4) {
        strcat(result, "XL");
    } else {
        for (int i = 0; i < tens; i++) {
            strcat(result, "X");
        }
    }

    if (units == 9) {
        strcat(result, "IX");
    } else if (units >= 5) {
        strcat(result, "V");
        for (int i = 0; i < units - 5; i++) {
            strcat(result, "I");
        }
    } else if (units == 4) {
        strcat(result, "IV");
    } else {
        for (int i = 0; i < units; i++) {
            strcat(result, "I");
        }
      }

    free(result);
    return result;
}
