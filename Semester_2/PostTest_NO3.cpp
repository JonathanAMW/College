#include <iostream>

struct Node
{
    int data;
    Node* next;
};
 
void printList(std::string msg, Node* head)
{
    std::cout << msg;
 
    Node* ptr = head;
    while (ptr)
    {
        std::cout << ptr->data << "->";
        ptr = ptr->next;
    }
 
    std::cout << "null" << std::endl;
}


void insert(Node** head, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void reverse(Node* &head, int m, int n)
{
    if (m > n) { //jika tidak masuk akal
        return;
    }
 
    Node* prev = NULL;
    Node* temp = head;  
 
    // 1. Skip the first `m` nodes
    for (int i = 1; temp != NULL && i < m; i++)
    {
        prev = temp;
        temp = temp->next;
    }
 
    Node* start = temp;
    Node* end = NULL;
 
    for (int i = 1; temp != NULL && i <= n - m + 1; i++)
    {
        Node* next = temp->next;

        temp->next = end;
        end = temp;
 
        temp = next;
    }
 
    if (start)
    {
        start->next = temp;
        if (prev != NULL) {
            prev->next = end;
        }
        else {
            head = end;
        }
    }
}

void reverseall(Node* &head) 
{
    Node* temp = head;
    Node *prev = NULL, *next = NULL;

    while (temp != NULL) {

        next = temp->next;

        temp->next = prev;

        prev = temp;
        temp = next;
    }
    head = prev;
}
 
int main()
{
    int m = 1, n = 7, size=0, input;
    char pilihan;
    
    std::cout << "m=" << m;
    std::cout << ", n=" << n << std::endl;
    Node* head = NULL;
    
    /*while(pilihan!='y')
    {
        std::cout << "masukkan node: ", std::cin >> input;
        std::cin.ignore();
        insert(&head, input);
        size++;
        
        std::cout << "selesai?(y/t): ", std::cin >> pilihan;
        std::cin.ignore();
    }*/
    
    for (int i = 7; i >= 1; i--) {
        insert(&head, i);
    }
    size=7;
 
    printList("Input: ", head);
    if(m==1 && n==size){
        reverseall(head);
        printList("Setelah direverse: ", head);
    }else{
        reverse(head, m, n);
        printList("Setelah direverse: ", head);
    }
 
    return 0;
}
