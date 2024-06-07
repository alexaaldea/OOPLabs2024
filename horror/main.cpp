#include <iostream>
#include "Revista.h"
#include "Roman.h"
#include "Carte.h"
#include "Biblioteca.h"
#include<string>
using namespace std;

int main()
{
    Biblioteca b;
    (b += new Roman("DON QUIJOTE", "MIGUEL DE CERVANTES")) += new Revista("Journal of Artificial Intelligence", 100);
    b += new Roman("MACBETH", "WILLIAM SHAKESPEARE");

    for (auto x : b) { std::cout << x.GetInfo() << std::endl; }

    std::cout << "Numar de intrari in biblioteca: " << (int)b << std::endl;
    std::cout << "Lista doar cu romane:" << std::endl;
    b.PrintFilter([](Carte* c) -> bool {
        return dynamic_cast<Roman*>(c) != nullptr;
        });
	return 0;
}