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

    unordered_map<Node* , Node*>copies;

    Node* cloneGraph(Node* node) {


        if(!node) return nullptr;

        if(copies.find(node) != copies.end()){
            return copies[node];
        }

        Node *clone = new Node(node->val);

        copies[node] = clone;

        for(Node* neighbor : node->neighbors){
            Node *cloneneighbors = cloneGraph(neighbor);
            clone->neighbors.push_back(cloneneighbors);
        }
        
        return clone;

    }
};
