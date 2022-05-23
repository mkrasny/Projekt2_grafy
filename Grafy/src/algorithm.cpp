#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <chrono>
#include <climits>
#include "../inc/algorithm.hpp"

int MAX = 2137420;

bool BF_list(list_graph G, int start, std::fstream &save)
{
    int ver = G.getVertices();
    //std::cout<<"size"<<ver<<'\n';
    int distance[ver];
    int path[ver];
    int v, u, k;
    edge *tmp;

    for (int i = 0; i < ver; i++)
    {
        distance[i] = MAX;
        path[i] = -1;
    }

    distance[start] = 0;

    std::chrono::time_point<std::chrono::system_clock> T1, T2;
    double time;

    T1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < (ver - 1); i++)
    {
        for (int j = 0; j < ver; j++)
        {
            tmp = G.getFront(j);
            v = j;

            while (tmp)
            {
                //std::cout<<"T"<<'\n';
                try
                {
                    u = tmp->getEnd();
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }

                //std::cout<<"U"<<'\n';
                k = tmp->getWeight();

                //std::cout<<"DV+K"<<distance[v]+k<<'\n';
                //std::cout<<"DU"<<distance[u]<<'\n'<<'\n';
                if (distance[u] > distance[v] + k)
                {

                    distance[u] = distance[v] + k;
                    path[u] = v;
                }
                tmp = tmp->getNext();
            }
        }
    }

    delete tmp;
    for (int i = 0; i < (ver - 1); i++)
    {
        for (int j = 0; j < ver; j++)
        {
            tmp = G.getFront(j);
            v = j;

            while (tmp)
            {
                u = tmp->getEnd();
                k = tmp->getWeight();

                if (distance[u] > distance[v] + k)
                {
                    return false;
                }
                tmp = tmp->getNext();
            }
        }
    }
    delete tmp;
    T2 = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration<double, std::milli>(T2 - T1).count();

    save << G.getVertices() << "   " << G.getDensity() << "   " << time << '\n';

    /*for (int i = 0; i < ver; i++)
    {
        std::cout<<i<<"   "<<distance[i]<<'\n';
    }*/
    save2file(distance, path, ver, start);

    return true;
}

bool BF_array(array_graph G, int start, std::fstream &save)
{
    int ver = G.getVertices();
    int distance[ver];
    int path[ver];
    int v, u, w;
    edge *tmp;

    //G.print_graph();
    for (int i = 0; i < ver; i++)
    {
        distance[i] = MAX;
        path[i] = -1;
    }

    distance[start] = 0;

    std::chrono::time_point<std::chrono::system_clock> T1, T2;
    double time;

    T1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < (ver - 1); i++)
    {
        for (int j = 0; j < ver; j++)
        {

            for (int q = 0; q < ver; q++)
            {
                w = G.getWeight(j, q);
                //std::cout << "waga" << w << '\n';
                //std::cout<<"DQ"<<distance[q]<<'\n';
                //std::cout<<"DJ+w"<<distance[j]+w<<'\n'<<'\n';
                if (w < MAX)
                {

                    if (distance[q] > distance[j] + w)
                    {
                        distance[q] = distance[j] + w;
                        path[q] = j;
                        //std::cout<<"DQ"<<distance[q]<<'\n';
                    }
                }
            }
        }
    }

    for (int i = 0; i < (ver - 1); i++)
    {
        for (int j = 0; j < ver; j++)
        {
            for (int q = 0; q < ver; q++)
            {
                if (G.getWeight(j, q) < MAX)
                {
                    if (distance[q] > distance[j] + G.getWeight(j, q))
                    {
                        return false;
                    }
                }
            }
        }
    }

    T2 = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration<double, std::milli>(T2 - T1).count();

    save << G.getVertices() << "   " << G.getDensity() << "   " << time << '\n';

    /*for (int i = 0; i < ver; i++)
    {
        std::cout << i << "   " << distance[i] << '\n';
    }*/

    //save2file(distance, path, ver, start);
    return true;
}

bool save2file(int distance[], int path[], int size, int start)
{
    int Tab[size][size];
    int p, q;
    std::fstream file;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            Tab[i][j] = -1;
        }
    }

    for (int i = 0; i < size; i++)
    {
        p = 0;
        q = i;

        while (q != start && q != -1)
        {
            Tab[i][p] = path[q];
            ++p;
            q = path[q];
        }
    }

    file.open("wynik.txt", std::ios::out);

    for (int i = 0; i < size; i++)
    {
        file << "nr: " << i << " koszt: " << distance[i] << " sciezka: ";
        for (int j = size - 1; j >= 0; j--)
        {
            if (Tab[i][j] != -1)
            {
                file << Tab[i][j] << ' ';
            }
        }
        file << '\n';
    }
    file.close();
    return true;
}