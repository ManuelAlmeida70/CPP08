#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
    std::cout << "--- Testando com std::vector ---" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 5; i++) vec.push_back(i * 10);
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Encontrado: " << *it << std::endl;

        easyfind(vec, 99);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Erro: " << e.what() << '\n';
    }

    std::cout << "\n--- Testando com std::list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 3);
        std::cout << "Encontrado lista: " << *it << std::endl;

        easyfind(lst, 42);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Erro: " << e.what() << '\n';
    }
    
    
    return 0;
}