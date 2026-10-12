/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* solve(Node* node, unordered_map<int,Node*> &mpp){
        vector<Node*> neigh;
        Node* temp = new Node(node->val);
        mpp[temp->val]=temp;
        for(auto t:node->neighbors){
            if(mpp.find(t->val)==mpp.end()) solve(t,mpp);
            neigh.push_back(mpp[t->val]);
        }
        temp->neighbors = neigh;
        return temp;
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        unordered_map<int,Node*> mpp;
        return solve(node,mpp);
    }
};
