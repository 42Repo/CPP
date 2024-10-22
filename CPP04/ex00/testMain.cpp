// test_ex00.cpp
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include <gtest/gtest.h>

// Test que les animaux font le bon son
TEST(AnimalTest, MakeSound) {
    Animal *meta = new Animal();
    Animal *dog = new Dog();
    Animal *cat = new Cat();

    testing::internal::CaptureStdout();
    meta->makeSound();
    std::string outputMeta = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    dog->makeSound();
    std::string outputDog = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    cat->makeSound();
    std::string outputCat = testing::internal::GetCapturedStdout();

    EXPECT_EQ(outputMeta, "Animal Sound !\n");
    EXPECT_EQ(outputDog, "Woula jsuis un chien !\n");
    EXPECT_EQ(outputCat, "Miaou le chat !\n");

    delete meta;
    delete dog;
    delete cat;
}

// Test du polymorphisme avec les pointeurs
TEST(AnimalTest, Polymorphism) {
    const Animal *animalDog = new Dog();
    const Animal *animalCat = new Cat();

    EXPECT_EQ(animalDog->getType(), "Dog");
    EXPECT_EQ(animalCat->getType(), "Cat");

    testing::internal::CaptureStdout();
    animalDog->makeSound();
    std::string outputDog = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    animalCat->makeSound();
    std::string outputCat = testing::internal::GetCapturedStdout();

    EXPECT_EQ(outputDog, "Woula jsuis un chien !\n");
    EXPECT_EQ(outputCat, "Miaou le chat !\n");

    delete animalDog;
    delete animalCat;
}

// Test sans le mot-clé virtual (WrongAnimal)
TEST(WrongAnimalTest, NoVirtualFunction) {
    const WrongAnimal *wrongAnimal = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();

    EXPECT_EQ(wrongAnimal->getType(), "Unknown");
    EXPECT_EQ(wrongCat->getType(), "WrongCat");

    testing::internal::CaptureStdout();
    wrongAnimal->makeSound();
    std::string outputWrongAnimal = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    wrongCat->makeSound();
    std::string outputWrongCat = testing::internal::GetCapturedStdout();

    EXPECT_EQ(outputWrongAnimal, "WrongAnimal Sound !\n");
    EXPECT_EQ(outputWrongCat, "WrongAnimal Sound !\n");

    const WrongCat *actualWrongCat = new WrongCat();

    testing::internal::CaptureStdout();
    actualWrongCat->makeSound();
    std::string outputActualWrongCat = testing::internal::GetCapturedStdout();

    EXPECT_EQ(outputActualWrongCat, "Miaou le chat !\n");

    delete wrongAnimal;
    delete wrongCat;
    delete actualWrongCat;
}

// Test des constructeurs et destructeurs
TEST(AnimalTest, ConstructorsDestructors) {
    testing::internal::CaptureStdout();
    Animal     *animal = new Animal();
    std::string constructorOutput = testing::internal::GetCapturedStdout();
    EXPECT_EQ(constructorOutput, "Animal Default constructor\n");

    testing::internal::CaptureStdout();
    delete animal;
    std::string destructorOutput = testing::internal::GetCapturedStdout();
    EXPECT_EQ(destructorOutput, "Animal Destructor\n");
}

// Test de l'opérateur d'affectation et du constructeur par copie
TEST(AnimalTest, CopyAssignment) {
    Dog dog1;
    Dog dog2;

    dog2 = dog1;
    EXPECT_EQ(dog1.getType(), dog2.getType());

    Cat cat1;
    Cat cat2(cat1);
    EXPECT_EQ(cat1.getType(), cat2.getType());
}
