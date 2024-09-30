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
    Node* help(Node* node, unordered_map<Node*,Node*>&mp){
        if(!node) return NULL;
        Node* head=new Node(node->val);
        mp[node]=head;
        vector<Node*>neighbors;
        for(int i=0;i<node->neighbors.size();++i){
            if(mp.find(node->neighbors[i])==mp.end())
                head->neighbors.push_back(help(node->neighbors[i],mp));
            else
                head->neighbors.push_back(mp[node->neighbors[i]]);
        }
 
        return head;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mp;
        // if(node==NULL)
        //     return NULL;
        // if(node->neighbors.size()==0)   //if only one node present no neighbors
        // {
        //     Node* clone= new Node(node->val);
        //     return clone; 
        // }
        return help(node,mp);
    }
};
