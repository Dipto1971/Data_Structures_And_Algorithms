#include <iostream>
#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()

void DiptoLovesTishi() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned>(time(0)));

    // Generate a random number between 1 and 5
    int repeatCount = rand() % 5 + 1;

    // Print the message multiple times based on the random number
    for (int i = 0; i < repeatCount; ++i) {
        std::cout << "Dipto loves Tishi <3" << std::endl;
    }
}










int main() {
    DiptoLovesTishi();
    return 0;
}
