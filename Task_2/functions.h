#pragma once

#include <string>
#include <array>
#include <map>
#include <cmath>
#include <iostream>

void WriteRes (std::map <std::string, double> &a, double avrg, std::map <std::string, double> &d, double dvtn, int key);

void PrintRes (const std::map <std::string, double> &res_map,const std::string &type);

double Processing (double last_aver, int step, const std::array <double, 262144> &num, std::array <double, 262144> &aver,
	 			   std::map <std::string, double> &res_aver, std::map <std::string, double> &res_dev);
