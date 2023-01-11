#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct user_data user;
typedef struct user_posts post;
typedef struct users_likes liker;
user* signup(char *user_input, user *head);
user* signup(char *user_input, user *head)
{
   user* search=head;
   if (search==NULL)
   {
      int reallocationCounter = 1, nameLoopCounter = 7, assignCounter = 0;
   search = (struct user_data *)malloc(sizeof(user));
   if (search == NULL)
      printf("oops");
   search->username = (char *)malloc(sizeof(char));
   if (search->username == NULL)
      printf("oops");
   for (nameLoopCounter; isspace(user_input[nameLoopCounter]) == 0; nameLoopCounter++)
   {
      search->username = (char *)realloc(search->username, reallocationCounter * sizeof(char));
      search->username[assignCounter] = user_input[nameLoopCounter];
      reallocationCounter++;
      assignCounter++;
   }
   search->username[assignCounter] = '\0';
   reallocationCounter = 1, assignCounter = 0;
   int passLoopCounter = nameLoopCounter + 1;
   search->password = (char *)malloc(sizeof(char));
   if (search->password == NULL)
   {
      printf("oops");
   }
   for (passLoopCounter; (user_input[passLoopCounter]) != '\0'; passLoopCounter++)
   {
      search->password = (char *)realloc(search->password, reallocationCounter * sizeof(char));
      search->password[assignCounter] = user_input[passLoopCounter];
      reallocationCounter++;
      assignCounter++;
   }
   search->password[assignCounter] = '\0';
   search->next = NULL;
   search->posts=NULL;
   user_input=(char*)realloc(user_input,sizeof(char));
      return search;
   }
   while(search->next!=NULL){
      search=search->next;
   }
   int reallocationCounter = 1, nameLoopCounter = 7, assignCounter = 0;
   search->next = (struct user_data *)malloc(sizeof(user));
   if (search->next == NULL)
      printf("oops");
   search = search ->next;
   
   search->username = (char *)malloc(sizeof(char));
   if (search->username == NULL)
      printf("oops");
   for (nameLoopCounter; isspace(user_input[nameLoopCounter]) == 0; nameLoopCounter++)
   {
      search->username = (char *)realloc(search->username, reallocationCounter * sizeof(char));
      search->username[assignCounter] = user_input[nameLoopCounter];
      reallocationCounter++;
      assignCounter++;
   }
   search->username[assignCounter] = '\0';
   reallocationCounter = 1, assignCounter = 0;
   int passLoopCounter = nameLoopCounter + 1;
   search->password = (char *)malloc(sizeof(char));
   if (search->password == NULL)
   {
      printf("oops");
   }
   for (passLoopCounter; (user_input[passLoopCounter]) != '\0'; passLoopCounter++)
   {
      search->password = (char *)realloc(search->password, reallocationCounter * sizeof(char));
      search->password[assignCounter] = user_input[passLoopCounter];
      reallocationCounter++;
      assignCounter++;
   }
   search->password[assignCounter] = '\0';
   search->next = NULL;
   search->posts=NULL;
   user_input=(char*)realloc(user_input,sizeof(char));
   if(head==NULL){
      printf("checkpoint");
      head=search;
   }
   return head;
}
/*int main(){
    char input[]={"signup mohammad 12345psi"};
    user* new=signup(input,6);
    if(new==NULL)
    printf("0oops");
    printf("%x", new);
}*/