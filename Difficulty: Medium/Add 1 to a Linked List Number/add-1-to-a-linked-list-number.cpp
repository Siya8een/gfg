//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/
// radhey radhey
class Solution
{
    public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* cur = head;
        while (cur != NULL) {
            Node* front = cur->next;
            cur->next = prev;
            prev = cur;
            cur = front;
        }
        return prev;
    }
    
    Node* addOne(Node *head) {
        if (head == NULL) {
            return head;
        }
        
        Node *temp1 = reverse(head);
        
        Node* temp = temp1;
        int carry = 1;
        
        while (temp != NULL && carry) {
            int sum = temp->data + carry;
            temp->data = sum % 10;
            carry = sum / 10;
            if (carry && temp->next == NULL) {
                temp->next = new Node(carry);
                carry = 0;
            }
            temp = temp->next;
        }
        
        temp1 = reverse(temp1);
        
        return temp1;
    }

};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends