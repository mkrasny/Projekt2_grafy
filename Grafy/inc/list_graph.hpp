#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "../inc/graph.hpp"

class edge
{

public:
    int begin, end, weight;
    edge *next;

    int getBegin() { return begin; }
    const int getEnd() { return end; }
    int getWeight() { return weight; }
    void mod(int b, int e, int w);
    void addNext(edge *newEdge);
    edge *getNext() { return next; }
    
};

class edgeList
{

public:
    edge *first;
    int elSize;

    edge *getFirst() { return first; }
    int getSize() { return elSize; }
    void addEdge(int b, int e, int w);
    void printEdgeList();
    edgeList()
    {
        first = NULL;
        elSize = 0;
    }
};

class list_graph : public graph
{

public:
    edgeList *tab;
    edge *getFront(int ver) { return tab[ver].getFirst(); }
    int getSizeG(int ver) { return tab[ver].getSize(); }
    int read_from_file(std::string name);
    void generate_random();
    void print_graph();
    void clear();
    list_graph(int ver, int den) : graph(ver, den) { tab = new edgeList[ver]; }
    list_graph() : graph(){};
};
