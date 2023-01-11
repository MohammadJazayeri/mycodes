#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void info(user *user);
void info(user *user)
{
    printf("%s\n%s\n", user->username, user->password);
    while (user->posts != NULL)
    {
        printf("%d\n%s\n%d\n", user->posts->postID, user->posts->tweet, user->posts->likes);
        user->posts = user->posts->next;
    }
}
/*int main()
{
    user *user = (struct user_data *)malloc(sizeof(struct user_data));
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
    info(user);
}*/