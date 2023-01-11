#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>/*post only receives a limited amount of characters*/
void posting(user *user, char *input, int* ID);
void posting(user *user, char *input, int* ID)
{
    post *head = user->posts;
    if (head == NULL) /*don't forget to assign null to the first post pointer*//*done*/
    {
    printf("the if\n%s\n", input);
        user->posts = (post *)malloc(sizeof(post));
        user->posts->tweet = (char *)malloc(sizeof(char));
        int reallocationCounter = 1, loopCounter = 5, assignCounter = 0;
        for (loopCounter; (input[loopCounter]) != '\0'; loopCounter++)
        {
            user->posts->tweet = (char *)realloc(user->posts->tweet, reallocationCounter * sizeof(char));
            user->posts->tweet[assignCounter] = input[loopCounter];
            reallocationCounter++;
            assignCounter++;
        }
        user->posts->tweet[assignCounter] = '\0';
        user->posts->postID = *ID;
        (*ID)++;
        user->posts->creator = user;
        user->posts->next = NULL;
        user->posts->likers=NULL;
        user->posts->likes=0;
        printf("%d\n%s\n", user->posts->postID, user->posts->tweet);
    }
    else
    {
        printf("the else\n%s\n", input);
        while (head != NULL)
        {
            if (head->next == NULL)
            {
                head->next = (post *)malloc(sizeof(post));
                break;
            }
            head = head->next;
        }
        head->next->tweet = (char *)malloc(sizeof(char));
        int reallocationCounter = 1, loopCounter = 5, assignCounter = 0;
        char *temp;
        for (loopCounter; (input[loopCounter]) != '\0'; loopCounter++)
        {
            head->next->tweet = (char *)realloc(head->next->tweet, reallocationCounter * sizeof(char));
            head->next->tweet[assignCounter] = input[loopCounter];
            reallocationCounter++;
            assignCounter++;
        }
        head->next->tweet[assignCounter] = '\0';
        head->next->postID = *ID;
        (*ID)++;
        head->next->creator = user;
        head->next->next = NULL;
        head->next->likers=NULL;
        head->next->likes=0;
        printf("%d\n%s\n", head->next->postID, head->next->tweet);
    }
    input=(char*)realloc(input, sizeof(char));
}
/*int main()
{
    int a = 1;
    int *ptr = &a;
    printf("%d\n", *ptr);
    char tweet[] = "post let's test this motherfucker";
    user *me = (user *)malloc(sizeof(user));
    post *nothing = (post *)malloc(sizeof(post));
    me->posts = nothing;
    nothing->next = NULL;
    posting(me, tweet, *ptr);
}*/