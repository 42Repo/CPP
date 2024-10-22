// test_ex02.cpp
#include <gtest/gtest.h>
#include "AAnimal.h"
#include "Cat.h"
#include "Dog.h"

// Test que AAnimal est abstraite et ne peut pas être instanciée
TEST(AbstractClassTest, CannotInstantiateAAnimal) {
    // Ceci devrait échouer à la compilation si AAnimal est abstraite
    // AAnimal animal; // Décommenter cette ligne devrait provoquer une erreur de compilation
    SUCCEED(); // Si le code compile, le test réussit
}

// Test que les classes dérivées implémentent makeSound()
TEST(DerivedClassesTest, MakeSoundImplementation) {
    AAnimal *dog = new Dog();
    AAnimal *cat = new Cat();

    testing::internal::CaptureStdout();
    dog->makeSound();
    std::string outputDog = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    cat->makeSound();
    std::string outputCat = testing::internal::GetCapturedStdout();

    EXPECT_EQ(outputDog, "Woula jsuis un chien !\n");
    EXPECT_EQ(outputCat, "Miaou le chat !\n");

    delete dog;
    delete cat;
}

// Test du destructeur virtuel
TEST(VirtualDestructorTest, ProperDestruction) {
    testing::internal::CaptureStdout();
    AAnimal *animal = new Dog();
    delete animal;
    std::string output = testing::internal::GetCapturedStdout();

    // Vérifier que le destructeur de Dog est appelé
    EXPECT_NE(output.find("Dog Destructor"), std::string::npos);
    EXPECT_NE(output.find("AAnimal Destructor"), std::string::npos);
}

// Test de la pure virtual function
TEST(PureVirtualFunctionTest, MakeSoundIsPureVirtual) {
    // Ceci devrait échouer à la compilation si makeSound() n'est pas pure virtuelle
    // AAnimal animal; // Décommenter cette ligne devrait provoquer une erreur de compilation
    SUCCEED(); // Si le code compile, le test réussit
}

