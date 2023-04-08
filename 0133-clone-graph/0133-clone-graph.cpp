class Solution
{
public:
    unordered_map<Node *, Node *> u;

    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        if (u.find(node) == u.end())
        {
            u[node] = new Node(node->val);
            for (auto adj : node->neighbors)
            {
                u[node]->neighbors.push_back(cloneGraph(adj));
            }
        }

        return u[node];
    }
};