#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
user *login(char *input, user *head);
user *login(char *input, user *head)
{
    char *name = (char *)malloc(sizeof(char));
    char *password = (char *)malloc(sizeof(char));
    int reallocationCounter = 1, nameLoopCounter = 6, assignCounter = 0;
    for (nameLoopCounter; isspace(input[nameLoopCounter]) == 0; nameLoopCounter++)
    {
        name = (char *)realloc(name, reallocationCounter * sizeof(char));
        name[assignCounter] = input[nameLoopCounter];
        reallocationCounter++;
        assignCounter++;
    }
    name[assignCounter] = '\0';
    reallocationCounter = 1, assignCounter = 0;
    int passLoopCounter = nameLoopCounter + 1;
    for (passLoopCounter; (input[passLoopCounter]) != '\0'; passLoopCounter++)
    {
        password = (char *)realloc(password, reallocationCounter * sizeof(char));
        password[assignCounter] = input[passLoopCounter];
        reallocationCounter++;
        assignCounter++;
    }
    password[assignCounter] = '\0';
    printf("enter login\n");
    user *search = head;
    while (search != NULL)
    {
        if ((!(strcmp(search->username, name))) && (!(strcmp(search->password, password))))
        {
            printf("%s\n%s\n",name,password);
            break;
        }
        search = search->next;
    }
    input=(char*)realloc(input,sizeof(char));
    return search;
}
/*int main()
{
    user *user1 = (user *)malloc(sizeof(user));
    user *user2 = (user *)malloc(sizeof(user));
    user *user3 = (user *)malloc(sizeof(user));
    user *user4 = (user *)malloc(sizeof(user));
    user *who = (user *)malloc(sizeof(user));
    user1->username = "moham";
    user1->password = "fell";
    user1->next = user2;
    user2->username = "zeynab";
    user2->password = "1019";
    user2->next = user3;
    user3->username = "parham";
    user3->password = "nobusines";
    user3->next = user4;
    user4->username = "navid";
    user4->password = "stopit79";
    user4->next = NULL;
    char input[] = {"login zeynab 1019"};
    who = login(input, user1);
    printf("\n%x", who);
}*/