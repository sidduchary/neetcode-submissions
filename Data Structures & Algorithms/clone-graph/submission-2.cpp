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
private:
    void dfs(Node* &node, Node* &newnode, unordered_map<Node*, Node*> &visMap) {
        visMap[node] = newnode;
        for(auto& it: node->neighbors) {
            if (visMap.find(it) == visMap.end()) {
                Node* neigh = new Node(it->val);
                visMap[it] = neigh;
                newnode->neighbors.push_back(neigh);
                dfs(it, neigh, visMap);
            } else {
                newnode->neighbors.push_back(visMap[it]);
            }
        }
        return;
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        Node* newnode = new Node(node->val);
        unordered_map<Node*, Node*> visMap;

        dfs(node, newnode, visMap);
        return newnode;
    }
};
