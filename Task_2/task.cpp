#include <fstream>
#include "functions.h"

int main ()
{
	std::string file_name = "variance_calc.tsv";
	// std::string file_name = "res.tsv";
	// std::string file_name = "row.tsv";
	std::array <double, 262144> numbers;
	std::array <double, 262144> moving_average;
	std::map <std::string, double> res_for_average;
	std::map <std::string, double> res_for_deviation;

	std::ifstream ifs (file_name, std::ios::in);
	if (!ifs.is_open ())
	{
		std::cerr << "Failed to open!" << std::endl;
	}
	else
	{
		size_t count = 0;
		double l_m_aver = 0.0;
		do
		{
			ifs >> numbers[count];
			count++;
			if (count == 262144 && !ifs.eof ())
			{
				static size_t cn = 1;
				if (cn == 1)
				{
					l_m_aver = Processing (numbers[0], count, numbers, moving_average, res_for_average, res_for_deviation);
					count = 0;
				}
				else
				{
					l_m_aver = Processing (l_m_aver, count, numbers, moving_average, res_for_average, res_for_deviation);
					count = 0;
				}
				cn++;
			}
			else if (count <= 262144 && ifs.eof ())
			{
				Processing (l_m_aver, --count, numbers, moving_average, res_for_average, res_for_deviation);
			}
		}
		while (!ifs.eof ());
	}

	ifs.close ();

	PrintRes (res_for_average, " moving average");
	PrintRes (res_for_deviation, " standard deviation");

	return 0;
}
