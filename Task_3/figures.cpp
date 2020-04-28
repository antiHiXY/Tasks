#define _USE_MATH_DEFINES

#include "figures.h"
#include <cmath>
#include <stdexcept>

Figure::Figure (std::string color) : color_ (color)
{}

Square::Square (double side, std::string color) : side_ (side), Figure (color)
{
    CalculatePerim ();
    CalculateArea ();
}

std::string Square::Name ()
{
    return "SQUARE";
}

std::string Square::Color ()
{
    return color_;
}

double Square::Perim ()
{
    return perim_;
}

double Square::Area ()
{
    return area_;
}

void Square::CalculatePerim ()
{
    perim_ = side_ * 4.0;
}

void Square::CalculateArea ()
{
    area_ = side_ * side_;
}

Circle::Circle (double radius, std::string color) : radius_ (radius), Figure (color)
{
    CalculatePerim ();
    CalculateArea ();
}

std::string Circle::Name ()
{
    return "CIRCLE";
}

std::string Circle::Color ()
{
    return color_;
}

double Circle::Perim ()
{
    return perim_;
}

double Circle::Area ()
{
    return area_;
}

void Circle::CalculatePerim ()
{
    perim_ = 2.0 * M_PI * radius_;
}

void Circle::CalculateArea ()
{
    area_ = radius_ * radius_ * M_PI;
}

Rectangle::Rectangle (double length, double width, std::string color) : length_ (length), width_ (width), Figure (color)
{
    CalculatePerim ();
    CalculateArea ();
}

std::string Rectangle::Name ()
{
    return "RECTANGLE";
}

std::string Rectangle::Color ()
{
    return color_;
}

double Rectangle::Perim ()
{
    return perim_;
}

double Rectangle::Area ()
{
    return area_;
}

void Rectangle::CalculatePerim ()
{
    perim_ = 2.0 * (length_ + width_);
}

void Rectangle::CalculateArea ()
{
    area_ = length_ * width_;
}

Triangle::Triangle (double side_f, double side_s, double side_t, std::string color)
                   : side_first_ (side_f), side_second_ (side_s), side_third_ (side_t), Figure (color)
{
    CalculatePerim ();
    CalculateArea ();
}

std::string Triangle::Name ()
{
    return "TRIANGLE";
}

std::string Triangle::Color ()
{
    return color_;
}

double Triangle::Perim ()
{
    return perim_;
}

double Triangle::Area ()
{
    return area_;
}

void Triangle::CalculatePerim ()
{
    perim_ = side_first_ + side_second_ + side_third_;
}

void Triangle::CalculateArea ()
{
    double half_perim = (side_first_ + side_second_ + side_third_) / 2.0;
    area_ = sqrt (half_perim * (half_perim - side_first_) * (half_perim - side_second_) * (half_perim - side_third_));
}

std::shared_ptr <Figure> CreateFigure (std::istringstream &iss)
{
    std::string figure;
    std::string color;

    iss >> figure;
    iss >> color;

    if (!figure.compare ("SQUARE"))
    {
        double first;

        iss >> first;

        return std::make_shared <Square> (first, color);
    }
    else if (!figure.compare ("CIRCLE"))
    {
        double first;

        iss >> first;

        return std::make_shared <Circle> (first, color);
    }
    else if (!figure.compare ("RECTANGLE"))
    {
        double first, second;

        iss >> first >> second;

        return std::make_shared <Rectangle> (first, second, color);
    }
    else if (!figure.compare ("TRIANGLE"))
    {
        double first, second, third;

        iss >> first >> second >> third;

        return std::make_shared <Triangle> (first, second, third, color);
    }
    throw std::invalid_argument ("Wrong type of figure!");
}