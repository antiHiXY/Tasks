#include <list>
#include <iostream>
#include "figures.h"

int main ()
{
    std::list <std::shared_ptr<Figure>> figures;

    for (std::string line; std::getline (std::cin, line);)
    {
        std::istringstream iss (line);
        std::string command;

        iss >> command;

        if (!command.compare ("ADD"))
        {
            try
            {
                figures.push_back (CreateFigure (iss));
            }
            catch (const std::invalid_argument &ex)
            {
                std::cout << ex.what () << std::endl;
            }
        }
        else if (!command.compare ("DELETE"))
        {
            std::string figure;
            std::string color;
            size_t fig_amount = figures.size ();

            iss >> figure;
            iss >> color;

            figures.remove_if ([&figure, &color](auto elem)
            {
                return (!figure.compare (elem->Name ())) && (!color.compare (elem->Color ()));
            });

            if (fig_amount == figures.size ())
            {
                std::cout << "There is no such figure!" << std::endl;
            }
        }
        else if (!command.compare ("PRINT"))
        {
            for (const auto &elem : figures)
            {
                std::cout << "Figure: " << elem -> Name () << ";" << " "
                          << "Color: " << elem -> Color () << ";" << " "
                          << "Perimeter: " << elem -> Perim () << ";" << " "
                          << "Area: " << elem -> Area () << "." << std::endl;
            }
        }
        else
        {
            std::cout << "Unknown command!" << std::endl;
        }
    }
    return 0;
}