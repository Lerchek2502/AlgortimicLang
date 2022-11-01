#pragma once
#include "tube.h"
#include "CS.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

int Take_Int(const int a, const int b);
float Take_Float(const float a, const float b);

void disp_menu();

void add_tube(unordered_map <int, tube>& mp);

void add_CS(unordered_map <int, CS>& mp);

void disp_all(const unordered_map <int, tube>& mp_pipe, const unordered_map <int, CS>& mp_cs);
