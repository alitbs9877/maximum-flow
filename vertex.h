#ifndef VERTEX
#define VERTEX
class Vertex
{
public:
    int h, e_flow;

    Vertex(int h, int e_flow)
    {
        this->h = h;
        this->e_flow = e_flow;
    }
};
#endif // VERTEX

