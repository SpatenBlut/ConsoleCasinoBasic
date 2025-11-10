#include <iostream>
#include <string>
#include <Windows.h>
#include "money.h"
#include "coin_flip.h"
#include "roulette.h"

int option;
bool loop;

void CflipUI() {

	std::string ht;

	bet();

	while (true) {
		std::cout << "heads or tails: ";
		std::cin >> ht;

		if (ht == "heads" || ht == "tails") {
			HeadsTails(ht);
			break;
		}
		else {
			system("cls");
			std::cout << "Incorrect Input\n";
		}
	}
}

void RouletteUI() {
	Roulette();
}




int main() {
	bool loop = true;
	while (loop == true) {
		read();
		std::cout << "CASINO ROYAL	";
		abalance();
		std::cout << "1: Coin Flip\n";
		std::cout << "2: Roulette\n";
		std::cout << "4: Reset Balance\n";
		std::cout << "5: Exit\n";
		std::cin >> option;
		system("cls");
		if (option == 1) {
			CflipUI();
		}
		else if (option == 2) {
			RouletteUI();
		}
		else if (option == 4)
		{
			reset_balance();
		}
		else {
			loop = false;
		}
	}
}