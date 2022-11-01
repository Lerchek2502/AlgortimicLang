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

using tube_func = void(*)(unordered_map <int, tube>& p, int id);
void edit_tube(unordered_map <int, tube>& mp, int id);
void delete_tube(unordered_map <int, tube>& mp, int id);
void effect_tube(unordered_map <int, tube>& mp, tube_func func);

void add_CS(unordered_map <int, CS>& mp);

using CS_func = void(*)(unordered_map <int, CS>& p, int id);
void edit_cs(unordered_map <int, CS>& mp, int id);
void delete_cs(unordered_map <int, CS>& mp, int id);
void effect_cs(unordered_map <int, CS>& mp, CS_func func);

void disp_all(const unordered_map <int, tube>& mp_pipe, const unordered_map <int, CS>& mp_cs);

void save(const unordered_map <int, tube>& mp_pipe, const unordered_map <int, CS>& mp_cs);
void upload(unordered_map <int, tube>& mp_pipe, unordered_map <int, CS>& mp_cs);
