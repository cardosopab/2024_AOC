#include <algorithm>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

void part_1(std::string file_name) {
  // Add puzzle.txt to directory
  std::fstream input_file(file_name);
  std::string curr_line;
  std::vector<int> arr1, arr2;

  while (std::getline(input_file, curr_line)) {
    std::istringstream line_stream(curr_line);
    int col1, col2;
    if (line_stream >> col1 >> col2) {
      arr1.push_back(col1);
      arr2.push_back(col2);
    }
  }
  input_file.close();

  std::sort(arr1.begin(), arr1.end());
  std::sort(arr2.begin(), arr2.end());

  int res = 0;
  for (int i = 0; i < arr1.size(); i++) {
    res += abs(arr1[i] - arr2[i]);
  }
  std::cout << "Part 1: " << res << std::endl;
}

void part_2(std::string file_name) {
  // Add puzzle.txt to directory
  std::fstream input_file(file_name);
  std::string curr_line;
  std::vector<int> arr1;
  std::unordered_map<int, int> map;

  while (std::getline(input_file, curr_line)) {
    std::istringstream line_stream(curr_line);
    int col1, col2;
    if (line_stream >> col1 >> col2) {
      arr1.push_back(col1);
      map[col2]++;
    }
  }
  input_file.close();

  int res = 0;
  for (int n : arr1) {
    res += n * map[n];
  }
  std::cout << "Part 2: " << res << std::endl;
}
int main() {
  // std::string file_name = "test.txt";
  std::string file_name = "puzzle.txt";
  part_1(file_name);
  part_2(file_name);
}
