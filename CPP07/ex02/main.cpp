#include "Array.h"

int main() {
    try {
        std::cout << "Test du constructeur par défaut:" << std::endl;
        Array<int> arrayDefault;
        std::cout << "Taille (constructeur par défaut): " << arrayDefault.size() << std::endl;

        std::cout << "\nTest du constructeur avec taille:" << std::endl;
        Array<int> arraySized(5);
        std::cout << "Taille (constructeur avec taille): " << arraySized.size() << std::endl;

        for (unsigned int i = 0; i < arraySized.size(); i++) {
            arraySized[i] = i * 10;
        }
        std::cout << "Contenu du tableau après initialisation:" << std::endl;
        arraySized.print();

        std::cout << "\nTest du constructeur de copie:" << std::endl;
        Array<int> arrayCopy(arraySized);
        std::cout << "Contenu du tableau copié:" << std::endl;
        arrayCopy.print();

        std::cout << "\nTest de l'opérateur d'affectation:" << std::endl;
        Array<int> arrayAssigned;
        arrayAssigned = arraySized;
        std::cout << "Contenu du tableau après affectation:" << std::endl;
        arrayAssigned.print();

        std::cout << "\nTest de l'accès aux éléments:" << std::endl;
        std::cout << "Élément à l'indice 0 : " << arraySized[0] << std::endl;
        std::cout << "Élément à l'indice 4 : " << arraySized[4] << std::endl;

        std::cout << "\nTest de l'accès hors limites (attendu une exception):" << std::endl;
        try {
            std::cout << arraySized[10] << std::endl; 
        } catch (const std::exception &e) {
            std::cerr << "Exception capturée : " << e.what() << std::endl;
        }

        std::cout << "\nTest avec un Array de chaînes de caractères:" << std::endl;
        Array<std::string> arrayStrings(3);
        arrayStrings[0] = "Hello";
        arrayStrings[1] = "World";
        arrayStrings[2] = "Array";
        std::cout << "Contenu de l'Array de chaînes:" << std::endl;
        arrayStrings.print();

    } catch (const std::exception &e) {
        std::cerr << "Exception capturée dans le main: " << e.what() << std::endl;
    }

    return 0;
}
