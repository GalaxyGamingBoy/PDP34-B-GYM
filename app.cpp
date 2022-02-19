/* USER: [REDACTED]
LANG: C++
TASK: crazyhotel */
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

std::vector<std::string> parameters[2];
std::string strings[2];
std::vector<int> filteredIn, checkVector;
std::vector<int> in;
int out = 0;
int appParameters[3]; // 0: Days, 1: Max Money, 2: Daily Money

std::vector<std::string> splitString(char splitWithCharacter, std::string stringIn) {
    // Split string into segments
    std::string tmpData;
    std::stringstream StringStream(stringIn);
    std::vector<std::string> returnStrings;

    while (std::getline(StringStream, tmpData, splitWithCharacter)) {
        returnStrings.push_back(tmpData);
    }

    return returnStrings;
}

void readFiles(std::string file) {
    std::ifstream fileOpen(file);
    std::getline(fileOpen, strings[0]);
    std::getline(fileOpen, strings[1]);
    fileOpen.close();
}
void writeFile(std::string fileName, int data) {
    std::ofstream file;
    file.open(fileName);
    file << data << "\n";
    file.close();
}

std::vector<int> checkIfVectorEven(std::vector<int> vector) {
    if (vector.size() % 2 != 0) {
        vector.pop_back();
    }
    return vector;
}

int getSizeOfVector(std::vector<int> vector) {
    return sizeof(vector) / sizeof(vector[0]);
}

void filterAndCountSingleDays() {
    for (int i; i < getSizeOfVector(in); i++) {
        if (in[i] <= appParameters[2]) {
            filteredIn.push_back(in[i]);
        }
    }
}

void checkDays(std::vector<int> vector) {
    for (int i; i < getSizeOfVector(vector) / 2; i++) {
        int currValue = vector[i];
        int nextValue = 0;
        try
        {
            nextValue = vector[i + 1];
        }
        catch (const std::exception& e)
        {
            nextValue = appParameters[1] + 1;
        }
        int x = currValue + nextValue;
        if (x <= appParameters[1]) {
            out++;
        }
    }
}

void proccessDataFromFiles() {
    parameters[0] = splitString(' ', strings[0]);
    parameters[1] = splitString(' ', strings[1]);

    appParameters[0] = std::stoi(parameters[0][0]);
    appParameters[1] = std::stoi(parameters[0][1]);
    appParameters[2] = std::stoi(parameters[0][2]);
}

int main() {
    readFiles("crazyhotel.in");
    proccessDataFromFiles();
    for (int i; i < appParameters[0]; i++) {
        in.push_back(std::stoi(parameters[1][i]));
        if (in[i] < appParameters[1]) {
            out++;
        }
    }
    filterAndCountSingleDays();
    checkVector = checkIfVectorEven(filteredIn);
    checkDays(checkVector);
    writeFile("crazyhotel.out", out);
    return 0;
}
