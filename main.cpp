#include <iostream>
#include <windows.h>
#include <algorithm>
#include <string>
#include <vector>
#include "color.h"
using namespace std;

int true_count(int rc, int decks) {
	return rc / decks;
}

int main()
{
	std::vector<std::string> more, zero, minus;

	int decks;
	more = { "2","3","4","5","6" };
	zero = { "7","8","9" };
	minus = { "10","j","q","k","a" };
	
	std::cout << "INSERT -  reduce one deck\n";
	std::cout << "end  -  dealer gotta 2nd  card\n";

	std::cout << "quantos baralhos restantes? ";
	std::cin >> decks;
	int roundcount=0;
	int trueCount = 0;

	while (true) {
		int jogadores;
		std::string opt;
		std::string opt2;
		std::cout << "quantos jogadores? ";
		std::cin >> jogadores;
		if (GetAsyncKeyState(VK_INSERT) & 1) {
			decks--;
			std::cout << "baralho:" << decks << "\n";
		}
		for (int i = 0; i < 99; i++) {
			INIT:
			std::cout << "j" << "[" << i << "]" << ":";
			std::cin >> opt;
			if (std::find(more.begin(), more.end(), opt) != more.end()) {
				roundcount += +1;
				trueCount = true_count(roundcount, decks);
			}
			if (std::find(minus.begin(), minus.end(), opt) != minus.end()) {
				roundcount += -1;
				trueCount = true_count(roundcount, decks);
			}

			if (i == jogadores-1) {
				std::cout << "dealer[1]:";
				std::cin >> opt2;
				if (std::find(more.begin(), more.end(), opt2) != more.end()) {
					roundcount += +1;
					trueCount = true_count(roundcount, decks);
				}
				if (std::find(minus.begin(), minus.end(), opt2) != minus.end()) {
					roundcount += -1;
					trueCount = true_count(roundcount, decks);
				}

				if(roundcount >= 1)
					std::cout << "\n" << green << "roundcount:" << roundcount << "\ntruecount:" << trueCount <<"\n" << white;
				else
					std::cout << "\n" << red << "roundcount:" << roundcount << "\ntruecount:" << trueCount << "\n" << white;

			}
			if (opt.find("n") != std::string::npos) {
				std::cout << "Next Round!\n";
				i = 0;
				if (roundcount >= 1)
					std::cout << "\n" << green << "roundcount:" << roundcount << "\ntruecount:" << trueCount << "\n" << white;
				else
					std::cout << "\n" << red << "roundcount:" << roundcount << "\ntruecount:" << trueCount << "\n" << white;
				continue;
			};
			if (i >= jogadores*2 - 1) {
				opt = std::string();

				while (opt.find("d") == std::string::npos) {
					std::cout << "card: ";
					std::cin >> opt;
					if (std::find(more.begin(), more.end(), opt) != more.end()) {
						roundcount += +1;
						trueCount = true_count(roundcount, decks);
					}
					if (std::find(minus.begin(), minus.end(), opt) != minus.end()) {
						roundcount += -1;
						trueCount = true_count(roundcount, decks);
					}
					if (opt.find("n") != std::string::npos) {
						std::cout << "Next Round!\n";
						i = 0;
						if (roundcount >= 1)
							std::cout << "\n" << green << "roundcount:" << roundcount << "\ntruecount:" << trueCount << "\n" << white;
						else
							std::cout << "\n" << red << "roundcount:" << roundcount << "\ntruecount:" << trueCount << "\n" << white;
						goto INIT;
					};
					if (roundcount >= 1)
						std::cout << "\n" << green << "roundcount:" << roundcount << "\ntruecount:" << trueCount << "\n" << white;
					else
						std::cout << "\n" << red << "roundcount:" << roundcount << "\ntruecount:" << trueCount << "\n" << white;
				}
				std::cout << "dealer[2]:";
				std::cin >> opt2;
				if (std::find(more.begin(), more.end(), opt2) != more.end()) {
					roundcount += +1;
					trueCount = true_count(roundcount, decks);
				}
				if (std::find(minus.begin(), minus.end(), opt2) != minus.end()) {
					roundcount += -1;
					trueCount = true_count(roundcount, decks);
				}

				if (roundcount >= 1)
					std::cout << "\n" << green << "roundcount:" << roundcount << "\ntruecount:" << trueCount << "\n" << white;
				else
					std::cout << "\n" << red << "roundcount:" << roundcount << "\ntruecount:" << trueCount << "\n" << white;
			dn:
				opt2= std::string();
				std::cout << "dealer [n]: ";
				std::cin >> opt2;
				if (std::find(more.begin(), more.end(), opt2) != more.end()) {
					roundcount += +1;
					trueCount = true_count(roundcount, decks);
				}
				if (std::find(minus.begin(), minus.end(), opt2) != minus.end()) {
					roundcount += -1;
					trueCount = true_count(roundcount, decks);
				};
				if (opt2.find("n") != std::string::npos) {
					std::cout << "Next Round!\n";
					i = 0;
					if (roundcount >= 1)
						std::cout << "\n" << green << "roundcount:" << roundcount << "\ntruecount:" << trueCount << "\n" << white;
					else
						std::cout << "\n" << red << "roundcount:" << roundcount << "\ntruecount:" << trueCount << "\n" << white;
					goto INIT;
				};
				goto dn;
				if (roundcount >= 1)
					std::cout << "\n" << green << "roundcount:" << roundcount << "\ntruecount:" << trueCount << "\n" << white;
				else
					std::cout << "\n" << red << "roundcount:" << roundcount << "\ntruecount:" << trueCount << "\n" << white;
				if (opt.find("s") != std::string::npos)
					continue;
			}
		}
		if (GetAsyncKeyState(VK_CONTROL) & 1) {
			exit(1);
		}
	}
}
