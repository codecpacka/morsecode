#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf
#include "bst.h" ////////header file with all the functions used in this programme

void search(struct bst *root, int data)
{
    if (root == NULL)
    {
        pf("\t element not found");
        return;
    }
    else if (data < root->info)
                    search(root->left, data);
    else if (data > root->info)
                    search(root->right, data);
    else
    {
        pf(" \t element found ");
    }
}

int main()
{
    int data, ch;
    struct bst *root;
    root = NULL;
    do
    {
        // disbst(root);
        pf("\n enter your choice\n ");
        pf("1.insert\n");
        pf("2.display\n");
        pf("3.search an element\n");
        pf("0.exit\n ");
        sf("%d", &ch);
        switch (ch)
        {
        case 0:
            exit(0);
            break;
        case 1:
            pf("x=");
            sf("%d", &data);
            root = insbtree(root, data);
            break;

        case 2:
            disbst(root);
            break;

        case 3:
            pf("element search x=");
            sf("%d", &data);
            search(root, data);
            break;

        default:
            pf("wrong choice");
            break;
        };
    } while (ch != 0);
    return 0;
}