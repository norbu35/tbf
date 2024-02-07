#include <iostream>

int **generateSpiralMatrix(int n) {

  int **matrix = new int *[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[n];
  }

  int top{0};
  int bottom{n};
  int left{0};
  int right{n};
  int value{1};

  while ((left < right) && (top < bottom)) {
    // Top row
    for (int i = left; i < right; i++) {
      matrix[top][i] = value++;
    }
    top += 1;

    // Right column
    for (int i = top; i < bottom; i++) {
      matrix[i][right - 1] = value++;
    }
    right -= 1;

    if (!(left < right) || !(top < bottom)) {
      break;
    }

    // Bottom row
    for (int i = right - 1; i >= left; i--) {
      matrix[bottom - 1][i] = value++;
    }
    bottom -= 1;

    // Left column
    for (int i = bottom - 1; i >= top; i--) {
      matrix[i][left] = value++;
    }
    left += 1;
  }

  return matrix;
}

const void printMatrix(int **matrix, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << matrix[i][j];
    }
    std::cout << '\n';
  }
}

int main(int argc, char *argv[]) {
  int n{};
  do {
    std::cout << "Матрицын N (NxN) oруулна уу: ";
    std::cin >> n;
  } while (n < 0 || n > 1000000);

  int **matrix{generateSpiralMatrix(n)};

  std::cout << "X, Y оруулна уу: ";
  int x{};
  int y{};
  std::cin >> x >> y;

  std::cout << matrix[x][y] << '\n';
  // printMatrix(matrix, n);

  return 0;
}
