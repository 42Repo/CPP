// test_ex03.cpp
#include "AMateria.h"
#include "Character.h"
#include "Cure.h"
#include "Ice.h"
#include "MateriaSource.h"
#include <gtest/gtest.h>

// Fonction d'aide pour capturer la sortie standard
std::string capture_stdout(std::function<void()> func) {
    testing::internal::CaptureStdout();
    func();
    return testing::internal::GetCapturedStdout();
}

// Test de la classe AMateria et de ses dérivées
TEST(Ex03_AMateriaTest, CloneFunction) {
    AMateria *ice = new Ice();
    AMateria *cure = new Cure();

    AMateria *iceClone = ice->clone();
    AMateria *cureClone = cure->clone();

    EXPECT_NE(iceClone, ice);
    EXPECT_EQ(iceClone->getType(), "ice");

    EXPECT_NE(cureClone, cure);
    EXPECT_EQ(cureClone->getType(), "cure");

    delete ice;
    delete cure;
    delete iceClone;
    delete cureClone;
}

TEST(Ex03_AMateriaTest, UseFunction) {
    Character target("Target");

    AMateria *ice = new Ice();
    AMateria *cure = new Cure();

    std::string outputIce = capture_stdout([&]() { ice->use(target); });
    std::string outputCure = capture_stdout([&]() { cure->use(target); });

    EXPECT_EQ(outputIce, "* shoots an ice bolt at Target *\n");
    EXPECT_EQ(outputCure, "* heals Target's wounds *\n");

    delete ice;
    delete cure;
}

// Test de la classe Character
TEST(Ex03_CharacterTest, EquipAndUseMateria) {
    MateriaSource source;
    source.learnMateria(new Ice());
    source.learnMateria(new Cure());

    Character character("Player");
    Character target("Enemy");

    AMateria *ice = source.createMateria("ice");
    AMateria *cure = source.createMateria("cure");

    character.equip(ice);
    character.equip(cure);

    // Utiliser les materias
    std::string outputIce = capture_stdout([&]() { character.use(0, target); });
    std::string outputCure = capture_stdout([&]() { character.use(1, target); });

    EXPECT_EQ(outputIce, "* shoots an ice bolt at Enemy *\n");
    EXPECT_EQ(outputCure, "* heals Enemy's wounds *\n");

    // Equipement au-delà de la capacité
    AMateria *extra1 = source.createMateria("ice");
    AMateria *extra2 = source.createMateria("cure");
    AMateria *extra3 = source.createMateria("ice"); // Doit être ignoré

    character.equip(extra1);
    character.equip(extra2);
    character.equip(extra3); // Ne doit pas être équipé

    // Utiliser les 4 premières materias
    std::string outputExtra1 = capture_stdout([&]() { character.use(2, target); });
    std::string outputExtra2 = capture_stdout([&]() { character.use(3, target); });

    EXPECT_EQ(outputExtra1, "* shoots an ice bolt at Enemy *\n");
    EXPECT_EQ(outputExtra2, "* heals Enemy's wounds *\n");

    // Utiliser une materia non équipée (doit ne rien faire)
    std::string outputInvalidUse = capture_stdout([&]() { character.use(4, target); });
    EXPECT_EQ(outputInvalidUse, "");

    // Nettoyage : extra3 doit être supprimé manuellement
    delete extra3;

    // Les autres materias seront supprimées par le destructeur de Character
}

TEST(Ex03_CharacterTest, UnequipMateria) {
    MateriaSource source;
    source.learnMateria(new Ice());
    source.learnMateria(new Cure());

    Character character("Player");
    Character target("Enemy");

    AMateria *ice = source.createMateria("ice");
    AMateria *cure = source.createMateria("cure");

    character.equip(ice);
    character.equip(cure);

    // Déséquipe la première materia (ice)
    character.unequip(0);

    // Utiliser la première slot déséquipée (doit ne rien faire)
    std::string outputUnequip = capture_stdout([&]() { character.use(0, target); });
    EXPECT_EQ(outputUnequip, "");

    // Utiliser la deuxième slot (cure)
    std::string outputUse1 = capture_stdout([&]() { character.use(1, target); });
    EXPECT_EQ(outputUse1, "* heals Enemy's wounds *\n");

    // Nettoyage : la materia déséquipée (ice) doit être supprimée manuellement
    delete ice;
    // La materia équipée (cure) sera supprimée par le destructeur de Character
}

TEST(Ex03_CharacterTest, CopyConstructor) {
    MateriaSource source;
    source.learnMateria(new Ice());
    source.learnMateria(new Cure());

    Character original("Original");
    original.equip(source.createMateria("ice"));
    original.equip(source.createMateria("cure"));

    // Copier le character
    Character copy(original);

    EXPECT_EQ(copy.getName(), "Original");

    // Utiliser les materias dans le copy
    Character target("Enemy");

    std::string outputCopyUse0 = capture_stdout([&]() { copy.use(0, target); });
    std::string outputCopyUse1 = capture_stdout([&]() { copy.use(1, target); });

    EXPECT_EQ(outputCopyUse0, "* shoots an ice bolt at Enemy *\n");
    EXPECT_EQ(outputCopyUse1, "* heals Enemy's wounds *\n");

    // Modifier le copy et vérifier que l'original n'est pas affecté
    AMateria *newIce = source.createMateria("ice");
    copy.equip(newIce);

    std::string outputOriginalUse2 = capture_stdout([&]() { original.use(2, target); });
    EXPECT_EQ(outputOriginalUse2, ""); // original n'a que 2 materias

    // Nettoyage : les materias du copy seront supprimées par son destructeur
}

TEST(Ex03_CharacterTest, AssignmentOperator) {
    MateriaSource source;
    source.learnMateria(new Ice());
    source.learnMateria(new Cure());

    Character original("Original");
    original.equip(source.createMateria("ice"));
    original.equip(source.createMateria("cure"));

    Character assigned("Assigned");
    assigned = original;

    EXPECT_EQ(assigned.getName(), "Original");

    // Utiliser les materias dans le assigned
    Character target("Enemy");

    std::string outputAssignedUse0 = capture_stdout([&]() { assigned.use(0, target); });
    std::string outputAssignedUse1 = capture_stdout([&]() { assigned.use(1, target); });

    EXPECT_EQ(outputAssignedUse0, "* shoots an ice bolt at Enemy *\n");
    EXPECT_EQ(outputAssignedUse1, "* heals Enemy's wounds *\n");

    // Modifier le assigned et vérifier que l'original n'est pas affecté
    AMateria *newCure = source.createMateria("cure");
    assigned.equip(newCure);

    std::string outputOriginalUse2 = capture_stdout([&]() { original.use(2, target); });
    EXPECT_EQ(outputOriginalUse2, ""); // original n'a que 2 materias

    // Nettoyage : les materias du assigned seront supprimées par son destructeur
}

// Test de la classe MateriaSource
TEST(Ex03_MateriaSourceTest, LearnAndCreateMateria) {
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
    // Les materias apprises sont gérées par MateriaSource
}

TEST(Ex03_MateriaSourceTest, LearnMateriaLimit) {
    MateriaSource source;

    // Apprendre jusqu'à 4 materias
    source.learnMateria(new Ice());
    source.learnMateria(new Cure());
    source.learnMateria(new Ice());
    source.learnMateria(new Cure());

    // Essayer d'apprendre un cinquième materia
    AMateria *extra = new Ice();
    source.learnMateria(extra); // Doit être ignoré donc fuite de mémoire car non supprimé
    delete extra;

    // Créer des materias apprises
    AMateria *ice1 = source.createMateria("ice");
    AMateria *cure1 = source.createMateria("cure");
    AMateria *ice2 = source.createMateria("ice");
    AMateria *cure2 = source.createMateria("cure");
    AMateria *ice3 = source.createMateria("caca"); // Doit être nullptr

    EXPECT_NE(ice1, nullptr);
    EXPECT_EQ(ice1->getType(), "ice");

    EXPECT_NE(cure1, nullptr);
    EXPECT_EQ(cure1->getType(), "cure");

    EXPECT_NE(ice2, nullptr);
    EXPECT_EQ(ice2->getType(), "ice");

    EXPECT_NE(cure2, nullptr);
    EXPECT_EQ(cure2->getType(), "cure");

    EXPECT_EQ(ice3, nullptr);

    delete ice1;
    delete cure1;
    delete ice2;
    delete cure2;
    // ice3 est nullptr, pas besoin de delete
}

TEST(Ex03_MateriaSourceTest, CloneMaterias) {
    MateriaSource source;
    source.learnMateria(new Ice());

    AMateria *ice = source.createMateria("ice");
    AMateria *iceClone = ice->clone();

    EXPECT_NE(iceClone, ice);
    EXPECT_EQ(iceClone->getType(), "ice");

    delete ice;
    delete iceClone;
}

// Test de l'absence de fuites lors de l'utilisation de MateriaSource
TEST(Ex03_MemoryTest, NoMemoryLeaks) {
    // Ce test ne peut pas être réalisé directement avec Google Test
    // Utilisez Valgrind ou un autre outil pour vérifier les fuites de mémoire
    SUCCEED();
}

// Test de la gestion de Materias déséquipées
TEST(Ex03_CharacterTest, ManageUnequippedMaterias) {
    MateriaSource source;
    source.learnMateria(new Ice());
    source.learnMateria(new Cure());

    Character character("Player");
    Character target("Enemy");

    AMateria *ice = source.createMateria("ice");
    AMateria *cure = source.createMateria("cure");

    character.equip(ice);
    character.equip(cure);

    // Déséquipe les deux materias
    character.unequip(0);
    character.unequip(1);

    // Utiliser les slots déséquipés (doit ne rien faire)
    std::string outputUse0 = capture_stdout([&]() { character.use(0, target); });
    std::string outputUse1 = capture_stdout([&]() { character.use(1, target); });

    EXPECT_EQ(outputUse0, "");
    EXPECT_EQ(outputUse1, "");

    // Les materias déséquipées ne sont pas gérées par le Character et doivent être supprimées
    // manuellement
    delete ice;
    delete cure;
}

// Test de l'équipement après déséquipement
TEST(Ex03_CharacterTest, EquipAfterUnequip) {
    MateriaSource source;
    source.learnMateria(new Ice());
    source.learnMateria(new Cure());

    Character character("Player");
    Character target("Enemy");

    AMateria *ice1 = source.createMateria("ice");
    AMateria *cure1 = source.createMateria("cure");
    AMateria *ice2 = source.createMateria("ice");

    character.equip(ice1);
    character.equip(cure1);

    // Déséquipe la première materia
    character.unequip(0);

    // Équipe une nouvelle materia
    character.equip(ice2);

    // Utiliser les materias
    std::string outputUse1 = capture_stdout([&]() { character.use(1, target); });
    std::string outputUse2 = capture_stdout([&]() { character.use(0, target); });

    EXPECT_EQ(outputUse1, "* heals Enemy's wounds *\n");
    EXPECT_EQ(outputUse2, "* shoots an ice bolt at Enemy *\n");

    // Nettoyage : la materia déséquipée initialement (ice1) doit être supprimée manuellement
    delete ice1;
    // Les autres materias seront supprimées par le destructeur de Character
}
