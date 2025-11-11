#include <random>
#include <iostream>
#include <string>
#include <Windows.h>
#include "money.h"


void Roulette(int numberChoice, std::string colorChoice ) {

    static std::random_device rd;       //Hardware-Seed
    static std::mt19937 gen(rd());      // Mersenne-Twister Generator

    std::uniform_int_distribution<int> numDist(1, 36);
    std::uniform_int_distribution<int> colorDist(0, 1);

    int Nrandom = numDist(gen);
    int Crandom = colorDist(gen);

    std::string Cresult = (Crandom == 0) ? "Red" : "Black";
	Sleep(500);
    std::cout << "Roulette shows: " << Cresult << " " << Nrandom << "\n";

    if (numberChoice == 0) {
        if (colorChoice == Cresult) {
            won();
            std::cout << "you won\n";
        }
        else {
            lost();
            std::cout << "you lost\n";
        }
    }
    else { 
        if (numberChoice == Nrandom && colorChoice == Cresult) {
            won2();
            std::cout << "you won\n";
        }
        else {
            lost();
            std::cout << "you lost\n";
        }
    }
    abalance();


	std::cout << "Press Enter to continue...";
    while (true) {
        if (GetAsyncKeyState(VK_RETURN) & 0x8000) { // VK_RETURN = Enter
            break;
        }
        Sleep(50);
    }
	system("cls");

}

void RouletteUI() {
    std::string colorChoice;
    int numberChoice;

    std::cout << "Choose a color (Red/Black): ";
    std::cin >> colorChoice;
    if (colorChoice != "Red" && colorChoice != "Black") {
        std::cout << "Invalid Color Choice\n";
        Sleep(800);
        system("cls");
        RouletteUI();
        return;
    }

    std::cout << "Choose a number (1-36)" << std::endl;
    std::cout << "If you don't want to choose a number, enter 0: ";
    std::cin >> numberChoice;
    if (numberChoice < 0 || numberChoice > 36) {
        std::cout << "Invalid Number Choice\n";
        Sleep(800);
        system("cls");
        RouletteUI();
        return;
    }
    
    Roulette(numberChoice, colorChoice);
}