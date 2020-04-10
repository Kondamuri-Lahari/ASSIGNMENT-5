//1.write a c program to reverse a string using stack?
input:
#include <stdio.h>  
#include <string.h>  
#define max 100  
int top,stack[max];
void main()  
{  
   char str[]="kondamuri";  
   int len = strlen(str);  
   int i;  
   for(i=0;i<len;i++)
        push(str[i]);  
   for(i=0;i<len;i++) 
      pop();
} 
  
void push(char x){  
  
      if(top == max-1){  
          printf("stack overflow");  
      }  else { 
          top++;
          stack[top]=x;
          printf("\n insertion sucess!!!");
      }  
  
}  
void pop(){ 
   if(top==-1)
       printf("\n stack is empty!!!deletion is not possible!!!");
    else{ 
      printf("%c",stack[top--]);  
    }
}  
output:

insertion sucess!!!                                                                                    
 insertion sucess!!!                                                                                    
 insertion sucess!!!                                                                                    
 insertion sucess!!!                                                                                    
 insertion sucess!!!                                                                                    
 insertion sucess!!!                                                                                    
 insertion sucess!!!                                                                                    
 insertion sucess!!!                                                                                    
 insertion sucess!!!irumadnok 

2.write a program for infix to postfix conversation using stack?
input:
#include<stdio.h>
char stack[50];
int top = -1;
void push(char y)
{
    stack[++top] = y;
}
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
int priority(char y)
{
    if(y == '(')
    {
        return 0;
    }
    if(y == '+' || y == '-')
     {
         return 1;
      }
    if(y== '*' || y == '/')
    {
        return 2;
    }
}
main()
{
    char exp[50];
    char *e, y;
    printf("Enter the expression: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((y = pop()) != '(')
                printf("%c", y);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c",pop());
    }
}
output:
Enter the expression: a+b(d%e*-+)                                                                                                               
abde%*-++
  
3.write a c program to implement queue using two stacks
input:
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void push(struct node** top, int data);
int pop(struct node** top);
struct queue
{
    struct node *stack1;
    struct node *stack2;
};
void enqueue(struct queue *q, int y)
{
    push(&q->stack1, y);
}
void dequeue(struct queue *q)
{
    int y;
    if (q->stack1 == NULL && q->stack2 == NULL) {
        printf("queue is empty");
        return;
    }
    if (q->stack2 == NULL) {
        while (q->stack1 != NULL) {
        y= pop(&q->stack1);
        push(&q->stack2, y);
        }
    }
    y = pop(&q->stack2);
    printf("%d\n", y);
}
void push(struct node** top, int data)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Stack overflow \n");
            return;
        }
    newnode->data = data;
    newnode->next = (*top);
    (*top) = newnode;
}
int pop(struct node** top)
{
    int buff;
    struct node *t;
    if (*top == NULL) {
        printf("Stack underflow \n");
        return;
    }
    else {
        t = *top;
        buff = t->data;
        *top = t->next;
        free(t);
        return buff;
    }
}
void display(struct node *top1,struct node *top2)
{
    while (top1 != NULL) {
        printf("%d\n", top1->data);
        top1 = top1->next;
    }
    while (top2 != NULL) {
        printf("%d\n", top2->data);
        top2 = top2->next;
    }
}
int main()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    int f = 0, a;
    char ch = 'x';
    q->stack1 = NULL;
    q->stack2 = NULL;
    while (ch == 'y'||ch == 'x') {
        printf("enter ur choice\n1.add to queue\n2.remove from queue\n3.display\n4.exit\n");
        scanf("%d", &f);
        switch(f) {
            case 1 : printf("enter the elements \n");
                     scanf("%d", &a);
                     enqueue(q,a);
                     break;
            case 2 : dequeue(q);
                     break;
            case 3 : display(q->stack1, q->stack2);
                     break;
            case 4 : exit(1);
                     break;
            default : printf("invalid\n");
                      break;
        }
    }
}
output:
enter ur choice                                                                                         
1.add to queue                                                                                          
2.remove from queue                                                                                     
3.display                                                                                               
4.exit                                                                                                  
1                                                                                                       
enter the elements                                                                                      
4                                                                                                       
enter ur choice                                                                                         
1.add to queue                                                                                          
2.remove from queue                                                                                     
3.display                                                                                               
4.exit                                                                                                  
2                                                                                                       
4                                                                                                       
enter ur choice                                                                                         
1.add to queue                                                                                          
2.remove from queue                                                                                     
3.display                                                                                               
4.exit                                                                                                  
1                                                                                                       
enter the elements                                                                                      
5                                                                                                       
enter ur choice                                                                                         
1.add to queue                                                                                          
2.remove from queue 
3.display                                                                                               
4.exit                                                                                                  
1                                                                                                       
enter the elements                                                                                      
5                                                                                                       
enter ur choice                                                                                         
1.add to queue                                                                                          
2.remove from queue                                                                                     
3.display                                                                                               
4.exit                                                                                                  
3                                                                                                       
5                                                                                                       
enter ur choice                                                                                         
1.add to queue                                                                                          
2.remove from queue                                                                                     
3.display                                                                                               
4.exit                                                                                                  
4  
 
4.write a c programe for insertion and deletion of bst?
input:
  #include <stdio.h>
  #include <stdlib.h>
  struct treeNode 
  {
        int data;
        struct treeNode *left, *right;
  };
  struct treeNode *root = NULL;
  struct treeNode* createNode(int data) 
  {
        struct treeNode *newNode;
        newNode = (struct treeNode *) malloc(sizeof (struct treeNode));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return(newNode);
  }
  void insertion(struct treeNode **node, int data) {
        if (*node == NULL) 
        {
                *node = createNode(data);
        } else if (data < (*node)->data) {
                insertion(&(*node)->left, data);
        } else if (data > (*node)->data) {
                insertion(&(*node)->right, data);
        }
  }
  void deletion(struct treeNode **node, struct treeNode **parent, int data) 
  {
        struct treeNode *tmpNode, *tmpParent;
        if (*node == NULL)
                return;
        if ((*node)->data == data) {
                /* deleting the leaf node */
                if (!(*node)->left && !(*node)->right) {
                        if (parent) {
                                /* delete leaf node */
                                if ((*parent)->left == *node)
                                        (*parent)->left = NULL;
                                else
                                        (*parent)->right = NULL;
                                free(*node);
                        } else 
                        {
                                free(*node);
                        }
                } else if (!(*node)->right && (*node)->left) 
                {
                        tmpNode = *node;
                        (*parent)->right = (*node)->left;
                        free(tmpNode);
                        *node = (*parent)->right;
                } else if ((*node)->right && !(*node)->left) 
                {
                        tmpNode = *node;
                        (*parent)->left = (*node)->right;
                        free(tmpNode);
                        (*node) = (*parent)->left;
                } else if (!(*node)->right->left) {
                          tmpNode = *node;
                        (*node)->right->left = (*node)->left;
                        (*parent)->left = (*node)->right;
                        free(tmpNode);
                        *node = (*parent)->left;
                } else 
                {
                        tmpNode = (*node)->right;
                        while (tmpNode->left) {
                                tmpParent = tmpNode;
                                tmpNode = tmpNode->left;
                        }
                        tmpParent->left = tmpNode->right;
                        tmpNode->left = (*node)->left;
                        tmpNode->right =(*node)->right;
                        free(*node);
                        *node = tmpNode;
                }
        } else if (data < (*node)->data) 
        {
                deletion(&(*node)->left, node, data);
        } else if (data > (*node)->data) 
        {
            deletion(&(*node)->right, node, data);
        }
  }
  void findElement(struct treeNode *node, int data) {
        if (!node)
                return;
        else if (data < node->data) {
                findElement(node->left, data);
        } else if (data > node->data) {
                findElement(node->right, data);
        } else
                printf("data found: %d\n", node->data);
        return;

  }

  void traverse(struct treeNode *node) {
        if (node != NULL) {
                traverse(node->left);
                printf("%3d", node->data);
                traverse(node->right);
        }
        return;
  }
  int main() {
        int data,ch;
        while (1) {
                printf("1. Insertion\n");
                printf("2. Deletion\n");
                printf("3. Search Element in Binary Search Tree\n");
                printf("4. Inorder traversal\n5. Exit\n");
                printf("Enter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                while (1) {
                                printf("Enter your data:");
                                scanf("%d", &data);
                                insertion(&root, data);
                                printf("Continue Insertion(0/1):");
                                scanf("%d", &ch);
                                if (!ch)
                                        break;
                                }
                                break;
                        case 2:
                                printf("Enter your data:");
                                scanf("%d", &data);
                                deletion(&root, NULL, data);
                                break;
                        case 3:
                                printf("Enter value ofdata:");
                                scanf("%d", &data);
                                findElement(root, data);
                                break;
                        case 4:
                                printf("Inorder Traversal:\n");
                                traverse(root);
                                printf("\n");
                                break;
                        case 5:
                                exit(0);
                        default:
                                printf(" entered wrong option\n");
                                break;
                }
        }
        return 0;
  }
output:
1. Insertion                                                                                            
2. Deletion                                                                                             
3. Search Element in Binary Search Tree                                                                 
4. Inorder traversal                                                                                    
5. Exit                                                                                                 
Enter your choice:1                                                                                     
Enter your data:6                                                                                       
Continue Insertion(0/1):9                                                                               
Enter your data:2                                                                                       
Continue Insertion(0/1):0                                                                               
1. Insertion                                                                                            
2. Deletion                                                                                             
3. Search Element in Binary Search Tree                                                                 
4. Inorder traversal                                                                                    
5. Exit                                                                                                 
Enter your choice:3                                                                                     
Enter value ofdata:9                                                                                    
1. Insertion                                                                                            
2. Deletion                                                                                             
3. Search Element in Binary Search Tree                                                                 
4. Inorder traversal                                                                                    
5. Exit                                                                                                 
Enter your choice:5  

 

