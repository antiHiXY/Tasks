#pragma once

#include <sstream>
#include <string>


class Figure
{
    public:
        Figure (std::string color);

        virtual std::string Name () = 0;
        virtual std::string Color () = 0;
        virtual double Perim () = 0;
        virtual double Area () = 0;
        virtual ~Figure () {}

    protected:
        virtual void CalculatePerim () = 0;
        virtual void CalculateArea () = 0;

        std::string color_;
        double perim_ = 0;
        double area_ = 0;
};

class Square : public Figure
{
    public:
        Square (double side, std::string color);

        std::string Name () override;
        std::string Color () override;
        double Perim () override;
        double Area () override;

    private:
        void CalculatePerim () override;
        void CalculateArea () override;

        double side_;
};  

class Circle : public Figure
{
    public:
        Circle (double radius, std::string color);

        std::string Name () override;
        std::string Color () override;
        double Perim () override;
        double Area () override;

    private:
        void CalculatePerim () override;
        void CalculateArea () override;
        
        double radius_;
};

class Rectangle : public Figure
{
    public:
        Rectangle (double length, double width, std::string color);
        
        std::string Name () override;
        std::string Color () override;
        double Perim () override;
        double Area () override;

    private:
        void CalculatePerim () override;
        void CalculateArea () override;
        
        double length_;
        double width_;
};

class Triangle : public Figure
{
    public:
        Triangle (double side_f, double side_s, double side_t, std::string color);

        std::string Name () override;
        std::string Color () override;
        double Perim () override;
        double Area () override;

    private:
        void CalculatePerim () override;
        void CalculateArea () override;

        double side_first_;
        double side_second_;
        double side_third_;
};

std::shared_ptr <Figure> CreateFigure (std::istringstream &iss);