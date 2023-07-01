#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>  

int select_mode() {

	char mode_select;

	std::cout << "Select your desired mode" << std::endl;

	std::cout << "" << std::endl;

	std::cout << "[1] Add an entry to the to-do list" << std::endl;

	std::cout << "" << std::endl;

	std::cout << "[2] Delete / clear entries" << std::endl;

	std::cout << "" << std::endl;

	std::cin >> mode_select;

	return mode_select;
}

void mode_add();

void mode_clear() {
	system("cls");

	char input;

	std::cout << "Do really want to clear the log? [y/n]: ";

	std::cin >> input;

	if (input == 'y') {
		std::ofstream file("todolist.txt", std::ios::trunc);

		if (file.is_open()) {

			file.close();
		}
		else {
			std::cout << "Cannot open file" << std::endl;
		}

		system("cls");

		char mode_select = select_mode();

		if (mode_select == '1') {

			mode_add();

		}
		else if (mode_select == '2') {
			mode_clear();
		}
	}
	else if (input == 'n') {
		system("cls");

		char mode_select = select_mode();

		if (mode_select == '1') {

			mode_add();

		}
		else if (mode_select == '2') {
			mode_clear();
		}
	}
}

void mode_add() {

	char input;

	std::string input_todo;

	system("cls");

	std::cin.ignore();

	std::cout << "Enter your to-do list entry here: ";

	std::getline(std::cin, input_todo);

	std::cout << "You entered: " << input_todo << std::endl;

	std::cout << "Do you want to add this entry to the log? [y/n]: ";

	std::cin >> input;

	if (input == 'y') {

		std::ofstream file("todolist.txt", std::ios::app);

		if (file.is_open()) {

			time_t now = time(0);

			char* date_time = ctime(&now);

			date_time[strcspn(date_time, "\n")] = '\0'; // es wird ehrenlos

			file << "[" << date_time << "] " << input_todo << std::endl;

			file.close();

			std::cout << "Do you want to add another entry to the log? [y/n]: ";

			std::cin >> input;

			if (input == 'y') {
				mode_add();
			}
			else if (input == 'n') {

				system("cls");

				char mode_select = select_mode();

				if (mode_select == '1') {

					mode_add();

				}
				else if (mode_select == '2') {
					mode_clear();
				}
			}
		}
		else {

			std::cout << "Error opening the file" << std::endl;
		}
	}
	else if (input == 'n') {

		system("cls");

		char mode_select = select_mode();

		if (mode_select == '1') {

			mode_add();

		}
		else if (mode_select == '2') {
			mode_clear();
		}
	}
}

int main() {

	char mode_select = select_mode();

	if (mode_select == '1') {

		mode_add();

	}
	else if (mode_select == '2') {
		mode_clear();
	}
}