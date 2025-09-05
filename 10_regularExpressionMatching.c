#include <regex.h>
#include <stdlib.h>
#include <string.h>

bool isMatch(char* s, char* p) {

    regex_t reegex;

    if ((!strchr(p, '*') && !strchr(p, '.')) && (s != p)) {
        return false;
    }

    size_t length = strlen(p);
    int value;

    for(int i = 0; i < length; i++){
        if(p[i] == '*' && i == 0){
            return false;
        } else if (p[i] == '*'){
            p[i] = 0;
        } else if (p[i] == '.'){
            p[i] = '.';
        } else {
            p[i] = p[i];
        }
    }

    if(strchr(p, '*') == NULL){
      value = regcomp( &reegex, p, 0);
    }else{
      value = regcomp( &reegex, p, REG_EXTENDED);
    }

    value= regexec( &reegex, s, 0, NULL, 0);

    return (value == 0) ? true : false;
}
