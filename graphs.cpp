#include "graphs.h"

Graphs::Graphs(int V)
{
    this->V = V;
    for (int i = 0; i < V; i++)
        ver.push_back(Vertex(0, 0));
}

void Graphs::addEdge(int u, int v, int capacity)
{
    edge.push_back(Edge(0, capacity, u, v));
}

void Graphs::preflow(int s)
{
    ver[s].h = ver.size();
    for (int i = 0; i < edge.size(); i++)
    {
        if (edge[i].u == s)
        {
            edge[i].flow = edge[i].capacity;
            ver[edge[i].v].e_flow += edge[i].flow;
            edge.push_back(Edge(-edge[i].flow, 0, edge[i].v, s));
        }
    }
}
int overFlowVertex(vector<Vertex>& ver)
{
    for (int i = 1; i < ver.size() - 1; i++)
    if (ver[i].e_flow > 0)
            return i;
    return -1;
}
void Graphs::updateReverseEdgeFlow(int i, int flow)
{
    int u = edge[i].v, v = edge[i].u;

    for (int j = 0; j < edge.size(); j++)
    {
        if (edge[j].v == v && edge[j].u == u)
        {
            edge[j].flow -= flow;
            return;
        }
    }
    Edge e = Edge(0, flow, u, v);
    edge.push_back(e);
}
bool Graphs::push(int u)
{
    for (int i = 0; i < edge.size(); i++)
    {
        if (edge[i].u == u)
        {
            if (edge[i].flow == edge[i].capacity)
                continue;
            if (ver[u].h > ver[edge[i].v].h)
            {
                int flow = min(edge[i].capacity - edge[i].flow,
                            ver[u].e_flow);
                ver[u].e_flow -= flow;
                ver[edge[i].v].e_flow += flow;
                edge[i].flow += flow;
                updateReverseEdgeFlow(i, flow);
                return true;
            }
        }
    }
    return false;
}
void Graphs::relabel(int u)
{
    int mh = INT_MAX;
    for (int i = 0; i < edge.size(); i++)
    {
        if (edge[i].u == u)
        {
            if (edge[i].flow == edge[i].capacity)
                continue;
            if (ver[edge[i].v].h < mh)
            {
                mh = ver[edge[i].v].h;
                ver[u].h = mh + 1;
            }
        }
    }
}
int Graphs::getMaxFlow(int s, int t)
{
    preflow(s);
    while (overFlowVertex(ver) != -1)
    {
        int u = overFlowVertex(ver);
        if (!push(u))
            relabel(u);
    }
    return ver.back().e_flow;
}
