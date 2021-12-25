#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

int main()
{
    try {
        Person *Adam(new Person("Adam", Gender::male));
        Person *Eva(new Person("Eva", Gender::female));
        Person *Igor(Eva->GiveBirth("Igor", Adam, Gender::male));
        Person *Maria(Eva->GiveBirth("Maria", Adam, Gender::female));
        Person *Kirill(Maria->GiveBirth("Kirill", Igor, Gender::male));
        std::cout << *Kirill;
    }
    catch (std::runtime_error &err) {
        cerr << endl << err.what() << endl;
    }
}