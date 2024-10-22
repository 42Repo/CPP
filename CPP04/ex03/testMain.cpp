// test_ex03.cpp
#include <gtest/gtest.h>
#include "AMateria.h"
#include "Ice.h"
#include "Cure.h"
#include "Character.h"
#include "MateriaSource.h"

// Test de la création et utilisation des Materias
TEST(MateriaTest, CreateAndUse) {
    AMateria *ice = new Ice();
    AMateria *cure = new Cure();

    EXPECT_EQ(ice->getType(), "ice");
    EXPECT_EQ(cure->getType(), "cure");

    Character target("Target");

    testing::internal::CaptureStdout();
    ice->use(target);
    std::string outputIce = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    cure->use(target);
    std::string outputCure = testing::internal::GetCapturedStdout();

    EXPECT_EQ(outputIce, "* shoots an ice bolt at Target *\n");
    EXPECT_EQ(outputCure, "* heals Target's wounds *\n");

    delete ice;
    delete cure;
}

// Test de l'équipement et de l'utilisation des Materias par un Character
TEST(CharacterTest, EquipUseMateria) {
    Character character("Player");

    AMateria *ice = new Ice();
    AMateria *cure = new Cure();

    character.equip(ice);
    character.equip(cure);

    Character target("Enemy");

    testing::internal::CaptureStdout();
    character.use(0, target);
    std::string outputUse0 = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    character.use(1, target);
    std::string outputUse1 = testing::internal::GetCapturedStdout();

    EXPECT_EQ(outputUse0, "* shoots an ice bolt at Enemy *\n");
    EXPECT_EQ(outputUse1, "* heals Enemy's wounds *\n");

    // Test de l'équipement au-delà de la capacité
    AMateria *extraMateria = new Ice();
    character.equip(extraMateria);
    character.equip(new Cure()); // 4e slot
    character.equip(new Ice());  // Doit être ignoré (inventaire plein)

    // Test de l'utilisation d'un index invalide
    testing::internal::CaptureStdout();
    character.use(4, target); // Index invalide
    std::string outputInvalidUse = testing::internal::GetCapturedStdout();
    EXPECT_EQ(outputInvalidUse, "");

    // Nettoyage
    delete extraMateria; // Materia non équipée doit être supprimée manuellement
    // Les Materias équipées seront supprimées par le destructeur de Character
}

// Test de l'unequip et gestion des Materias déséquipées
TEST(CharacterTest, UnequipMateria) {
    Character character("Player");
    AMateria *ice = new Ice();
    AMateria *cure = new Cure();

    character.equip(ice);
    character.equip(cure);

    character.unequip(0); // Déséquipe ice

    Character target("Enemy");

    testing::internal::CaptureStdout();
    character.use(0, target); // Ne doit rien faire
    std::string outputUse0 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(outputUse0, "");

    testing::internal::CaptureStdout();
    character.use(1, target); // Doit fonctionner
    std::string outputUse1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(outputUse1, "* heals Enemy's wounds *\n");

    // Gestion de la Materia déséquipée
    delete ice; // Doit être supprimée manuellement pour éviter les fuites

    // Le destructeur de Character supprimera cure
}

// Test de MateriaSource
TEST(MateriaSourceTest, LearnAndCreateMateria) {
    MateriaSource source;
    source.learnMateria(new Ice());
    source.learnMateria(new Cure());

    AMateria *ice = source.createMateria("ice");
    AMateria *cure = source.createMateria("cure");
    AMateria *unknown = source.createMateria("fire");

    EXPECT_NE(ice, nullptr);
    EXPECT_EQ(ice->getType(), "ice");

    EXPECT_NE(cure, nullptr);
    EXPECT_EQ(cure->getType(), "cure");

    EXPECT_EQ(unknown, nullptr);

    delete ice;
    delete cure;
    // Les Materias apprises doivent être supprimées par MateriaSource
}

// Test de la gestion de la mémoire dans MateriaSource
TEST(MateriaSourceTest, MemoryManagement) {
    MateriaSource source;
    AMateria *ice = new Ice();
    AMateria *cure = new Cure();

    source.learnMateria(ice);
    source.learnMateria(cure);

    // Les Materias passées à learnMateria sont clonées, il faut les supprimer
    delete ice;
    delete cure;

    // Test de la création de Materia
    AMateria *createdIce = source.createMateria("ice");
    EXPECT_NE(createdIce, nullptr);

    delete createdIce;
    // Les Materias apprises seront supprimées par le destructeur de MateriaSource
}

// Test de la copie et de l'affectation de Character
TEST(CharacterTest, CopyAndAssignment) {
    Character original("Original");
    AMateria *ice = new Ice();
    AMateria *cure = new Cure();

    original.equip(ice);
    original.equip(cure);

    Character copy(original); // Constructeur de copie

    EXPECT_EQ(copy.getName(), "Original");

    Character assigned("Assigned");
    assigned = original; // Opérateur d'affectation

    EXPECT_EQ(assigned.getName(), "Original");

    Character target("Enemy");

    testing::internal::CaptureStdout();
    copy.use(0, target);
    std::string outputCopyUse0 = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    assigned.use(1, target);
    std::string outputAssignedUse1 = testing::internal::GetCapturedStdout();

    EXPECT_EQ(outputCopyUse0, "* shoots an ice bolt at Enemy *\n");
    EXPECT_EQ(outputAssignedUse1, "* heals Enemy's wounds *\n");

    // Nettoyage
    // Les Materias de original, copy, et assigned seront supprimées par leurs destructeurs
}

