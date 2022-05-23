#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <chrono>
#include "../inc/list_graph.hpp"
#include "../inc/array_graph.hpp"

bool BF_list(list_graph G, int start, std::fstream &save);
bool BF_array(array_graph G, int start, std::fstream &save);
bool save2file(int distance[], int path[], int size, int start);