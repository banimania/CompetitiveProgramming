#include <iostream>
#include <string>

int main() {
  std::string input;

  std::cin >> input;

  int length = (int) (input.length() / 2.0f + 0.5f);
  int* nums = (int*) malloc(length * sizeof(int));

  int c = 0;
  for (int i = 0; i < input.length(); i++) {
    if (input.at(i) != '+') {
      *(nums + c) = int(input.at(i)) - 48;
      c++;
    }
  }

  int temp = 0;
  for (int i = 0; i < length; i++) {
    for (int j = i + 1; j < length; j++) {
      if (nums[j] < nums[i]) {
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
    }
    std::cout << nums[i] << (i == length - 1 ? "" : "+");
  }

  return 0;
}
