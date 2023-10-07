#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

void searchFiles(const std::string& directory, const std::string& searchQuery);

int main()
{
    std::string searchQuery;
    std::string directory = "C:/Users/Nolan/Desktop/drive-download-20231007T172104Z-001"; // Specify the directory where you want to search
    std::cout << "Search: ";
    std::cin >> searchQuery;

    searchFiles(directory, searchQuery);

    return 0;
}

void searchFiles(const std::string& directory, const std::string& searchQuery) {
    std::vector<std::string> matchingFiles;
    
    // Iterate over each file in the directory
    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            // Check if the file name contains the search query
            std::string fileName = entry.path().filename().string();
            if (fileName.find(searchQuery) != std::string::npos) {
                matchingFiles.push_back(fileName);
            }
        }
    }
    
    // Print the matching file names
    if (!matchingFiles.empty()) {
        std::cout << "Matching files found:" << std::endl;
        for (const auto& file : matchingFiles) {
            std::cout << file << std::endl;
        }
    } else {
        std::cout << "No matching files found." << std::endl;
    }
}