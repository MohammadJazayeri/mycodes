#include <stdio.h>
#include <stdlib.h>
#include "scan.h"
#include "signup.h"
#include "post.h"
#include "login.h"
#include "like.h"
#include "info.h"
#include "find.h"
#include "delete.h"
#include "logout.h"
#define TRUE 1
int main()
{
    typedef struct user_data user;
    typedef struct user_posts post;
    typedef struct users_likes liker;
    struct user_posts
    {
        int postID;
        char *tweet;
        int likes;                                      /*initialize likes with 0*/
        liker *likers; /*assign null to this variable*/ /*same as above*/
        user *creator;
        post *next;
    };
    struct user_data
    {
        char *username;
        char *password;
        post *posts;
        user *next;
    };
    struct users_likes
    {
        user *likee;
        liker *next;
    };
    printf("Welcome to university of Tehrans's version of twitter.\n");
    printf("in order to work with this application enter your command and the needed info as following:\n");
    printf("signing up: signup username password\n");
    printf("logging in: login username password\n");
    printf("posting: post your tweet\n");
    printf("deleting: delete post_ID\n");
    printf("searching: find_user username\n");
    printf("displaying your info: info\n");
    printf("liking a post:like username post_ID\n");
    printf("logging out: logout\n");
    user *head = NULL;
    user *inControl;
    int command = 0;
    int post_ID = 1;
    int like_ID = 0;
    int delete = 0;
    int *deletePtr = &delete;
    int *postPtr = &post_ID;
    int *likePtr = &like_ID;
    char *input = malloc(sizeof(char));
    while (TRUE)
    {
        command = scan(input, head, likePtr, deletePtr);
        printf("#%d\n", command);
        printf("%s\n", input);
        switch (command)
        {
        case 1:
            if (head == NULL)
            {
                head = signup(input, head);
            }
            else
            {
                signup(input, head);
            }
            break;
        case 2:
            inControl = login(input, head);
            break;
        case 3:
           inControl = deleting(inControl, deletePtr);
            break;
        case 4:
            info(inControl);
            break;
        case 5:
            logout(inControl);
            inControl = (user *)malloc(sizeof(user));
            break;
        case 6:
            /*printf("%x\n%x\n", head, inControl);*/
            like(head, inControl, likePtr);
            break;
        case 7:
            find(input, head);
            break;
        case 8:
            printf("this is before calling the function\n%s\n", input);
            posting(inControl, input, postPtr);
            break;
        default:
            break;
        }
    }
}