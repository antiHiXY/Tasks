#include <ctime>
#include "functions.h"

int main ()
{
    size_t size_of_cont = 0;

    std::cout << "Input size of containers." << std::endl;
    size_of_cont = CheckCorrectInput (std::cin);

    std::vector <unsigned int> vector_cont (size_of_cont);
    std::map <unsigned int, unsigned int> map_cont;

    std::srand (unsigned (std::time (0)));

    FillVec (vector_cont);
    FillMap (map_cont, size_of_cont);

    std::cout << "Initial containers:" << std::endl;
    PrintVec (vector_cont);
    PrintMap (map_cont);
    std::cout << std::endl;

    DelElemVec (vector_cont);
    DelElemMap (map_cont);

    std::cout << "Containers after deleting random amount of elements:" << std::endl;
    PrintVec (vector_cont);
    PrintMap (map_cont);
    std::cout << std::endl;

    Synch (map_cont, vector_cont);

    std::cout << "Containers after synchronization:" << std::endl;
    PrintVec (vector_cont);
    PrintMap (map_cont);

    return 0;
}