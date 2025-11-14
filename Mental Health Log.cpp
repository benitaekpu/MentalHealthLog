#include <iostream>
#include <fstream>
#include <chrono>
#include <string>


int main() {

    while (true) {
        int choice = 0;

        std::cout << "\nWhat would you like to do today?\n"
            << "1. Make entry for today\n"
            << "2. Redo or delete today's entry\n"
            << "3. Display all entries\n"
            << "4. Display entry from a specific date\n"
            << "5. Generate random encouragement\n"
            << "6. Generate random fortune\n"
            << "7. Exit\n";

        std::cin >> choice;
        std::cin.ignore(); // clear leftover newline

        std::string todays_entry;
        std::string output_file = "log.txt";

        switch (choice) {
        case 1: {
            std::cout << "Write today's entry:\n> ";
            std::getline(std::cin, todays_entry);

            std::ofstream os(output_file, std::ios::app);

            if (os.is_open()) {
                os << "Entry: " << todays_entry << "\n";
                os.close();
                std::cout << "Entry saved.\n";
            }
            else {
                std::cerr << "Error: Unable to open file.\n";
            }
            break;
        }

        case 7:
            std::cout << "Goodbye!\n";
            return 0;

        default:
            std::cout << "Invalid entry. Please choose 1–7.\n";
        }
    }

    return 0;
}
