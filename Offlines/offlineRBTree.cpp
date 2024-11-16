#include <iostream>
using namespace std;

class nodeRBT
{
    int key;
    int color;
    nodeRBT *left, *right,*parent;
public:
    nodeRBT();
    nodeRBT(int,nodeRBT*);
    nodeRBT* getRight()
    {
        return right;
    }
    void setRight(nodeRBT* rChild)
    {
        right=rChild;
    }
    void setLeft(nodeRBT* lChild)
    {
        left=lChild;
    }
    nodeRBT* getLeft()
    {
        return left;
    }
    int getKey()
    {
        return key;
    }
    void setKey(int value)
    {
        key=value;
    }
    nodeRBT* getParent()
    {
        return parent;
    }
    void setParent(nodeRBT* p)
    {
        parent=p;
    }

};

nodeRBT :: nodeRBT()
{
    key = 0;
    left = right = parent=NULL;
}

nodeRBT :: nodeRBT(int value,nodeRBT* parnt)
{
    key = value;
    left = right = NULL;
    parent = parnt;
}

nodeRBT* insertFun(nodeRBT* root, int value)
{
    if (!root)
    {
        return new nodeRBT(value,root);
    }
    if (value > root->getKey())
    {
        if(root->getRight()==NULL)
        {
            return new nodeRBT(value,root);
        }
        else
        root->setRight(insertFun(root->getRight(), value));

    }
    else
    {
        if(root->getLeft()==NULL)
        {
            return new nodeRBT(value,root);
        }
        else
        root->setLeft (insertFun(root->getLeft(), value));
    }
    return root;
}
void leftRotate(nodeRBT* root,nodeRBT* x)
{
    nodeRBT* y=x->getRight();
    x->setRight(y->getLeft());
    if(y->getLeft()!=NULL)
    {
        y->getLeft()->setParent(x);
    }
    y->setParent(x->getParent());
    if( x->getParent()==NULL)
    {
        root=y;
    }
    else if( x == (x->getParent())->getLeft())
    {
        x->getParent()->setLeft(y);
    }
    else
    {
        x->getParent()->setRight(y);
    }
    y->setLeft(x);
    x->setParent(y);

}


// Inorder Traversal
void inorder(nodeRBT *root)
{
    if (root != NULL)
    {
        // Traverse left
        inorder(root->getLeft());

        // Traverse root
        cout << root->getKey()<< " -> ";

        // Traverse right
        inorder(root->getRight());
    }
}

int main()
{
    nodeRBT* root=NULL;
    cout<<"initialised"<<endl;
    root = insertFun(root, 9);
    root =insertFun(root, 6);
    root = insertFun(root, 15);
    root = insertFun(root, 12);
    root = insertFun(root, 19);
    root = insertFun(root, 16);
    root = insertFun(root, 20);


    cout << "Inorder traversal: ";
    inorder(root);
    cout<<endl;
    cout<<root->getKey()<<"   sfgdsfg  "<<endl;

    leftRotate(NULL,root->getRight());
    cout<<root->getKey()<<"   sfgdsfg  "<<endl;
    cout << "Inorder traversal: "<<endl;
    inorder(root);
    cout<<endl;
}
