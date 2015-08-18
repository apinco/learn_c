//
//  main.c
//  contacts
//
//  Created by adam on 8/4/15.
//  Copyright (c) 2015 mada. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAX_FNAME 32
#define MAX_FNAME_SCANF "32"
#define SUCCESS 0
#define FAIL 1

// Global Vars
struct contact *head = NULL;
struct contact *tail = NULL;

//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}
int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}

struct contact
{
    char fname[MAX_FNAME];
    struct contact *next;
};

struct ll
{
    struct contct *head;
    struct contact *current;
};

//void add(struct ll, struct node)
//{
//    if (!ll.current)
//    {
//        ll.head = node;
//        ll.current = node;
//        return;
//    }
//    ll.current.next = node;
//    ll.current = node;
//    node.next = NULL;
//}

int print_menu(void) {
    int ans;
    do {
        ans = 0;
        printf("Choose an option:\n");
        printf("1. Print current list\n");
        printf("2. Add contact\n");
        printf("3. Exit\n");
        scanf("%d", &ans);
        if (!ans) {
            printf("**Bad Input**\n");
        }
    } while ((clean_stdin() && !ans) || ans < 1 || ans >3 );
    return ans;
}

int get_contact(char *name)
{
    char name_buf[MAX_FNAME];
    do
    {
        printf("Enter your name:\n");
        scanf("%"MAX_FNAME_SCANF"s", name_buf);
        if (!*name_buf) {
            printf("Bad Input, lalala\n");
        }
    } while ((clean_stdin() && !*name_buf));
    strcpy(name, name_buf);
    return SUCCESS;
}

int add_contact() {
    char fname[MAX_FNAME];
    
    if(get_contact(fname) == SUCCESS)
    {
        printf("I got this name: %s\n", fname);
        struct contact *newc = (struct contact)malloc(sizeof(head));
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}

int main(int argc, const char * argv[]) {
    //    struct ll myll;
    //    struct node *llnode;2
    int opt;

    
    
    do {
        opt = print_menu();
        switch (opt) {
            case 1:
                printf("**Print here**\n");
                break;
            case 2:
                if (add_contact() == SUCCESS) {
                    printf("success adding contact\n");
                }
                else {
                    printf("failed adding name\n");
                }
                break;
            case 3:
                printf("**save and exit here**\n");
                break;
            default:
                printf("**Invalid number selected**\n");
                break;
        }
    }
    while (opt != 3);
    return 0;
}


