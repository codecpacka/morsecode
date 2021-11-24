/////////////////structure of binary search tree.....
struct bst
{

    struct bst* left;
    int info;
    struct bst* right;
}*temp;

/////////////////////insertion in binary search tree............
struct bst* insbtree(struct bst *root, int data)
{
  

    if (root == NULL)
    {
        struct bst* node;
    node=(struct bst*)malloc(sizeof(bst));
    node->left = NULL;
    node->right = NULL;
    node->info = data;
        root = node;
        return root;
    }
    else if(data<root->info){
        root->left=insbtree(root->left,data);
    }
  
    else if(data>root->info){
        root->right=insbtree(root->right,data);
    }
    return root;
}

/////////preorder traversal..............
void preorder(struct bst *root){
        if (root)
    {
        
        printf("%d \t", root->info);
        preorder(root->left);
        preorder(root->right);
    }
    }


//////////inorder traversal..............
void inorder(struct bst *root){
        if (root)
    {
        
        inorder(root->left);
        printf("%d \t", root->info);
        inorder(root->right);
    }
    }
//////////post order treversal .............
void postorder(struct bst *root){
        if (root)
    {
        
        postorder(root->left);
        postorder(root->right);
        printf("%d \t", root->info);
    }
    }
/////////main display function from where calling is done..........
void disbst(struct bst *root)
    {
    if(root)
    {
       pf("preorder :-");
        preorder(root);
       pf("\n");
        pf("inorder :-");
        inorder(root);
        pf("\n");
        pf("postorder :-");
        postorder(root);

    }
    


    }
