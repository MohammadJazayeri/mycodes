#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void logout(user* input);
void logout(user* input){
    printf("%s ",input->username);
    input=NULL;
    printf("logged out\n");
}