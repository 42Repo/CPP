// test_ex01.cpp
#include "Animal.h"
#include "Brain.h"
#include "Cat.h"
#include "Dog.h"
#include <gtest/gtest.h>

// Fonction d'aide pour capturer la sortie standard
std::string capture_stdout(std::function<void()> func) {
    testing::internal::CaptureStdout();
    func();
    return testing::internal::GetCapturedStdout();
}

// Test de la classe Brain
TEST(Ex01_BrainTest, DefaultConstructor) {
    testing::internal::CaptureStdout();
    Brain       brain;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Brain Default constructor\n");
}

TEST(Ex01_BrainTest, CopyConstructor) {
    Brain brain1;
    brain1.setIdea(0, "Idea 1");
    brain1.setIdea(1, "Idea 2");

    testing::internal::CaptureStdout();
    Brain       brain2(brain1);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Brain Copy constructor\n");

    EXPECT_EQ(brain2.getIdea(0), "Idea 1");
    EXPECT_EQ(brain2.getIdea(1), "Idea 2");

    brain2.setIdea(0, "Idea 3");
    EXPECT_EQ(brain1.getIdea(0), "Idea 1");
    EXPECT_EQ(brain2.getIdea(0), "Idea 3");
}

TEST(Ex01_BrainTest, AssignmentOperator) {
    Brain brain1;
    brain1.setIdea(0, "Idea A");
    brain1.setIdea(1, "Idea B");

    Brain brain2;
    testing::internal::CaptureStdout();
    brain2 = brain1;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Brain Copy assignment operator constructor\n");

    EXPECT_EQ(brain2.getIdea(0), "Idea A");
    EXPECT_EQ(brain2.getIdea(1), "Idea B");

    brain2.setIdea(1, "Idea C");
    EXPECT_EQ(brain1.getIdea(1), "Idea B");
    EXPECT_EQ(brain2.getIdea(1), "Idea C");
}

TEST(Ex01_BrainTest, SetGetIdea) {
    Brain brain;
    brain.setIdea(0, "First Idea");
    brain.setIdea(99, "Last Idea");

    EXPECT_EQ(brain.getIdea(0), "First Idea");
    EXPECT_EQ(brain.getIdea(99), "Last Idea");
    EXPECT_EQ(brain.getIdea(100), "Unknown"); // Out of bounds
    EXPECT_EQ(brain.getIdea(-1), "Unknown");  // Out of bounds
}

// Test des classes Cat et Dog avec Brain
TEST(Ex01_CatTest, BrainAssociation) {
    testing::internal::CaptureStdout();
    Cat         cat;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output,
              "Animal Parameter constructor\nBrain Default constructor\nCat Default constructor\n");
    EXPECT_NE(cat.getBrain(), nullptr);
}

TEST(Ex01_DogTest, BrainAssociation) {
    testing::internal::CaptureStdout();
    Dog         dog;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output,
              "Animal Parameter constructor\nBrain Default constructor\nDog Default constructor\n");
    EXPECT_NE(dog.getBrain(), nullptr);
}

// Test de la copie profonde pour Cat
TEST(Ex01_CatTest, DeepCopyConstructor) {
    Cat cat1;
    cat1.getBrain()->setIdea(0, "Climbing trees");
    cat1.getBrain()->setIdea(1, "Chasing mice");

    testing::internal::CaptureStdout();
    Cat         cat2(cat1);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Copy constructor\nBrain Copy constructor\nCat Copy constructor\n");

    EXPECT_NE(cat1.getBrain(), cat2.getBrain());
    EXPECT_EQ(cat2.getBrain()->getIdea(0), "Climbing trees");
    EXPECT_EQ(cat2.getBrain()->getIdea(1), "Chasing mice");

    cat2.getBrain()->setIdea(0, "Sleeping");
    EXPECT_EQ(cat1.getBrain()->getIdea(0), "Climbing trees");
    EXPECT_EQ(cat2.getBrain()->getIdea(0), "Sleeping");
}

// Test de l'opérateur d'affectation pour Cat
TEST(Ex01_CatTest, DeepAssignmentOperator) {
    Cat cat1;
    cat1.getBrain()->setIdea(0, "Hunting");

    Cat cat2;
    testing::internal::CaptureStdout();
    cat2 = cat1;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Copy assignment operator constructor\nBrain Destructor\nBrain Copy "
                      "constructor\nCat Copy assignment operator called\n");

    EXPECT_NE(cat1.getBrain(), cat2.getBrain());
    EXPECT_EQ(cat2.getBrain()->getIdea(0), "Hunting");

    cat2.getBrain()->setIdea(0, "Fishing");
    EXPECT_EQ(cat1.getBrain()->getIdea(0), "Hunting");
    EXPECT_EQ(cat2.getBrain()->getIdea(0), "Fishing");
}

// Test de la copie profonde pour Dog
TEST(Ex01_DogTest, DeepCopyConstructor) {
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Digging");
    dog1.getBrain()->setIdea(1, "Fetching");

    testing::internal::CaptureStdout();
    Dog         dog2(dog1);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Copy constructor\nBrain Copy constructor\nDog Copy constructor\n");

    EXPECT_NE(dog1.getBrain(), dog2.getBrain());
    EXPECT_EQ(dog2.getBrain()->getIdea(0), "Digging");
    EXPECT_EQ(dog2.getBrain()->getIdea(1), "Fetching");

    dog2.getBrain()->setIdea(1, "Running");
    EXPECT_EQ(dog1.getBrain()->getIdea(1), "Fetching");
    EXPECT_EQ(dog2.getBrain()->getIdea(1), "Running");
}

// Test de l'opérateur d'affectation pour Dog
TEST(Ex01_DogTest, DeepAssignmentOperator) {
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Barking");

    Dog dog2;
    testing::internal::CaptureStdout();
    dog2 = dog1;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Copy assignment operator constructor\nBrain Destructor\nBrain Copy "
                      "constructor\nDog Copy assignment operator called\n");

    EXPECT_NE(dog1.getBrain(), dog2.getBrain());
    EXPECT_EQ(dog2.getBrain()->getIdea(0), "Barking");

    dog2.getBrain()->setIdea(0, "Howling");
    EXPECT_EQ(dog1.getBrain()->getIdea(0), "Barking");
    EXPECT_EQ(dog2.getBrain()->getIdea(0), "Howling");
}

// Test des destructeurs
TEST(Ex01_MemoryTest, DestructorsCalled) {
    testing::internal::CaptureStdout();
    {
        Cat cat;
        Dog dog;
    }
    std::string output = testing::internal::GetCapturedStdout();
    // Détruction dans l'ordre inverse de la création
    EXPECT_EQ(output,
              "Animal Parameter constructor\nBrain Default constructor\nCat Default constructor\n"
              "Animal Parameter constructor\nBrain Default constructor\nDog Default constructor\n"
              "Dog Destructor\nBrain Destructor\nAnimal Destructor\n"
              "Cat Destructor\nBrain Destructor\nAnimal Destructor\n");
}

// Test de la copie multiple pour assurer aucune fuite
TEST(Ex01_MemoryTest, MultipleCopies) {
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Chasing cars");

    Dog dog2 = dog1;
    Dog dog3;
    dog3 = dog2;

    EXPECT_EQ(dog1.getBrain()->getIdea(0), "Chasing cars");
    EXPECT_EQ(dog2.getBrain()->getIdea(0), "Chasing cars");
    EXPECT_EQ(dog3.getBrain()->getIdea(0), "Chasing cars");

    dog3.getBrain()->setIdea(0, "Running fast");

    EXPECT_EQ(dog1.getBrain()->getIdea(0), "Chasing cars");
    EXPECT_EQ(dog2.getBrain()->getIdea(0), "Chasing cars");
    EXPECT_EQ(dog3.getBrain()->getIdea(0), "Running fast");
}

// Test de la méthode makeSound()
TEST(Ex01_AnimalTest, MakeSound) {
    Animal      animal;
    std::string output = capture_stdout([&]() { animal.makeSound(); });
    EXPECT_EQ(output, "Animal Sound !\n");
}

TEST(Ex01_CatTest, MakeSound) {
    Cat         cat;
    std::string output = capture_stdout([&]() { cat.makeSound(); });
    EXPECT_EQ(output, "Miaou le chat !\n");
}

TEST(Ex01_DogTest, MakeSound) {
    Dog         dog;
    std::string output = capture_stdout([&]() { dog.makeSound(); });
    EXPECT_EQ(output, "Woula jsuis un chien !\n");
}

// Test de la gestion des Brain dans Cat
TEST(Ex01_CatTest, BrainManagement) {
    Cat cat1;
    cat1.getBrain()->setIdea(0, "Sleep");
    cat1.getBrain()->setIdea(1, "Eat fish");

    Cat cat2(cat1);

    EXPECT_NE(cat1.getBrain(), cat2.getBrain());
    EXPECT_EQ(cat2.getBrain()->getIdea(0), "Sleep");
    EXPECT_EQ(cat2.getBrain()->getIdea(1), "Eat fish");

    cat2.getBrain()->setIdea(0, "Climb tree");
    EXPECT_EQ(cat1.getBrain()->getIdea(0), "Sleep");
    EXPECT_EQ(cat2.getBrain()->getIdea(0), "Climb tree");
}

// Test de la gestion des Brain dans Dog
TEST(Ex01_DogTest, BrainManagement) {
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Chase tail");
    dog1.getBrain()->setIdea(1, "Fetch stick");

    Dog dog2 = dog1;

    EXPECT_NE(dog1.getBrain(), dog2.getBrain());
    EXPECT_EQ(dog2.getBrain()->getIdea(0), "Chase tail");
    EXPECT_EQ(dog2.getBrain()->getIdea(1), "Fetch stick");

    dog2.getBrain()->setIdea(1, "Run in park");
    EXPECT_EQ(dog1.getBrain()->getIdea(1), "Fetch stick");
    EXPECT_EQ(dog2.getBrain()->getIdea(1), "Run in park");
}

// Test de l'opérateur d'affectation avec self-assignment
TEST(Ex01_AnimalTest, SelfAssignment) {
    Animal animal("Self");
    testing::internal::CaptureStdout();
    animal = animal;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal Copy assignment operator constructor\n");
    EXPECT_EQ(animal.getType(), "Self");
}

TEST(Ex01_CatTest, SelfAssignment) {
    Cat cat;
    testing::internal::CaptureStdout();
    cat = cat;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Cat Copy assignment operator called\n");
}

TEST(Ex01_DogTest, SelfAssignment) {
    Dog dog;
    testing::internal::CaptureStdout();
    dog = dog;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output,
              "Dog Copy assignment operator called\n");
}
