#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*fix deleteing one post so it wouldn't lead to deleteing all*/
user* deleting(user *user, int *ID);
user* deleting(user *user, int *ID)
{
    post *search = user->posts;
    post *pre = user->posts;
    int flag = 0;
    while (search != NULL)
    {
        printf("\nwhile\n");
        if (search->postID == *ID)
        {
            if (search->creator == user)
            {
                printf("creator\n");
                if (pre == search)
                {
                    user->posts = user->posts->next;
                    printf("%s\n",search->tweet);
                    printf("if\nthe post was deleted\n");
                    flag = 1;
                    free(search);
                    return user;
                    break;
                }
                else
                {
                    printf("not head\n");
                    pre->next = search->next;
                    printf("else\nthe post was deleted\n");
                    flag = 1;
                    free(search);
                    return user;
                    break;
                }
            }
        }
        pre = search;
        search = search->next;
    }
    if (flag == 0)
    {
        printf("Unauthorized action\n");
        return user;
    }
}
/*int main()
{
    user *user1 = (user *)malloc(sizeof(user));
    user *user2 = (user *)malloc(sizeof(user));
    user1->posts = (post *)malloc(sizeof(post));
    user2->posts = (post *)malloc(sizeof(post));
    user1->posts->next = (post *)malloc(sizeof(post));
    user1->posts->creator = user1;
    user1->posts->next->creator = user1;
    user1->posts->postID = 1;
    user1->posts->tweet = "I love you";
    user1->posts->next->postID = 2;
    user1->posts->next->tweet = "don't I deserve to hear it back?";
    user1->posts->next->next = NULL;
    user2->posts->creator = user2;
    user2->posts->postID = 3;
    user2->posts->tweet = "you deserve it and you will. just in time";
    user2->posts->next = NULL;
    delete (user2, 3);
}*/