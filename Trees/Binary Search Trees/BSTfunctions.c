#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}Node;

//----------------------QUEUE FUNCTIONS CREATION-----------------------------------//
typedef struct 
{
    Node* arr[50];
    int front, rear;
}Queue;

int isEmpty(Queue *q)
{
    if(q->front==q->rear)
        return 1;
    return 0;
}

Node* dequeue(Queue *q)
{
    return q->arr[++q->front];
}

void enqueue(Queue *q, Node* temp)
{
    q->arr[++q->rear]=temp;
}
//-------------------------------------------------------------------------//
//-----------------------NODE CREATION-----------------------------------//
Node* getnode(int x)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=x;
    newNode->right=NULL;
    newNode->left=NULL;
    return newNode;
}
//-----------------------------TRAVERSALS------------------------------------//
//<---------------------------INORDER-------------------------------->
void inorder(Node* root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
}

//<----------------------------PREORDER------------------------------->
void preorder(Node* root)
{
    if(root)
    {
        printf("%d  ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//<----------------------------POSTORDER------------------------------>
void postorder(Node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d  ",root->data);
    }
}

//<----------------------------LEVEL ORDER----------------------------->
void levelorder(Node* root)
{
    Queue q;
    q.front=-1;
    q.rear=-1;
    if(root==NULL)
    {
        printf("Empty tree");
        return;
    }

    enqueue(&q,root);
    while(!isEmpty(&q))
    {
        Node* temp=dequeue(&q);
        printf("%d  ",temp->data);
        if(temp->left)
            enqueue(&q,temp->left);

        if(temp->right)
            enqueue(&q,temp->right);
    }
}
//------------------------------------------------------------------------------//
//----------------------CREATING BST USING RECURSION--------------------------//
Node* recursiveCreateBST(int item)
{
    int x;
    if(item!=-1)
    {
        Node* temp=getnode(item);
        printf("Enter element : ");
        scanf("%d",&x);
        if(x<temp->data)
            temp->left=recursiveCreateBST(x);
        else if(x>temp->data)
            temp->right=recursiveCreateBST(x);
        else
            printf("No duplicates");

        return temp;
    }
    else
        return NULL;
}