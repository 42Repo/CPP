// test_ex01.cpp
#include <gtest/gtest.h>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

// Test de la copie profonde du Brain
TEST(BrainTest, DeepCopy) {
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Chase the cat");
    dog1.getBrain()->setIdea(1, "Fetch the ball");

    Dog dog2 = dog1; // Opérateur d'affectation

    EXPECT_NE(dog1.getBrain(), dog2.getBrain()); // Les cerveaux doivent être différents
    EXPECT_EQ(dog1.getBrain()->getIdea(0), dog2.getBrain()->getIdea(0));
    EXPECT_EQ(dog1.getBrain()->getIdea(1), dog2.getBrain()->getIdea(1));

    dog2.getBrain()->setIdea(0, "Dig a hole");
    EXPECT_NE(dog1.getBrain()->getIdea(0), dog2.getBrain()->getIdea(0));
}

// Test de la destruction sans fuite mémoire
// TEST(MemoryTest, NoMemoryLeaks) {
//     int initialBreaks = 0;
//     int finalBreaks = 0;

//     {
//         testing::internal::CaptureStderr();
//         Dog *dog = new Dog();
//         delete dog;
//         std::string output = testing::internal::GetCapturedStderr();
//         // Analyse de la sortie pour détecter des erreurs (par exemple, via valgrind si possible)
//     }

//     // Ici, vous pouvez intégrer des outils de détection de fuites de mémoire si possible
// }

// Test de la création d'un tableau d'animaux
TEST(AnimalArrayTest, CreationAndDeletion) {
    const int size = 10;
    Animal *animals[size];

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < size; i++) {
        delete animals[i];
    }

    // Ici, vous pouvez vérifier s'il y a des fuites de mémoire après suppression
}

// Test de la copie du Cat
TEST(CatTest, CopyConstructor) {
    Cat cat1;
    cat1.getBrain()->setIdea(0, "Sleep");
    cat1.getBrain()->setIdea(1, "Eat fish");

    Cat cat2(cat1); // Constructeur de copie

    EXPECT_NE(cat1.getBrain(), cat2.getBrain());
    EXPECT_EQ(cat1.getBrain()->getIdea(0), cat2.getBrain()->getIdea(0));
    EXPECT_EQ(cat1.getBrain()->getIdea(1), cat2.getBrain()->getIdea(1));

    cat2.getBrain()->setIdea(0, "Climb tree");
    EXPECT_NE(cat1.getBrain()->getIdea(0), cat2.getBrain()->getIdea(0));
}

