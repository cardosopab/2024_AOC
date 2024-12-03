#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

void part_1(std::string file_name) {
  std::fstream input_file(file_name);
  std::string curr_line;
  int res = 0;

  while (std::getline(input_file, curr_line)) {
    std::istringstream line_stream(curr_line);
    int val;
    std::vector<int> arr;

    while (line_stream >> val) {
      arr.push_back(val);
    }

    bool increasing = arr[0] < arr[1];
    bool monotonic = true;

    if (increasing) {
      for (int i = 1; i < arr.size(); i++) {
        if (arr[i - 1] >= arr[i] || abs(arr[i - 1] - arr[i]) > 3) {
          monotonic = false;
          break;
        }
      }
    } else {
      for (int i = 1; i < arr.size(); i++) {
        if (arr[i - 1] <= arr[i] || abs(arr[i - 1] - arr[i]) > 3) {
          monotonic = false;
          break;
        }
      }
    }

    if (monotonic)
      res++;
  }
  input_file.close();

  std::cout << "Part 1: " << res << std::endl;
}

bool is_safe(std::vector<int> arr) {
  bool increasing = arr[0] < arr[1];
  bool monotonic = true;

  if (increasing) {
    for (int i = 1; i < arr.size(); i++) {
      if (arr[i - 1] >= arr[i] || abs(arr[i - 1] - arr[i]) > 3) {
        monotonic = false;
        break;
      }
    }
  } else {
    for (int i = 1; i < arr.size(); i++) {
      if (arr[i - 1] <= arr[i] || abs(arr[i - 1] - arr[i]) > 3) {
        monotonic = false;
        break;
      }
    }
  }

  return monotonic;
}

void part_2(std::string file_name) {
  std::fstream input_file(file_name);
  std::string curr_line;
  int res = 0;

  while (std::getline(input_file, curr_line)) {
    std::istringstream line_stream(curr_line);
    int val;
    std::vector<int> arr;

    while (line_stream >> val) {
      arr.push_back(val);
    }

    bool safe = false;
    for (int i = 0; i < arr.size(); i++) {
      std::vector<int> temp(arr.begin(), arr.begin() + i);
      temp.insert(temp.end(), arr.begin() + i + 1, arr.end());

      if (is_safe(temp)) {
        safe = true;
        break;
      }
    }

    if (safe)
      res++;
  }
  input_file.close();

  std::cout << "Part 2: " << res << std::endl;
}

int main() {
  // std::string file_name = "test.txt";
  std::string file_name = "puzzle.txt";
  // part_1(file_name);
  // First 495 too low.
  // Second 501 too low.
  part_2(file_name);
}
