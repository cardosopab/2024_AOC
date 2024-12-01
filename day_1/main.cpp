#include <algorithm>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  // Add puzzle.txt to directory
  std::string file_name = "puzzle.txt";
  std::fstream input_file(file_name);
  std::string curr;
  std::vector<int> arr1, arr2;

  while (std::getline(input_file, curr)) {
    std::istringstream line_stream(curr);
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
  std::cout << res << std::endl;
}
