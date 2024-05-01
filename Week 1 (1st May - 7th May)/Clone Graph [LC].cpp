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
    Node* func(Node* node, map<Node*, Node*>& mp){
        if(mp[node]) return mp[node];
        
        Node* newNode = new Node(node->val);
        mp[node] = newNode;

        for(auto &x : node->neighbors){
            newNode -> neighbors.push_back(func(x, mp));
        }

        return newNode;
    }

    Node* cloneGraph(Node* node) {
        if(!node) return node;
        map<Node*, Node*> mp;
        return func(node, mp);
    }
};