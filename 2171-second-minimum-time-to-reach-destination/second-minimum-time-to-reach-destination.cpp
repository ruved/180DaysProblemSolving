
// Representation of a node 
class Node {
public:
    Node(int num) : _num (num) {}

    void addEdge(Node* node) {
        _edges.push_back(node);
    }

    const vector<Node*>& getEdges() const {
        return _edges;
    }

    void visit(const int time) {
        if (!_visitedTimes.empty() && _visitedTimes.back() == time) {
           // Do not record the same time multiple times. We need to get 'second-best' time
           return;
        }
        _visitedTimes.push_back(time);
    }

    bool canVisit() const {
        return _visitedTimes.size() < MaxVisits;
    }

    int getNum() const {
        return _num;
    }

private:
    static const int MaxVisits = 2;
    const int _num;

    vector<Node*> _edges;

    // Remember how many times this node has been visited. 
    // Allow only 2 different times as we need the second best answer
    vector<int> _visitedTimes;
};


class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        buildNodes(edges);

        int firstTime = 0;
        int curTime = 0;

        queue<Node*> q;
        Node* head = _nodes[1];
        head->visit(curTime);
        q.push(head);

        // Breadth-first search
        while (!q.empty()) {
            curTime = adjustTime(curTime, change);
            const int arrivalTime = curTime + time;
            const int qCount = (int) q.size(); // queue count for this given time

            // through all the nodes being visited at [curTime]
            for (int i = 0; i < qCount; i ++) {
                Node* node = q.front(); q.pop();

                // through all target nodes to be visited at [arrivalTime]
                for (Node* edge : node->getEdges()) {

                    // Check if it's possible to visit (only allowed 2 different times)
                    if (edge->canVisit()) {

                        // Check if we're at the goal!
                        if (edge->getNum() == n) {
                            if (firstTime == 0) {
                                firstTime = arrivalTime;
                            } else if (arrivalTime > firstTime) { // Found!!
                                return arrivalTime;
                            }
                        }

                        edge->visit(arrivalTime);
                        q.push(edge);
                    } 
                }
            }
            curTime = arrivalTime;
        }

        // Failure - shouldn't happen
        return -1;
    }
private:
    map<int, Node*> _nodes;

    int adjustTime(int curTime, const int change) {

        if ((curTime / change) % 2 == 0) {
            return curTime;
        }

        return (curTime + change) / change * change;
    }

    void buildNodes(const vector<vector<int>>& edges) {
        for (const vector<int>& edge : edges) {
            Node* node1 = createOrGetNode(edge.front());
            Node* node2 = createOrGetNode(edge.back());
            node1->addEdge(node2);
            node2->addEdge(node1);
        }
    }

    Node* createOrGetNode(const int num) {
        if (auto ite = _nodes.find(num); ite != _nodes.end()) {
            return ite->second;
        }
        auto node = new Node(num);
        _nodes[num] = node;
        return node;
    }
};