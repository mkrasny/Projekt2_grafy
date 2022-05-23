#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <climits>
#include "../inc/array_graph.hpp"

int MAXX = INT_MAX;

int array_graph::read_from_file(std::string name)
{
    int b, e, w, start;
    std::fstream file;
    file.open(name, std::ios::in);

    if (file.good())
    {
        file >> edges >> vertices >> start;
        arr_ptr = new int *[vertices];

        for (int i = 0; i < vertices; i++)
        {
            arr_ptr[i] = new int[vertices];
        }
        array_graph::clear();

        while (!file.fail())
        {
            file >> b >> e >> w;
            array_graph::arr_ptr[b][e] = w;
        }
    }
    file.close();

    return start;
}

void array_graph::print_graph()
{
    for (int i = 0; i < vertices; i++)
    {
        std::cout << i << '\n';
        for (int j = 0; j < vertices; j++)
        {
            if (arr_ptr[i][j] != MAXX)
            {
                std::cout << i << ' ' << arr_ptr[i][j] << ' ' << j << '\n';
            }
        }
    }
}

void array_graph::generate_random()
{
    int b, e, w, num_of_edges;
    int tmp[vertices];

    for (int i = 0; i < vertices; i++)
    {
        tmp[i] = 0;
    }

    array_graph::clear();

    num_of_edges = density * vertices * (vertices - 1)/100;

    for (int i = 0; i < num_of_edges; i++)
    {
        do
        {
            b = rand() % vertices;
        } while (tmp[b] >= (vertices-1));

        do
        {
            e = rand() % vertices;
        } while (e == b || arr_ptr[b][e] != MAXX);

        do
        {
            w = rand() % 50;
        } while (w == 0);

        arr_ptr[b][e] = w;
        tmp[b]++;
    }
}

void array_graph::clear()
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            arr_ptr[i][j] = MAXX;
        }
        
    }
    
}