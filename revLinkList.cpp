#include <iostream>

using namespace std;
  
class Node { 
public: 
    int data; 
    Node* next; 
}; 
  
// This function prints contents of linked list 
// starting from the given node 
void printList(Node* n) 
{ 
    while (n != NULL) { 
        cout << n->data << " "; 
        n = n->next; 
    } 
} 

void reverseLinkedList(Node* n) 
{ 
    Node* head1 = NULL; 
    Node* second1 = NULL; 
    Node* third1 = NULL; 
    Node* fourth1 = NULL;
    
    head1 = new Node(); 
    second1 = new Node(); 
    third1 = new Node(); 
    fourth1 = new Node(); 
    
    //n is head initially
    head1 = n->next->next->next;    //fourth
    second1 = n->next->next; //third
    third1 = n->next; //second
    fourth1 = n;    //head
    
    head1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = NULL;
    
    n = head1;
    
    while (n != NULL) { 
        cout << n->data << " "; 
        n = n->next; 
    } 
}
  
// Driver code 
int main() 
{ 
    Node* head = NULL; 
    Node* second = NULL; 
    Node* third = NULL; 
    Node* fourth = NULL;
  
    // allocate 3 nodes in the heap 
    head = new Node(); 
    second = new Node(); 
    third = new Node(); 
    fourth = new Node(); 
  
    head->data = 1; // assign data in first node 
    head->next = second; // Link first node with second 
  
    second->data = 2; // assign data to second node 
    second->next = third; 
  
    third->data = 3; // assign data to third node 
    third->next = fourth; 
    
    fourth->data = 4; // assign data to third node 
    fourth->next = NULL; 
    
    reverseLinkedList(head);
  
    //printList(head); 
  
    return 0; 
} 