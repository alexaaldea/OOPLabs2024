#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include "Head.h"
using namespace std;
int main()
{
    Tree<char*> copac(100);
    copac.add_node(nullptr, "1");
    copac.add_node(copac.root, "2");
    copac.add_node(copac.root, "3");
    copac.add_node(copac.root, "5");
    copac.add_node(copac.root, "4");
    copac.sort(copac.root, compara);
    cout << "Numarul de copii al radacinii este:" << copac.count(copac.get_node()) << endl;
    copac.delete_node(copac.find(copac.root, "2", compara), 3);
    copac.delete_node(copac.root, 2);
   copac.insert(copac.root, "10", 2);
   copac.printNodes(copac.find(copac.root, "1", compara));
   printf("\n");
    copac.printNodes(copac.root);

	return 0;
}