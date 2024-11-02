//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Helper function to create a parent map for all nodes and count nodes
    void createParentMap(unordered_map<Node*, Node*>& parent, Node* root) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if (node->left != NULL) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right != NULL) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    // Function to find minimum time required to burn the tree
    int minTime(Node* root, int target) {
        // Map to store the parent pointers of each node
        unordered_map<Node*, Node*> parent;
        createParentMap(parent, root);
        
        // Find target node in the tree
        Node* targetNode = nullptr;
        queue<Node*> findTargetQueue;
        findTargetQueue.push(root);
        while (!findTargetQueue.empty()) {
            Node* node = findTargetQueue.front();
            findTargetQueue.pop();
            if (node->data == target) {
                targetNode = node;
                break;
            }
            if (node->left) findTargetQueue.push(node->left);
            if (node->right) findTargetQueue.push(node->right);
        }
        
        if (targetNode == nullptr) return 0;

        // To track visited nodes and avoid revisiting them
        unordered_map<Node*, bool> visited;
        queue<Node*> burnQueue;
        burnQueue.push(targetNode);
        visited[targetNode] = true;
        
        int burnt = 0;
        
        // BFS to simulate burning process level by level
        while (!burnQueue.empty()) {
            int size = burnQueue.size();
            burnt++; // Increment time for each level

            for (int i = 0; i < size; i++) {
                Node* node = burnQueue.front();
                burnQueue.pop();

                // Check left child
                if (node->left && !visited[node->left]) {
                    burnQueue.push(node->left);
                    visited[node->left] = true;
                }
                
                // Check right child
                if (node->right && !visited[node->right]) {
                    burnQueue.push(node->right);
                    visited[node->right] = true;
                }
                
                // Check parent
                if (parent.find(node) != parent.end() && !visited[parent[node]]) {
                    burnQueue.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
        }
        
        // `burnt` includes an extra increment, so return `burnt - 1`
        return burnt - 1;
    }
};


//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    
cout << "~" << "\n";
}


    return 0;
}

// } Driver Code Ends