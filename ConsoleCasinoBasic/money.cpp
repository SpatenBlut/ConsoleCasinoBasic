#include <iostream>
#include <Windows.h>
#include <fstream>

int balance;
int amount;

// Function to read balance from file
void read() {
	std::ifstream MyReadFile("money.ini");
	if (MyReadFile.is_open()) {
		MyReadFile >> balance;
		MyReadFile.close();
	}
	else {
		balance = 100;
		std::ofstream MyFile("money.ini");
		MyFile << balance;
		MyFile.close();
	}
}
// Function to write balance to file
void write(int wMoney) {
	std::ofstream MyFile("money.ini");
	MyFile << wMoney;
	MyFile.close();
}

// Function to handle betting
void bet() {
	read();
	std::cout << "Bet Amount: ";
	std::cin >> amount;
	// Validate bet amount
	if (amount > balance) {
		std::cout << "Insufficient Funds\n";
		Sleep(1500);
		system("cls");
		bet();
	}
	else if (amount <= 0) {
		std::cout << "Invalid Bet\n";
		Sleep(1500);
		system("cls");
		bet();
	}
	system("cls");
}

void lost() {
	read();
	balance -= amount;
	write(balance);
}

void won() {
	read();
	balance += amount;
	write(balance);
}

void abalance() {
	read();
	std::cout << "Balance: " << balance << std::endl;
}

void reset_balance() {
	balance = 100;
	write(balance);
}