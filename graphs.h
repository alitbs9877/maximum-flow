#ifndef GRAPHS_H
#define GRAPHS_H


class Graphs
{
public:
    int V;
    vector<Vertex> ver;
    vector<Edge> edge;
    bool push(int u);
    void relabel(int u);
    void preflow(int s);
    void updateReverseEdgeFlow(int i, int flow);
    Graphs(int V);
    void addEdge(int u, int v, int w);
    int getMaxFlow(int s, int t);
};

#endif // GRAPHS_H
