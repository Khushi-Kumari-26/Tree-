#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root;
struct node* createT()
{
    int val;
    struct node* NT = (struct node*)malloc(sizeof(struct node));
    printf("Enter data, or -1 for no data: ");
    scanf("%d", &val);
    if (val == -1)
    {
        return NULL;
    }
    else
    {
        NT->data = val;
        printf("left child:\n");
        NT->left = createT();
        printf("right child:\n");
        NT->right = createT();
        return NT;
    }
}
//call a new node
struct node* newnode(int item)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void inorder(struct node* temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
    return;
}
void preorder(struct node* temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
    return;
}
void postorder(struct node* temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
    return;
}
struct node* insert(struct node* root,int key)
{
	if(root==NULL)
	{
	    return newnode(key);
    }
	else if(key<root->data)
	{
		root->left=insert(root->left,key);
	}
	else
	{
		root->right=insert(root->right,key);
	}
	return root;
}


struct node* inorderpredeccessor(struct node* root,int key)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=key;
    while(temp->right=NULL)
    {
        temp=temp->right;
    }
    return temp;
}
struct node* deletenode(struct node* root,int key)
{
    if(root==NULL)
    {
        return root;
    }
    if(key<root->data)
    {
        root->left=deletenode(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=deletenode(root->right,key);
    }
    else
    {
        if(root->left==NULL)
        {
            struct node* temp=root->right;
            free(root);
        return temp;
        }
        else if(root->right==NULL)
        {
            struct node* temp=root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node* temp = inorderpredeccessor(root->left,key);
            root->data=temp->data;
            root->left = deletenode(root->left,temp->data);
 }
}

}
int main()
{
    root = createT();
    printf("Inorder:\n");
    inorder(root);
    printf("\n");
    printf("Preorder:\n");
    preorder(root);
    printf("\n");
    printf("Postorder:\n");
    postorder(root);
    printf("\n");
    printf("insertion in the tree :\n");
    root=insert(root,100);
    inorder(root);
    printf("deletion in the tree :\n");
    root=deletenode(root,85);
    inorder(root);
    return 0;
}

