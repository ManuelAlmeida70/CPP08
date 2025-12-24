#include "Span.hpp"
#include <list>
#include <ctime>
#include <cstdlib>

int main()
{
    std::cout << "--- Teste do sujeito ---" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Teste de Excecoes ---" << std::endl;
    try
    {
        Span small(1);
        small.addNumber(10);

        std::cout << small.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Erro esperado: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "--- Teste de 10.0000 numero ---" << std::endl;
    std::vector<int> bigVector;
    std::srand(std::time(0));
    for (int i = 0; i < 1000; i++)
    {
        bigVector.push_back(std::rand());
    }

    Span bigSpan(1000);
    try
    {
        bigSpan.addNumbers(bigVector.begin(), bigVector.end());

        std::cout << "Shortest em 10k: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest em 10: " << bigSpan.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Erro esperado: " << e.what() << '\n';
    }
    
}