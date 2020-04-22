#include "functions.h"

size_t CheckCorrectInput (std::istream &is)
{
    int input;

    while (true)
    {
        is >> input;
        if (!(is.fail ()) && input > 0)
        {
            return input;
        }
        else
        {
            is.clear ();
            is.ignore (std::numeric_limits <std::streamsize>::max (), '\n');
            std::cout << "Input correct size of containers." << std::endl;
        }
    }
}

void FillVec (std::vector <unsigned int> &v)
{
    for (auto &el : v)
    {
        el = rand () % 9 + 1;
    }
}

void PrintVec (const std::vector <unsigned int> &v)
{
    if (v.empty ())
    {
        std::cout << "Vector is empty." << std::endl;
    }
    else
    {
        std::cout << "Vector values:" << std::endl;
        for (const auto &el : v)
        {
            std::cout << el << ' ';
        }
        std::cout << std::endl;
    }
}

void FillMap (std::map <unsigned int, unsigned int> &m, size_t size)
{
    for (unsigned int i = 0; i < size; ++i)
    {
        m.insert (std::pair <unsigned int, unsigned int> (i, rand () % 9 + 1));
    }
}

void PrintMap (const std::map <unsigned int, unsigned int> &m)
{
    if (m.empty ())
    {
        std::cout << "Map is empty." << std::endl;
    }
    else
    {
        std::cout << "Map values:" << std::endl;
        for (const auto &[key, value] : m)
        {
            std::cout << value << ' ';
        }
        std::cout << std::endl;
    }
}

bool FindInMap (const std::map <unsigned int, unsigned int> &m, const std::vector <unsigned int>::iterator &v_it)
{
    for (auto it = m.begin (); it != m.end (); ++it)
    {
        if (*v_it == it->second)
        {
            return true;
        }
    }
    return false;
}

void Synch (std::map <unsigned int, unsigned int> &m, std::vector <unsigned int> &v)
{
    std::map <unsigned int, unsigned int>::iterator map_begin = m.begin ();
    std::map <unsigned int, unsigned int>::iterator map_end = m.end ();

    std::vector <unsigned int>::iterator vector_begin = v.begin ();
    std::vector <unsigned int>::iterator vector_end = v.end ();

    for (; map_begin != map_end;)
    {
        if (find (vector_begin, vector_end, map_begin->second) == vector_end)
        {
            map_begin = m.erase (map_begin);
        }
        else
        {
            ++map_begin;
        }
    }
    std::vector <unsigned int>::iterator it_vector = v.begin ();
    while (it_vector != v.end ())
    {
        if (!FindInMap (m, it_vector))
        {
            it_vector = v.erase (it_vector);
        }
        else
        {
            ++it_vector;
        }
    }
}

void DelElemVec (std::vector <unsigned int> &v)
{
    unsigned int del_elem = rand () % 15 + 0;
    if (del_elem >= v.size ())
    {
        v.clear ();
    }
    else
    {
        v.erase (v.begin (), v.begin () + del_elem);
    }
}

void DelElemMap (std::map <unsigned int, unsigned int> &m)
{
    unsigned int del_elem = rand () % 15 + 0;
    if (del_elem >= m.size ())
    {
        m.clear ();
    }
    else
    {
        for (auto it = m.begin (); del_elem > 0; --del_elem)
        {
            it = m.erase (it);
        }
    }
}