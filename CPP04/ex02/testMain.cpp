// test_ex02.cpp
#include "AAnimal.h"
#include "Cat.h"
#include "Dog.h"
#include <gtest/gtest.h>

// Fonction d'aide pour capturer la sortie standard
std::string capture_stdout(std::function<void()> func) {
    testing::internal::CaptureStdout();
    func();
    return testing::internal::GetCapturedStdout();
}

// Test que AAnimal est une classe abstraite
// Cette ligne ne devrait pas compiler si AAnimal est abstraite
// TEST(Ex02_AbstractClassTest, CannotInstantiateAAnimal) {
//     AAnimal animal; // Doit provoquer une erreur de compilation
// }

// Test que les classes dérivées implémentent makeSound()
TEST(Ex02_DerivedClassesTest, MakeSoundImplementation) {
    AAnimal *dog = new Dog();
    AAnimal *cat = new Cat();

    std::string outputDog = capture_stdout([&]() { dog->makeSound(); });
    std::string outputCat = capture_stdout([&]() { cat->makeSound(); });

    EXPECT_EQ(outputDog, "Woula jsuis un chien !\n");
    EXPECT_EQ(outputCat, "Miaou le chat !\n");

    delete dog;
    delete cat;
}

// Test des constructeurs et destructeurs avec AAnimal
TEST(Ex02_AAnimalTest, ConstructorsDestructors) {
    testing::internal::CaptureStdout();
    { Cat cat("Simba"); }
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(
        output,
        "AAnimal Parameter constructor\nBrain Default constructor\nCat Parameter constructor\n"
        "Cat Destructor\nBrain Destructor\nAAnimal Destructor\n");
}

TEST(Ex02_AAnimalTest, Polymorphism) {
    AAnimal *animals[2];
    animals[0] = new Dog("Buddy");
    animals[1] = new Cat("Whiskers");

    EXPECT_EQ(animals[0]->getType(), "Buddy");
    EXPECT_EQ(animals[1]->getType(), "Whiskers");

    std::string outputDog = capture_stdout([&]() { animals[0]->makeSound(); });
    std::string outputCat = capture_stdout([&]() { animals[1]->makeSound(); });

    EXPECT_EQ(outputDog, "Woula jsuis un chien !\n");
    EXPECT_EQ(outputCat, "Miaou le chat !\n");

    for (int i = 0; i < 2; i++) {
        delete animals[i];
    }
}

// Test du destructeur virtuel
TEST(Ex02_VirtualDestructorTest, ProperDestruction) {
    testing::internal::CaptureStdout();
    AAnimal *animal = new Dog();
    delete animal;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "AAnimal Parameter constructor\nBrain Default constructor\nDog Default "
                      "constructor\nDog Destructor\nBrain Destructor\nAAnimal Destructor\n");
}

// Test de la pure virtual function
// Ce test n'est pas exécutable car il doit échouer à la compilation
// Il est commenté pour ne pas empêcher la compilation des autres tests
// TEST(Ex02_PureVirtualFunctionTest, MakeSoundIsPureVirtual) {
//     AAnimal animal; // Doit provoquer une erreur de compilation
// }
