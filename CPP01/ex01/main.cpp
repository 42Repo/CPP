#include "Zombie.h"

int main(void) {
    const int N = 5;

    Zombie *zombies = zombieHorde(N, "Zombie");
    for (int i = 0; i < N; i++) {
        zombies[i].announce();
    }

    zombies[0].setName("Zombie0");
    zombies[0].announce();
    zombies[1].setName("Zombie1");
    zombies[1].announce();
    zombies[2].setName("Zombie2");
    zombies[2].announce();
    zombies[3].setName("Zombie3");
    zombies[3].announce();
    zombies[4].setName("Zombie4");
    zombies[4].announce();

    delete[] zombies;
    return 0;
}
