#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "SLLfunctions.c"
void main()
{
    int n,i,item;

    printf("Enter size of list : ");
    scanf("%d",&n);

    struct node* list = (struct node*)calloc(n,sizeof(struct node));
    list=NULL;

    printf("Enter numbers : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        list=insertEnd(list,item);
    }

    printf("List is : ");
    display(list);

    struct node* odd=NULL;
    struct node* even=NULL;

    for(i=0;i<n;i++)
    {
        item=list->data;
        item=pow(item,3);
        if(item%2==0)
            even=insertEnd(even,item);
        else
            odd=insertEnd(odd,item);

        list=list->next;
    }

    printf("\nOdd list is : ");
    display(odd);
    printf("\nEven list is : ");
    display(even);
}
