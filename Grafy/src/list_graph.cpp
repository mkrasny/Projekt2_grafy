#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "../inc/list_graph.hpp"

void edge::mod(int b, int e, int w)
{
    begin = b;
    end = e;
    weight = w;
}

void edge::addNext(edge *newEdge)
{
    next = new edge;
    next = newEdge;
}

void edgeList::addEdge(int b, int e, int w)
{
    edge *newEdge = new edge;
    newEdge->mod(b, e, w);

    if (first == NULL)
    {
        first = newEdge;
        //std::cout<<"rozm"<<elSize<<'\n';
    }
    else
    {
        edge *tmp = first;
        first = newEdge;
        newEdge->addNext(tmp);
        //std::cout<<"rozm"<<elSize<<'\n';
    }
    ++elSize;
}

void edgeList::printEdgeList()
{
    edge *tmp = first;

    while (tmp)
    {
        std::cout << tmp->getBegin() << ' ' << tmp->getEnd() << ' ' << tmp->getWeight() << '\n';
        tmp = tmp->getNext();
    }
}

int list_graph::read_from_file(std::string name)
{
    int b, e, w, start;
    std::fstream file;
    file.open(name, std::ios::in);

    if (file.good())
    {
        file >> edges >> vertices >> start;

        tab = new edgeList[vertices];

        while(!file.fail())
        {
            file >> b >> e >> w;
            tab[b].addEdge(b, e, w);
        }
    }
    file.close();

    return start;
}

void list_graph::generate_random()
{
    int b, e, w, num_of_edges;
    int **tmp = new int *[vertices];

    for (int i = 0; i < vertices; i++)
    {
        tmp[i] = new int [vertices];
    }
    

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            tmp[i][j] = 0;
        }
    }

    std::cout<<"AAAAAAA"<<'\n';
    list_graph::clear();
    std::cout<<"AAAAAAA"<<'\n';

    num_of_edges = density * vertices*(vertices - 1)/100;

    for (int i = 0; i < num_of_edges; i++)
    {
        do
        {
            b = rand() % vertices;
        } while (tab[b].getSize() == (vertices - 1));

        do
        {
            e = rand() % vertices;
        } while (e == b || tmp[b][e] == 1);

        do
        {
            w = rand() % 50;
        } while (w == 0);

        tmp[b][e] = 1;
        tab[b].addEdge(b, e, w);
    }

    std::cout<<"BBBBBB"<<'\n';
    for (int i = 0; i < vertices; i++)
    {
        delete [] tmp[i];
    }

    delete [] tmp;
    
}

void list_graph::print_graph()
{
    int ver = list_graph::getVertices();

    for (int i = 0; i < ver; i++)
    {
        std::cout << i << '\n';
        tab[i].printEdgeList();
    }
    
}

void list_graph::clear()
{
    delete[] tab;
    tab = new edgeList[vertices];
}