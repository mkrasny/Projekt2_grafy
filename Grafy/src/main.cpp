#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "../inc/algorithm.hpp"

void testFromFile(std::string name)
{
    int start;
    char rep;

    std::cout << "Wybierz reprezentacje: M - macierz, L - lista" << '\n';
    std::cin >> rep;

    switch (rep)
    {
    case 'M':
    {
        std::fstream saveTestA;
        saveTestA.open("test.txt", std::ios::out);
        array_graph *ArrG = new array_graph();
        start = ArrG->read_from_file(name);
        BF_array(*ArrG, start, saveTestA);
        saveTestA.close();
        break;
    }
    case 'L':
    {
        std::fstream saveTestL;
        saveTestL.open("test.txt", std::ios::out);
        list_graph *ListG = new list_graph();
        start = ListG->read_from_file(name);
        BF_list(*ListG, start, saveTestL);
        saveTestL.close();
        break;
    }
    default:
        std::cout << "Zla opcja" << '\n';
        break;
    }
}

void autoTest()
{
    std::fstream saveArr, saveList;
    list_graph *ListG;
    array_graph *ArrG;

    saveList.open("ResultsList.txt", std::ios::out);
    //saveArr.open("ResultsArray.txt", std::ios::out);

    int ver_num[] = {10, 20, 40, 80, 100};
    int density[] = {25, 50, 75, 100};

    //std::cout<<"AAAA"<<'\n';
    saveList << "Rozmiar"
             << "   "
             << "Gestosc"
             << "   "
             << "Czas " << '\n';
    /*saveArr << "Rozmiar"
            << "   "
            << "Gestosc"
            << "   "
            << "Czas " << '\n';*/

    //std::cout<<"AAAA"<<'\n';
    for (int i = 4; i < 5; i++)
    {
        //std::cout<<"I"<<i<<'\n';
        for (int j = 3; j < 4; j++)
        {
            //std::cout<<"J"<<j<<'\n';

            for (int k = 0; k < 1; k++)
            {
                ListG = new list_graph(ver_num[i], density[j]);
                //ArrG = new array_graph(ver_num[i], density[j]);
                ListG->generate_random();
                //ArrG->generate_random();
                BF_list(*ListG, rand() %ver_num[i], saveList);
                //BF_array(*ArrG, rand() % ver_num[i], saveArr);
                delete ListG;
                //delete ArrG;
            }
        }
    }
    saveList.close();
    //saveArr.close();
}

int main()
{
    int menu;
    std::string name;

    while (1)
    {
        std::cout << "Wybor opcji" << '\n';
        std::cout << "1. Testy automatyczne" << '\n';
        std::cout << "2. Z pliku" << '\n';
        std::cout << "3. Zakoncz" << '\n';

        std::cin >> menu;

        switch (menu)
        {
        case 1:
            autoTest();
            break;

        case 2:
            std::cout << "Podaj nazwe pliku: " << '\n';
            std::cin >> name;
            testFromFile(name);
            break;

        case 3:
            break;
        default:
            std::cout << "Zla opcja" << '\n';
            break;
        }

        if (menu == 3)
        {
            break;
        }
    }
    return 0;
}