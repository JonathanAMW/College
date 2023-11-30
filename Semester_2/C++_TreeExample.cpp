#include <iostream>

struct BstNode
{
    int data;
    BstNode* left;
    BstNode* right;
};
BstNode* root = NULL;

BstNode* createNode(int data)
{
    BstNode* temp = new BstNode();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

BstNode* insertNode(BstNode* root, int data)
{
    if(root == NULL){
        root = createNode(data);
        return root;
    }else if(data == root->data){
        std::cout << "Data (" << data << ") yang dimasukkan sudah ada!\n";
    }else if(data > root->data){
        root->right = insertNode(root->right, data); //fungsi rekursif
    }else if(data < root->data){
        root->left = insertNode(root->left, data);
    }

    return root;
}

void Preorder(BstNode* root) 
{
    BstNode* temp = root;
    if(temp != NULL)
    {
        std::cout << temp->data << std::endl;
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Inorder(BstNode* root) 
{
    BstNode* temp = root;
    if(temp != NULL)
    {
        Inorder(root->left);
        std::cout << temp->data << std::endl;
        Inorder(root->right);
    }
}

void Postorder(BstNode* root) 
{
    BstNode* temp = root;
    if(temp != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        std::cout << temp->data << std::endl;
    }
}

int main()
{
    
    root = insertNode(root, 7);
    root = insertNode(root, 5);
    root = insertNode(root, 12);
    root = insertNode(root, 3);
    root = insertNode(root, 6);
    root = insertNode(root, 1);
    root = insertNode(root, 4);
    root = insertNode(root, 9);

    std::cout << "Preorder:" << std::endl;
    Preorder(root);

    std::cout << "\nInorder:" << std::endl;
    Inorder(root);

    std::cout << "\nPostorder:" << std::endl;
    Postorder(root);
}

