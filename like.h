#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>/*fix the ID receiving*/
void like(user *head,user* users, int *ID);
void like(user *head,user* users, int *ID)
{
    int flag = 0;
    user *search = head;
    post *find = search->posts;
    printf("-_-%d\n", *ID);
    while (search != NULL)
    {
        while (find != NULL)
        {
            if (find->postID == *ID)
            {
                flag++;
                break;
            }
            find = find->next;
        }
        if (flag == 1)
        {
            break;
        }
        search = search->next;
        find = search->posts;
    }
    if (find->likers == NULL)
    {
        find->likers = (liker *)malloc(sizeof(liker));
        find->likers->likee = users;
        find->likes++;
        find->likers->next = NULL;
        printf("_-_%d\npost liked successfully\n", find->likes);
    }
    else
    {
        liker *search = find->likers;
        while (search != NULL)
        {
            if (search->likee == users)
            {
                printf("you already liked this post");
                break;
            }
            else if (search->next == NULL)
            {
                search->next = (liker *)malloc(sizeof(liker));
                search->next->likee = users;
                search->next->next = NULL;
                find->likes++;
                printf("#%d\npost liked successfully", find->likes);
                break;
            }
            search = search->next;
        }
    }
}
/*int main()
{
    user *user1 = (user *)malloc(sizeof(user));
    user *user2 = (user *)malloc(sizeof(user));
    user1->posts = (post *)malloc(sizeof(post));
    user2->posts = (post *)malloc(sizeof(post));
    user1->posts->next = (post *)malloc(sizeof(post));
    user1->next = user2;
    user2->next = NULL;
    user1->posts->likers = (liker*)malloc(sizeof(liker));
    user1->posts->likers->likee=user1;
    user1->posts->next->likers = NULL;
    user1->posts->creator = user1;
    user1->posts->next->creator = user1;
    user1->posts->postID = 1;
    user1->posts->tweet = "I love you";
    user1->posts->likes = 0;
    user1->posts->next->postID = 2;
    user1->posts->next->tweet = "don't I deserve to hear it back?";
    user1->posts->next->likes = 0;
    user1->posts->next->next = NULL;
    user2->posts->creator = user2;
    user2->posts->postID = 3;
    user2->posts->tweet = "you deserve it and you will. just in time";
    user2->posts->likers = NULL;
    user2->posts->likes = 0;
    user2->posts->next = NULL;
    like(user1, user1, 1);
}*/