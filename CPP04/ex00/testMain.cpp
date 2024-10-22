// test_ex00.cpp
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include <gtest/gtest.h>

// Fonction d'aide pour capturer la sortie standard
std::string capture_stdout(std::function<void()> func) {
    testing::internal::CaptureStdout();
    func();
    return testing::internal::GetCapturedStdout();
}

// Test des constructeurs par défaut
TEST(Ex00_AnimalTest, DefaultConstructor) {
    testing::internal::CaptureStdout();
    Animal      animal;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Default constructor\n");
    EXPECT_EQ(animal.getType(), "Unknown");
}

TEST(Ex00_CatTest, DefaultConstructor) {
    testing::internal::CaptureStdout();
    Cat         cat;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Parameter constructor\nCat Default constructor\n");
    EXPECT_EQ(cat.getType(), "Cat");
}

TEST(Ex00_DogTest, DefaultConstructor) {
    testing::internal::CaptureStdout();
    Dog         dog;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Parameter constructor\nDog Default constructor\n");
    EXPECT_EQ(dog.getType(), "Dog");
}

// Test des constructeurs avec paramètres
TEST(Ex00_AnimalTest, ParameterConstructor) {
    testing::internal::CaptureStdout();
    Animal      animal("Generic");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Parameter constructor\n");
    EXPECT_EQ(animal.getType(), "Generic");
}

TEST(Ex00_CatTest, ParameterConstructor) {
    testing::internal::CaptureStdout();
    Cat         cat("Kitty");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Parameter constructor\nCat Parameter constructor\n");
    EXPECT_EQ(cat.getType(), "Kitty");
}

TEST(Ex00_DogTest, ParameterConstructor) {
    testing::internal::CaptureStdout();
    Dog         dog("Puppy");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Parameter constructor\nDog Parameter constructor\n");
    EXPECT_EQ(dog.getType(), "Puppy");
}

// Test des constructeurs de copie
TEST(Ex00_AnimalTest, CopyConstructor) {
    Animal original("Original");
    testing::internal::CaptureStdout();
    Animal      copy(original);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Copy constructor\n");
    EXPECT_EQ(copy.getType(), "Original");
}

TEST(Ex00_CatTest, CopyConstructor) {
    Cat original;
    testing::internal::CaptureStdout();
    Cat         copy(original);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Copy constructor\nCat Copy constructor\n");
    EXPECT_EQ(copy.getType(), "Cat");
}

TEST(Ex00_DogTest, CopyConstructor) {
    Dog original;
    testing::internal::CaptureStdout();
    Dog         copy(original);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Copy constructor\nDog Copy constructor\n");
    EXPECT_EQ(copy.getType(), "Dog");
}

// Test des opérateurs d'affectation
TEST(Ex00_AnimalTest, AssignmentOperator) {
    Animal a1("Type1");
    Animal a2;
    testing::internal::CaptureStdout();
    a2 = a1;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Copy assignment operator constructor\n");
    EXPECT_EQ(a2.getType(), "Type1");
}

TEST(Ex00_CatTest, AssignmentOperator) {
    Cat cat1;
    Cat cat2;
    testing::internal::CaptureStdout();
    cat2 = cat1;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output,
              "Animal Copy assignment operator constructor\nCat Copy assignment operator called\n");
    EXPECT_EQ(cat2.getType(), "Cat");
}

TEST(Ex00_DogTest, AssignmentOperator) {
    Dog dog1;
    Dog dog2;
    testing::internal::CaptureStdout();
    dog2 = dog1;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output,
              "Animal Copy assignment operator constructor\nDog Copy assignment operator called\n");
    EXPECT_EQ(dog2.getType(), "Dog");
}

// Test des destructeurs
TEST(Ex00_AnimalTest, Destructor) {
    testing::internal::CaptureStdout();
    {
        Animal *animal = new Animal();
        delete animal;
    }
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Default constructor\nAnimal Destructor\n");
}

TEST(Ex00_CatTest, Destructor) {
    testing::internal::CaptureStdout();
    {
        Cat *cat = new Cat();
        delete cat;
    }
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Parameter constructor\nCat Default constructor\nCat "
                      "Destructor\nAnimal Destructor\n");
}

TEST(Ex00_DogTest, Destructor) {
    testing::internal::CaptureStdout();
    {
        Dog *dog = new Dog();
        delete dog;
    }
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Parameter constructor\nDog Default constructor\nDog "
                      "Destructor\nAnimal Destructor\n");
}

// Test de makeSound()
TEST(Ex00_AnimalTest, MakeSound) {
    Animal      animal;
    std::string output = capture_stdout([&]() { animal.makeSound(); });
    EXPECT_EQ(output, "Animal Sound !\n");
}

TEST(Ex00_CatTest, MakeSound) {
    Cat         cat;
    std::string output = capture_stdout([&]() { cat.makeSound(); });
    EXPECT_EQ(output, "Miaou le chat !\n");
}

TEST(Ex00_DogTest, MakeSound) {
    Dog         dog;
    std::string output = capture_stdout([&]() { dog.makeSound(); });
    EXPECT_EQ(output, "Woula jsuis un chien !\n");
}

// Test du polymorphisme
TEST(Ex00_PolymorphismTest, VirtualMakeSound) {
    const Animal *animal = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    std::string outputAnimal = capture_stdout([&]() { animal->makeSound(); });
    std::string outputDog = capture_stdout([&]() { dog->makeSound(); });
    std::string outputCat = capture_stdout([&]() { cat->makeSound(); });

    EXPECT_EQ(outputAnimal, "Animal Sound !\n");
    EXPECT_EQ(outputDog, "Woula jsuis un chien !\n");
    EXPECT_EQ(outputCat, "Miaou le chat !\n");

    delete animal;
    delete dog;
    delete cat;
}

// Test des WrongAnimal sans virtual
TEST(Ex00_WrongAnimalTest, MakeSoundNoVirtual) {
    const WrongAnimal *wrongAnimal = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();

    std::string outputWrongAnimal = capture_stdout([&]() { wrongAnimal->makeSound(); });
    std::string outputWrongCat = capture_stdout([&]() { wrongCat->makeSound(); });

    EXPECT_EQ(outputWrongAnimal, "WrongAnimal Sound !\n");
    // Sans virtual, wrongCat->makeSound() appelle WrongAnimal::makeSound()
    EXPECT_EQ(outputWrongCat, "WrongAnimal Sound !\n");

    delete wrongAnimal;
    delete wrongCat;
}

TEST(Ex00_WrongCatTest, MakeSoundWrongCat) {
    WrongCat    wrongCat;
    std::string output = capture_stdout([&]() { wrongCat.makeSound(); });
    EXPECT_EQ(output, "Miaou le chat !\n");
}

// Test de l'opérateur d'affectation avec auto-affectation
TEST(Ex00_AnimalTest, SelfAssignment) {
    Animal animal("Self");
    testing::internal::CaptureStdout();
    animal = animal;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Copy assignment operator constructor\n");
    EXPECT_EQ(animal.getType(), "Self");
}

TEST(Ex00_CatTest, SelfAssignment) {
    Cat cat;
    testing::internal::CaptureStdout();
    cat = cat;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output,
              "Cat Copy assignment operator called\n");
}

TEST(Ex00_DogTest, SelfAssignment) {
    Dog dog;
    testing::internal::CaptureStdout();
    dog = dog;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output,
              "Dog Copy assignment operator called\n");
}
