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
        if(!node) return nullptr;

        queue<pair<Node*,Node*>> q;
        Node* newnode = new Node(node->val);
        q.push({node, newnode});
        unordered_map<Node*, Node*> vis;
        vis[node] = newnode;

        while(!q.empty()) {
            Node* old = q.front().first;
            Node* nuw = q.front().second;
            q.pop();
            for(auto &it: old->neighbors) {
                if(vis.find(it) == vis.end()) {
                    Node* neigh = new Node(it->val);
                    q.push({it,neigh});
                    vis[it] = neigh;
                    nuw->neighbors.push_back(neigh);
                }
                else {
                    Node* visNode = vis[it];
                    nuw->neighbors.push_back(visNode);
                }
            }
        }
        return newnode;
    }
};
