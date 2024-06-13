#include<stdio.h>
#include<stdlib.h>
/*C program for recursive and inrecursive preorder,postorder and Inorder 
   Traversal of Tree Inputed from User*/
   

// Creating the structure for node of the tree
struct node{
	int data;
	struct node*left; //storing left child
	struct node*right;  // storing the right child
};
// implementing the stack with the help of LL
struct stack{
	int top;
	struct node**s;
};
// creating the tree mean taking the tree input from the user
struct node * create()
{
    int x;
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the node,if no node then enter 0\n");
    scanf("%d",&x);
    if(x==0)
    {
        return 0;
    }
    newnode->data=x;
    printf("enter the left node of %d\n",x);
    newnode->left=create(); // recursive call of create for left subtree
    printf("enter the rigth node of %d\n",x);
    newnode->right=create();  // recursive call of create for right subtree
    return newnode;
}

// Recursive Preorder traversal of Tree
void preorder(struct node*root){
	if(root==0){
		return ;
	}
	printf("%d  ",root->data);
	preorder(root->left);
	preorder(root->right);
	
}
// Recursive inorder traversal of tree
void inorder(struct node*root){
	if(root==0){
		return ;
	}
	inorder(root->left);
	printf("%d  ",root->data);
	inorder(root->right);
	
}
// Recursive postorder traversal of tree
void postorder(struct node*root){
	if(root==0){
		return ;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d  ",root->data);
	
}
// defining the push funhction for the stack
void push(struct stack*s1,struct node*t){
	s1->top++;
	s1->s[s1->top]=t;
	
}
//defining pop funtion of stack
struct node* pop(struct stack*s1){
	struct node*t;
	t=s1->s[s1->top];
	s1->top--;
	return t;
	
}
// function to check weather the stack is empty or not
int empty(struct stack*s){
	if(s->top==-1){
		return 1;
		
	}
	else{
		return 0;
	}
}
// Non-recursive preorder traversal 
void n_preorder(struct node*root){
	//preorder(root);
//	printf("\n");
	struct stack*s1;
	s1=(struct stack*)malloc(sizeof(struct stack));
	s1->top=-1;
	s1->s=(struct node**)malloc(10*sizeof(struct node*));
	struct node*t=root;
	while(t!=0){
		printf("%d  ",t->data);
		push(s1,t);
		t=t->left;
	}
	while(!empty(s1)){
		t=pop(s1);
		t=t->right;
	 while(t!=0){
		printf("%d  ",t->data);
		push(s1,t);
		t=t->left;
	}
	}
	
}

// Non-recursive In-order  traversal 
void n_inorder(struct node*root){
//	inorder(root);
//	printf("\n");
	struct stack*s1;
	s1=(struct stack*)malloc(sizeof(struct stack));
	s1->top=-1;
	s1->s=(struct node**)malloc(10*sizeof(struct node*));
	struct node*t=root;
	while(t!=0){
		push(s1,t);
		t=t->left;
	}
	while(!empty(s1)){
		t=pop(s1);
		printf("%d  ",t->data);
		t=t->right;
	 while(t!=0){
		push(s1,t);
		t=t->left;
	}
	}
	
}
// Non-recursive postorder traversal 
void n_postorder(struct node*root){
//	postorder(root);
//	printf("\n");
	struct stack*s1;
	s1=(struct stack*)malloc(sizeof(struct stack));
	s1->top=-1;
	s1->s=(struct node**)malloc(10*sizeof(struct node*));
	struct stack*s2;
	s2=(struct stack*)malloc(sizeof(struct stack));
	s2->top=-1;
	s2->s=(struct node**)malloc(10*sizeof(struct node*));
	struct node*t=root;
	push(s1,t);
	while(!empty(s1)){
		t=pop(s1);
		push(s2,t);
		if(t->left!=0){
			push(s1,t->left);
			
		}
		if(t->right!=0){
			push(s1,t->right);
			
		}
		
	}
	while(!empty(s2)){
		root=pop(s2);
		printf("%d  ",root->data);
		
	}
	
}
int main(){
	struct node*root=0;
	root=create();
	printf("\n------------------------------------------------------------\n");
	printf("\nRecursive preorder Traversal of tree : \n");
	preorder(root);
	printf("\nNon-Recursive preorder Traversal of tree : \n");
	n_preorder(root);
	printf("\n------------------------------------------------------------\n");
//    printf("\n------------------------------------------------------------\n");
	printf("\nRecursive inorder Traversal of tree : \n");
	inorder(root);
	printf("\nNon-Recursive inorder Traversal of tree : \n");
	n_inorder(root);
	printf("\n------------------------------------------------------------\n");
//		printf("\n------------------------------------------------------------\n");
	printf("\nRecursive postorder Traversal of tree : \n");
	postorder(root);
	printf("\nNon-Recursive postorder Traversal of tree : \n");
	n_postorder(root);
	printf("\n------------------------------------------------------------\n");
//	printf("\npreorder:\n");
//	
//	printf("\ninorder:\n");
//	n_inorder(root);
//	printf("\npostorder:\n");
//	n_postorder(root);
	return 0;
	
}
