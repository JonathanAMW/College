#include <iostream>
#include <stack>
#include <queue>

struct Node {
    char info;
    Node* left;
    Node* right;
};

Node* root = NULL;

Node* CreateNode(int info)
{
    Node* temp = new Node();
    temp->info = info;
    temp->left = temp->right = NULL;
    return temp;
}

Node* InsertNode(Node *root, Node *info) //tanpa rekursif
{
    if(root->right == NULL){
        root->right = info;
    }else if(root->left == NULL){
        root->left = info;
    }else{
        std::cout << "Error pada InsertNode" << std::endl;
    }
}

//traversal tanpa rekursif atau iteratif
void Preorder(Node* root) 
{
    std::cout << "Preorder/Prefix: ";
    Node* temp = root;
    std::stack<Node *> address; //untuk menyimpan alamat
    address.push(temp); //memasukkan address pertama / root
    while(!address.empty())
    {
        temp = address.top();
        address.pop();
        std::cout << temp->info;
        
        if(temp->right != NULL){
            address.push(temp->right);
        }
        if(temp->left != NULL){
            address.push(temp->left);
        }
    }
}

void Inorder(Node* root)
{
    std::cout << "Inorder/Infix: ";
    Node* temp = root;
    std::stack<Node *> address;
    while(temp!=NULL || !address.empty())
    {
        if(temp != NULL){ //terus ke kiri
            address.push(temp);
            temp = temp->left;
        }else{
            temp = address.top();
            address.pop();
            std::cout << temp->info;
            temp = temp->right; //pindah ke kanan
        }
    }
}

void Postorder(Node* root) 
{
    std::cout << "Postorder/Postfix: ";
    Node* temp = root;
    std::stack<Node*> address1;
    std::stack<Node*> address2;
    address1.push(temp);

    while(!address1.empty())
    {
        temp = address1.top();
        address1.pop();
        address2.push(temp);
        if(temp->left != NULL){
            address1.push(temp->left);
        }
        if(temp->right != NULL){
            address1.push(temp->right);
        }
    }

    while(!address2.empty())
    {
        temp = address2.top();
        std::cout << temp->info;
        address2.pop();
    }
}

void MaxDepth(Node *root)
{
    std::cout << "\nKedalaman: ";
    Node *temp = root;
    if (temp == NULL){ //jika tree kosong
        std::cout << "Tree kosong!" << std::endl;
        return;
    }

    int count = -1; //karena root tidak terhitung
    std::queue<Node*> address;
    address.push(temp);

    while(!address.empty())
    {
        count++;
        int size = address.size();
        while(size > 0)
        {
            size--;
            temp = address.front();
            address.pop();
            if(temp->left != NULL){
                address.push(temp->left);
            }
            if(temp->right != NULL){
                address.push(temp->right);
            }
        }
    }
    std::cout << count;
}

void NodeAmount(Node *root)
{
    std::cout << "\nJumlah Simpul: ";
    Node *temp = root;

    if (temp == NULL){ //jika tree kosong
        std::cout << "Tree kosong!" << std::endl;
        return;
    }
     
    std::queue<Node *> address;
    int count = 0; 
    address.push(temp);

    while(!address.empty()){
        temp = address.front();
        address.pop();

        if(temp != NULL){
            count++;
        }

        if(temp->left != NULL){
            address.push(temp->left);
        }
        if(temp->right != NULL){
            address.push(temp->right);
        }
    }
    std::cout << count;
}

int main()
{
    std::stack<Node *> Operand;
    std::stack<Node *> Operator;
    std::string perhitungan;

    std::cout << "masukkan perhitungan:", std::getline(std::cin, perhitungan);

    for(int i=0; i<perhitungan.length(); i++)
    {
        if(perhitungan[i]=='+' || perhitungan[i]=='-' || perhitungan[i]=='/' || perhitungan[i]=='*' || perhitungan[i]=='(')
        {
            Node *temp = CreateNode(perhitungan[i]);
            Operator.push(temp);

        }
        if(perhitungan[i] >= 'A' && perhitungan[i] <= 'Z' || perhitungan[i] >= 'a' && perhitungan[i] <= 'z'){
            Node *temp = CreateNode(perhitungan[i]);
            Operand.push(temp);

        }
        if(perhitungan[i]==')' || i==perhitungan.length()-1){
            //stack operator
            Node *temp = Operator.top(); //node induk atau root
            Operator.pop();

            //stack Operand
            InsertNode(temp, Operand.top());
            Operand.pop();
            InsertNode(temp, Operand.top());
            Operand.pop();

            //memasukkan node induk pada stack operand
            Operand.push(temp);
        }
    }

    while(!Operator.empty())
    {
        if(Operator.top()->info == ')' || Operator.top()->info == '('){
            Operator.pop();
        }else{
            //stack operator
            Node *temp = Operator.top(); //node induk atau root
            Operator.pop();

            //stack Operand
            InsertNode(temp, Operand.top());
            Operand.pop();
            InsertNode(temp, Operand.top());
            Operand.pop();

            //memasukkan node induk pada stack operand
            Operand.push(temp);
        }  
    }

    std::cout << std::endl;
    std::stack<Node *> tempStack;
    tempStack = Operand;
    while(!tempStack.empty())
    {
        Preorder(tempStack.top());
        tempStack.pop();
    }

    std::cout << std::endl;
    tempStack = Operand;
    while(!tempStack.empty())
    {
        Inorder(tempStack.top());
        tempStack.pop();
    }

    std::cout << std::endl;
    tempStack = Operand;
    while(!tempStack.empty())
    {
        Postorder(tempStack.top());
        tempStack.pop();
    }

    //Menampilakn jumlah node dan kedalaman
    NodeAmount(Operand.top());
    MaxDepth(Operand.top());

    //semua stack dihapus
    while(!Operand.empty())
    {
        Operand.pop();
    }
    while(!Operator.empty())
    {
        Operator.pop();
    }

    return 0;
}
