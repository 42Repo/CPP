#include <gtest/gtest.h>
#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"
#include "DiamondTrap.h"

// Test des constructeurs par défaut
TEST(ClapTrapTest, DefaultConstructorTest) {
    ClapTrap ct;
    ASSERT_EQ(ct.getName(), "DefaultClap");
    ASSERT_EQ(ct.show(), "ClapTrap DefaultClap has 10 hit points, 10 energy points and 0 attack damage");
}

TEST(ScavTrapTest, DefaultConstructorTest) {
    ScavTrap st;
    ASSERT_EQ(st.getName(), "DefaultScav");
    ASSERT_EQ(st.show(), "ScavTrap DefaultScav has 100 hit points, 50 energy points and 20 attack damage");
}

TEST(FragTrapTest, DefaultConstructorTest) {
    FragTrap ft;
    ASSERT_EQ(ft.getName(), "DefaultFrag");
    ASSERT_EQ(ft.show(), "FragTrap DefaultFrag has 100 hit points, 100 energy points and 30 attack damage");
}

TEST(DiamondTrapTest, DefaultConstructorTest) {
    DiamondTrap dt;
    ASSERT_EQ(dt.getName(), "Default");
    ASSERT_EQ(dt.ClapTrap::getName(), "Default_clap_name");
    ASSERT_EQ(dt.show(), "DiamondTrap Default has 100 hit points, 50 energy points and 30 attack damage");
}

// Test des constructeurs avec paramètres
TEST(ClapTrapTest, ParameterizedConstructorTest) {
    ClapTrap ct("Clappy");
    ASSERT_EQ(ct.getName(), "Clappy");
    ASSERT_EQ(ct.show(), "ClapTrap Clappy has 10 hit points, 10 energy points and 0 attack damage");
}

TEST(ScavTrapTest, ParameterizedConstructorTest) {
    ScavTrap st("Scavvy");
    ASSERT_EQ(st.getName(), "Scavvy");
    ASSERT_EQ(st.show(), "ScavTrap Scavvy has 100 hit points, 50 energy points and 20 attack damage");
}

TEST(FragTrapTest, ParameterizedConstructorTest) {
    FragTrap ft("Fraggy");
    ASSERT_EQ(ft.getName(), "Fraggy");
    ASSERT_EQ(ft.show(), "FragTrap Fraggy has 100 hit points, 100 energy points and 30 attack damage");
}

TEST(DiamondTrapTest, ParameterizedConstructorTest) {
    DiamondTrap dt("Diamondy");
    ASSERT_EQ(dt.getName(), "Diamondy");
    ASSERT_EQ(dt.ClapTrap::getName(), "Diamondy_clap_name");
    ASSERT_EQ(dt.show(), "DiamondTrap Diamondy has 100 hit points, 50 energy points and 30 attack damage");
}

// Test des méthodes 'attack'
TEST(ClapTrapTest, AttackTest) {
    ClapTrap ct("Clappy");
    ct.attack("Enemy");
    ASSERT_EQ(ct.show(), "ClapTrap Clappy has 10 hit points, 9 energy points and 0 attack damage");
}

TEST(ScavTrapTest, AttackTest) {
    ScavTrap st("Scavvy");
    st.attack("Enemy");
    ASSERT_EQ(st.show(), "ScavTrap Scavvy has 100 hit points, 49 energy points and 20 attack damage");
}

TEST(FragTrapTest, AttackTest) {
    FragTrap ft("Fraggy");
    ft.attack("Enemy");
    ASSERT_EQ(ft.show(), "FragTrap Fraggy has 100 hit points, 99 energy points and 30 attack damage");
}

TEST(DiamondTrapTest, AttackTest) {
    DiamondTrap dt("Diamondy");
    dt.attack("Enemy");
    ASSERT_EQ(dt.show(), "DiamondTrap Diamondy has 100 hit points, 49 energy points and 30 attack damage");
}

// Test des méthodes 'takeDamage'
TEST(ClapTrapTest, TakeDamageTest) {
    ClapTrap ct("Clappy");
    ct.takeDamage(5);
    ASSERT_EQ(ct.show(), "ClapTrap Clappy has 5 hit points, 10 energy points and 0 attack damage");
    ct.takeDamage(10);
    ASSERT_EQ(ct.show(), "ClapTrap Clappy has 0 hit points, 10 energy points and 0 attack damage");
}

TEST(ScavTrapTest, TakeDamageTest) {
    ScavTrap st("Scavvy");
    st.takeDamage(20);
    ASSERT_EQ(st.show(), "ScavTrap Scavvy has 80 hit points, 50 energy points and 20 attack damage");
    st.takeDamage(100);
    ASSERT_EQ(st.show(), "ScavTrap Scavvy has 0 hit points, 50 energy points and 20 attack damage");
}

TEST(FragTrapTest, TakeDamageTest) {
    FragTrap ft("Fraggy");
    ft.takeDamage(50);
    ASSERT_EQ(ft.show(), "FragTrap Fraggy has 50 hit points, 100 energy points and 30 attack damage");
    ft.takeDamage(100);
    ASSERT_EQ(ft.show(), "FragTrap Fraggy has 0 hit points, 100 energy points and 30 attack damage");
}

TEST(DiamondTrapTest, TakeDamageTest) {
    DiamondTrap dt("Diamondy");
    dt.takeDamage(30);
    ASSERT_EQ(dt.show(), "DiamondTrap Diamondy has 70 hit points, 50 energy points and 30 attack damage");
    dt.takeDamage(100);
    ASSERT_EQ(dt.show(), "DiamondTrap Diamondy has 0 hit points, 50 energy points and 30 attack damage");
}

// Test des méthodes 'beRepaired'
TEST(ClapTrapTest, BeRepairedTest) {
    ClapTrap ct("Clappy");
    ct.takeDamage(8);
    ct.beRepaired(5);
    ASSERT_EQ(ct.show(), "ClapTrap Clappy has 7 hit points, 9 energy points and 0 attack damage");
    ct.beRepaired(20); // HP shouldn't exceed maximum
    ASSERT_EQ(ct.show(), "ClapTrap Clappy has 27 hit points, 8 energy points and 0 attack damage");
}

TEST(ScavTrapTest, BeRepairedTest) {
    ScavTrap st("Scavvy");
    st.takeDamage(90);
    st.beRepaired(10);
    ASSERT_EQ(st.show(), "ScavTrap Scavvy has 20 hit points, 49 energy points and 20 attack damage");
    st.beRepaired(100);
    ASSERT_EQ(st.show(), "ScavTrap Scavvy has 120 hit points, 48 energy points and 20 attack damage");
}

TEST(FragTrapTest, BeRepairedTest) {
    FragTrap ft("Fraggy");
    ft.takeDamage(100);
    ft.beRepaired(50);
    ASSERT_EQ(ft.show(), "FragTrap Fraggy has 50 hit points, 99 energy points and 30 attack damage");
    ft.beRepaired(60);
    ASSERT_EQ(ft.show(), "FragTrap Fraggy has 110 hit points, 98 energy points and 30 attack damage");
}

TEST(DiamondTrapTest, BeRepairedTest) {
    DiamondTrap dt("Diamondy");
    dt.takeDamage(90);
    dt.beRepaired(20);
    ASSERT_EQ(dt.show(), "DiamondTrap Diamondy has 30 hit points, 49 energy points and 30 attack damage");
}

// Test des méthodes spécifiques de DiamondTrap
TEST(DiamondTrapTest, WhoAmITest) {
    DiamondTrap dt("Diamondy");
    dt.whoAmI();
    ASSERT_EQ(dt.getName(), "Diamondy");
    ASSERT_EQ(dt.ClapTrap::getName(), "Diamondy_clap_name");
}

// Main pour exécuter les tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
