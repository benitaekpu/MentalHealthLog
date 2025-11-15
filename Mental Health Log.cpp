#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>   // rand

// generate random encouragement case 5
std::string getRandomEncouragement(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return "Error: Could not open encouragement file.";
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        if (!line.empty())
            lines.push_back(line);
    }

    if (lines.empty()) {
        return "No encouragements found.";
    }

    // Seed random once using time
    std::srand(std::time(0));

    int index = std::rand() % lines.size();
    return lines[index];
}



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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // file to store entries in
        std::string output_file = "log.txt";
        // file where encouragements are stored in
        std::string msg = getRandomEncouragement("encouragements.txt");


   

    switch (choice) {

        case 1: {
        

            // ==== GET ENTRY ====
            std::string todays_entry;
            std::cout << "Write today's entry:\n> ";
            std::getline(std::cin, todays_entry);

            // ==== WRITE TO FILE ====
            std::ofstream os(output_file, std::ios::app);
            if (os.is_open()) {

                 os << "Entry: " << todays_entry << "\n\n";
                os.close();
                std::cout << "Entry saved.\n";
            }
            else {
                std::cerr << "Error: Unable to open file.\n";
            }
            break;
        }
        case 5:
            std::cout << "\n Encouragement: " << msg << "\n";
            break;
        case 7:
            std::cout << "Goodbye!\n";
            return 0;

        default:
            std::cout << "Invalid entry. Please choose 1–7.\n";
        }
    }

    return 0;
}
