#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "../inc/graph.hpp"

class array_graph : public graph
{
private:
    int **arr_ptr;

public:
    int getWeight(int start, int end) { return arr_ptr[start][end]; }
    int read_from_file(std::string name);
    void print_graph();
    void generate_random();
    void clear();
    array_graph() : graph(){};
    array_graph(int ver, int den) : graph(ver, den)
    {
        arr_ptr = new int *[ver];
        for (int i = 0; i < ver; i++)
        {
            arr_ptr[i] = new int[ver];
        }
    }
};
