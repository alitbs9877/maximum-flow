#ifndef EDGE
#define EDGE
using namespace std;

class Edge
{
public:
    int flow, capacity;
    int u, v;

    Edge(int flow, int capacity, int u, int v)
    {
        this->flow = flow;
        this->capacity = capacity;
        this->u = u;
        this->v = v;
    }
};

#endif // EDGE

