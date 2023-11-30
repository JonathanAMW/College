#include <iostream>
#include <vector>

struct Node
{
    int data;
    Node* next;
};

Node *head;
Node *head1;
Node *head2;
 
void printList(std::string msg, Node* n)
{
    std::cout << msg;
 
    Node* ptr = n;
    while (ptr)
    {
        std::cout << ptr->data << "->";
        ptr = ptr->next;
    }
 
    std::cout << "null" << std::endl;
}


void insert(Node* n, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = n;
    n = newNode;
}


void tambah(Node *head, Node *head1, Node *head2, int size1, int size2)
{
    int sizetotal;
    std::vector<int> arr1(size1, 0); 
    std::vector<int> arr2(size2, 0);

    if(size1>=size2){
        sizetotal = size1;
    }else if(size2>=size1){
        sizetotal = size2;
    } 
    std::vector<int> arrhasil(sizetotal, 0); 

    Node* ptr = head1;
    int i = size1-1;
    while (ptr)
    {
        if(i == -1){
            break;
        }
        arr1[i] = ptr->data; 
        ptr = ptr->next;
        i--;
    }

    ptr = head2;
    int j = size2-1;
    while (ptr)
    {
        if(j == -1){
            break;
        }
        arr2[j] = ptr->data; 
        ptr = ptr->next;
        j--;
    }

    for(int i=0, j=0; i<size1; i--, j--)
    {
        arrhasil[i]=arr1[i]+arr2[j];
        insert(head, arrhasil[i]);
    }

}

 
int main()
{
    int size1=3, size2=3;
    
    //Node* head = NULL;

    for (int i = size1; i >= 1; i--) {
        insert(head1, i);
    }

    for (int i = 1; i <= size2; i++) {
        insert(head2, i);
    }
 
 
    printList("Input: ", head1);
    printList("Input: ", head2);

    
    printList("Hasil: ", head);

    
 
    return 0;
}
