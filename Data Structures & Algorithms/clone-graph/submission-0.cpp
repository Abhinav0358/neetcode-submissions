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
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> attendance;
        return createNewNode(node, attendance);
    }
    Node* createNewNode(Node* node, unordered_map<int, Node*> &attendance){
        if(!node)return nullptr;
        if(attendance.find(node->val)!=attendance.end()){
            return attendance[node->val];
        }
        Node * thisnode=new Node(node->val);
        attendance[node->val]=thisnode;
        // for(Node * neighbor : node->neighbors){
        //     if(attendance.find(neighbor->val)==attendance.end()){
        //         Node*newneighbor=new Node(neighbor->val);
        //         attendance[neighbor->val]=newneighbor;
        //         newneighbor->neighbors.push_back(thisnode);
        //         thisnode->neighbors.push_back(newneighbor);
        //     }
        // }
        
        for(Node * neighbor : node->neighbors){
            thisnode->neighbors.push_back(createNewNode(neighbor,attendance));
        }
        return thisnode;
    }
};
