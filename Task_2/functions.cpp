#include "functions.h"


void WriteRes (std::map <std::string, double> &a, double avrg, std::map <std::string, double> &d, double dvtn, int key)
{
	std::string str_key = std::to_string (key);
	a[str_key] = avrg;
	d[str_key] = dvtn;
}

void PrintRes (const std::map <std::string, double> &res_map, const std::string &type)
{
	std::cout.precision(32);
	for (const auto &el : res_map)
	{
		std::cout  << "For " << el.first << type << " is " << el.second << std::endl;
	}
}

double Processing (double last_aver, int step, const std::array <double, 262144> &num, std::array <double, 262144> &aver,
	 			   std::map <std::string, double> &res_aver, std::map <std::string, double> &res_dev)
{
	static size_t amount = 0;
	static double sum_sq_elem = 0.0;
	static double dev = 0.0;

	for (int i = 0; i < step; ++i)
	{
		if (i == 0)
		{
			aver[i] = (last_aver * static_cast <double> (amount) + static_cast <double> (num[i])) / static_cast <double> (amount + 1);
			amount++;
		}
		else
		{
			aver[i] = (aver[i - 1] * static_cast <double> (amount) + static_cast <double> (num[i])) / static_cast <double> (amount + 1);
			amount++;
		}
		if (amount - 1 == 0)
		{
			double sum_el = num[0];
			sum_sq_elem = num[0] * num[0];
		}
		else
		{
			sum_sq_elem += (num[i] * num[i]);
			dev = (1.0 / sqrt (static_cast <double> (amount - 1))) * sqrt (-static_cast <double> (amount) * (aver[i] * aver[i]) + sum_sq_elem);
		}
		if (amount == 1 || amount == 100 || amount == 1000000 || amount == 500000000)
		{
			WriteRes (res_aver, aver[i], res_dev, dev, amount);
		}
	}
	return aver[step - 1];
}
