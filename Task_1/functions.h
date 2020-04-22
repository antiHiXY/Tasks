#pragma once

#include <vector>
#include <map>
#include <iostream>

size_t CheckCorrectInput (std::istream &is);

void FillVec (std::vector <unsigned int> &v);

void PrintVec (const std::vector <unsigned int> &v);

void FillMap (std::map <unsigned int, unsigned int> &m, size_t size);

void PrintMap (const std::map <unsigned int, unsigned int> &m);

bool FindInMap (const std::map <unsigned int, unsigned int> &m, const std::vector <unsigned int>::iterator &v_it);

void Synch (std::map <unsigned int, unsigned int> &m, std::vector <unsigned int> &v);

void DelElemVec (std::vector <unsigned int> &v);

void DelElemMap (std::map <unsigned int, unsigned int> &m);
