#pragma once
#include <iostream>
#include <fstream>
#include <string>

class graph
{

public:
    int edges, vertices, density;

    int getEdges() { return edges; }
    int getVertices() { return vertices; }
    int getDensity() { return density; }
    virtual int read_from_file(std::string name) = 0;
    virtual void print_graph() = 0;
    virtual void generate_random() = 0;
    virtual void clear() = 0;
    graph()
    {
        vertices = 0;
        density = 0;
        edges = 0;
    }
    graph(int ver, int den)
    {
        vertices = ver;
        density = den;
    }
};
