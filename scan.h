#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
int scan(char *input, user *head, int* like, int* delete);
int scan(char *input, user *head, int* like, int* delete)
{
    char *temp, parham;
    int i = 0, j = 0; /*i is for allocation and j is only a counter*/
    for (j = 0; parham != '\n'; j++)
    {
        temp = input; /*store the address of input in temp I'll explain the reason in the next few lines*/
        scanf("%c", &parham);
        i++; /*getting more memory rooms*/
        input = (char *)realloc(input, i * (sizeof(char)));
        input[j] = parham; /*assigning the input characters one by one*/
        if (parham == '\n')
        { /*if user enters enter we put null at the end of string*/
            input[j] = '\0';
            break;
        }
    }
    int commandCounter = 0;
    char *command = (char *)malloc(sizeof(char));
    for (commandCounter = 0; isspace(input[commandCounter]) == 0; commandCounter++)
    {
        command = (char *)realloc(command, (commandCounter + 1) * sizeof(char));
        command[commandCounter] = input[commandCounter];
    }
    command[commandCounter] = '\0';
    int kindOfCommand = 0;
    if (!strcmp(command, "signup"))
    {
        kindOfCommand = 1;
        return kindOfCommand;
    }
    if (!strcmp(command, "login"))
    {
        kindOfCommand = 2;
        return kindOfCommand;
    }
    if (!strcmp(command, "delete"))
    {
        kindOfCommand = 3;
        commandCounter++;
        *delete = input[commandCounter] - 48;
        return kindOfCommand;
    }
    if (!strcmp(command, "info"))
    {
        kindOfCommand = 4; /*the user's pointer*/
        return kindOfCommand;
    }
    if (!strcmp(command, "logout"))
    {
        kindOfCommand = 5;
        return kindOfCommand;
    }
    if (!strcmp(command, "like"))
    {
        kindOfCommand = 6;
        commandCounter++;
        for (commandCounter; isspace(input[commandCounter]) == 0; commandCounter++)
        {
        }
        commandCounter++;
        *like = input[commandCounter] - 48; /*pass ID to function*/
        input = (char *)realloc(input, sizeof(char));
        return kindOfCommand;
    }
    if (!strcmp(command, "find_user"))
    {
        kindOfCommand = 7;
        return kindOfCommand;
        /*head of the list and the input*/
    }
    if (!strcmp(command, "post"))
    {
    printf("before %s\n", input);
        kindOfCommand = 8;
        return kindOfCommand;
    }
}
/*int main(){
    char* in=(char*)malloc(sizeof(char));
    scan(in);
}*/