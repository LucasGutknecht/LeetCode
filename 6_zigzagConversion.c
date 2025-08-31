#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

float initialGuess(float x) {
    if(x >= 1.0) {
        int power = 0;
        while(pow(2, power) < x) {
            power++;
        }
        return 1.0 / pow(2, power);
    } else {
        return 1.0;
    }
}

float findReciprocal(float x) {
    float guess = initialGuess(x);
    float new_guess;
    float error = 0.00001;

    do {
        new_guess = guess * (2 - x * guess);
        if(fabs(new_guess - guess) < error) {
            break;
        }
        guess = new_guess;
    } while(1);

    return new_guess;
}

typedef struct {
    int quotient;
    int remainder;
} DivisionResult;

DivisionResult mainDivision(float dividend, float divisor) {
    DivisionResult result;
    float reciprocalB = findReciprocal(divisor);
    float decimalResult = dividend * reciprocalB;
    result.quotient = (int)floor(decimalResult);
    result.remainder = (int)(dividend - (divisor * result.quotient));
    return result;
}

int calculatePeriod(int numRows) {
    if (numRows <= 1) return 1;
    return 2 * numRows - 2;
}

int getRowForPosition(int pos, int numRows) {
    if (numRows <= 1) return 0;

    int period = calculatePeriod(numRows);
    DivisionResult divResult = mainDivision(pos, period);
    int posInPeriod = divResult.remainder;

    if (posInPeriod < numRows) {
        return posInPeriod;
    }
    else {
        return numRows - 2 - (posInPeriod - numRows);
    }
}

char* convert(char* s, int numRows) {
    if (numRows <= 1 || numRows >= strlen(s)) {
        char* result = (char*)malloc((strlen(s) + 1) * sizeof(char));
        strcpy(result, s);
        return result;
    }

    int len = strlen(s);
    char* result = (char*)calloc(len + 1, sizeof(char));
    int resultPos = 0;

    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* rowSizes = (int*)calloc(numRows, sizeof(int));
    int* rowCapacities = (int*)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++) {
        rowCapacities[i] = len / numRows + 2;
        rows[i] = (char*)calloc(rowCapacities[i], sizeof(char));
    }

    for (int i = 0; i < len; i++) {
        int row = getRowForPosition(i, numRows);

        if (rowSizes[row] >= rowCapacities[row] - 1) {
            rowCapacities[row] *= 2;
            rows[row] = (char*)realloc(rows[row], rowCapacities[row] * sizeof(char));
        }

        rows[row][rowSizes[row]++] = s[i];
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < rowSizes[i]; j++) {
            result[resultPos++] = rows[i][j];
        }
    }

    result[resultPos] = '\0';

    for (int i = 0; i < numRows; i++) {
        free(rows[i]);
    }
    free(rows);
    free(rowSizes);
    free(rowCapacities);

    return result;
}
