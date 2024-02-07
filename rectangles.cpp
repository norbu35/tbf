#include <iostream>

constexpr int numberOfPossibleRectangles(int perimeter) {
  /* Perimeter has to be even to form a rectangle with integer side lengths
   * P = 2x + 2y
   * Smallest possible P is 6
   */
  if (perimeter < 6 || perimeter > 2e9 || perimeter % 2 != 0) {
    return -1;
  }

  // P / 2 = x + y
  int sumOfSideLengths{perimeter / 2};

  // x1 != x2 (sumOfSideLengths / 2)
  // x != y (sumOfSideLengths % 2 == 0 ? -1 : 0)
  return sumOfSideLengths / 2 + (sumOfSideLengths % 2 == 0 ? -1 : 0);
}

void test() {
  int testArray[6] = {2, 6, 20, 15, 50, static_cast<int>(2e10)};

  for (int i = 0; i < std::size(testArray); i++) {
    std::cout << "Perimeter: " << testArray[i]
              << ", Rectangles: " << numberOfPossibleRectangles(testArray[i])
              << '\n';
  }
}

int main(int argc, char *argv[]) {
  int result{-1};
  int perimeter{};
  do {
    std::cout << "Савaaны уртыг оруулна уу: ";
    std::cin >> perimeter;
    result = numberOfPossibleRectangles(perimeter);
  } while (result < 0);
  std::cout << "Тэгш өнцөгт үүсгэх боломжын тоо: "
            << numberOfPossibleRectangles(perimeter) << '\n';

  // test();
}
