#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>/*fix the post showing after deleteing one*//*I think it's more of a delete problem*/
void find(char *input, user *head);
void find(char *input, user *head)
{
    user *search = head;
    char *name = (char *)malloc(sizeof(char));
    int reallocationCounter = 1, loopCounter = 10, assignCounter = 0;
    char *temp;
    for (loopCounter; isspace(input[loopCounter]) == 0; loopCounter++)
    {
        temp = name;
        name = (char *)realloc(name, reallocationCounter * sizeof(char));
        name[assignCounter] = input[loopCounter];
        reallocationCounter++;
        assignCounter++;
        if (temp != name)
        {
            free(temp);
        }
    }
    name[assignCounter] = '\0';
    int checkpoint=0;
    while (search != NULL)
    {
        if (!strcmp(name, search->username))
        {
            checkpoint=printf("%s\n", search->username);
            while (search->posts != NULL)
            {
                printf("%d\n%s\n%d\n", search->posts->postID, search->posts->tweet,search->posts->likes);
                search->posts = search->posts->next;
            }
        }
        search = search->next;
    }
    if (checkpoint==0)
    {
        printf("no such user exists");
    }
    free(name);
}
/*int main()
{
    user* head=(user*)malloc(sizeof(user*));
    user *user = (struct user_data *)malloc(sizeof(struct user_data));
    head->next=user;
    user->next=NULL;
    user->posts = (post *)malloc(sizeof(post));
    user->posts->next = (post *)malloc(sizeof(post));
    user->username = "mohammad";
    user->password = "ImissU";
    user->posts->postID = 1;
    user->posts->tweet = "Even a message would make me so happy:)";
    user->posts->likes = 8;
    user->posts->next->postID = 2;
    user->posts->next->tweet = "I'm still waiting:D";
    user->posts->next->likes = 2;
    user->posts->next->next = NULL;
    char* input="find_user ali";
    find(input,head);
}*/