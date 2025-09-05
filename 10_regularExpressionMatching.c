#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isMatch(char* s, char* p) {
    regex_t reegex;
    if ((!strchr(p, '*') && !strchr(p, '.')) && (strcmp(s, p) != 0)) {
        return false;
    }
    size_t length = strlen(p);
    int value;

    char* modified_p = malloc(length + 3);
    strcpy(modified_p, "^");
    strcat(modified_p, p);
    strcat(modified_p, "$");

    for(int i = 1; i < length + 1; i++){
        if(modified_p[i] == '*' && i == 1){
            free(modified_p);
            return false;
        } else if (modified_p[i] == '*'){
            modified_p[i] = '*';
        } else if (modified_p[i] == '.'){
            modified_p[i] = '.';
        } else {
            modified_p[i] = modified_p[i];
        }
    }

    if(strchr(modified_p, '*') == NULL){
        value = regcomp(&reegex, modified_p, 0);
    } else {
        value = regcomp(&reegex, modified_p, REG_EXTENDED);
    }

    if(value != 0) {
        free(modified_p);
        return false;
    }

    value = regexec(&reegex, s, 0, NULL, 0);
    regfree(&reegex);
    free(modified_p);
    return (value == 0) ? true : false;
}
