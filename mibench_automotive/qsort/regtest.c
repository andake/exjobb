#include <regex.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

regex_t regex;
int reti;
char msgbuf[100];

int main (int argc, char *argv[]){
/* Compile regular expression */
        reti = regcomp(&regex, "..*\.dat", 0);
        if( reti ){ fprintf(stderr, "Could not compile regex\n"); exit(1); }

/* Execute regular expression */
        reti = regexec(&regex, argv[1], 0, NULL, 0);
        if( !reti ){
                puts("Match");
        }
        else if( reti == REG_NOMATCH ){
                puts("No match");
        }
        else{
                regerror(reti, &regex, msgbuf, sizeof(msgbuf));
                fprintf(stderr, "Regex match failed: %s\n", msgbuf);
                exit(1);
        }
}