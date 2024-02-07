#include <cstddef>
#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>

const int getNumberOfBuckets() {
  const int max{200'000};
  int x{};

  do {
    std::cout << "Өнгөтэй савнуудын тоог оруулна уу: ";
    std::cin >> x;
  } while (x < 1 || x > max);

  return x;
}

const std::vector<int> getAmountOfPaint(int size) {
  std::vector<int> vector(size);

  while (true) {
    std::cout << "Будагны хэмжээний тооны дараалалыг оруулна уу: ";
    std::cin.ignore();

    std::string input;
    getline(std::cin, input);
    std::istringstream integers{input};

    bool validInput{true};
    int readCount{0};

    for (int i = 0; i < size && integers >> vector[i]; i++) {
      if (vector[i] < 1 || vector[i] > 1e9) {
        validInput = false;
        break;
      }

      readCount++;
    }

    if (validInput && readCount == size) {
      break;
    }
  }

  return vector;
}

const int indexLastMinElement(std::vector<int> &vector) {
  int minElement = vector.back();
  size_t lastIndex = vector.size() - 1;

  for (size_t i = lastIndex; i > 0; --i) {
    if (vector[i - 1] < minElement) {
      minElement = vector[i - 1];
      lastIndex = i - 1;
    }
  }

  return lastIndex == vector.size() - 1 ? 0 : lastIndex;
}

const int maxSquaresPainted(std::vector<int> &vector) {
  const size_t size = vector.size();
  int count{0};

  // Start iterating after last minimum element to paint the most squares
  for (int i = indexLastMinElement(vector) + 1;; ++i) {
    if (vector[i % size] == 0) {
      break;
    }
    --vector[i % size];
    ++count;
  }

  return count;
}

int main(int argc, char *argv[]) {
  int numberOfBuckets = getNumberOfBuckets();
  std::vector<int> paintVector = getAmountOfPaint(numberOfBuckets);
  std::cout << "Намагын их будаж болох боломжтой тоо: "
            << maxSquaresPainted(paintVector);

  return 0;
}
