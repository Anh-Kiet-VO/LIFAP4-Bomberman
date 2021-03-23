#include "TabBombe.h"
#include "TabBrique.h"
#include "Personnage.h"
#include <iostream>
using namespace std;

int main() {
    TabBombe bombes;
    bombes.testRegression();
    TabBrique briques;
    briques.testRegression();
    Personnage perso;
    perso.testRegression();
    return 0;
}