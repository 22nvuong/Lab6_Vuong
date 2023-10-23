#include <iostream>
#include <fstream> // read/write files
#include <iomanip> // io manipulation

static const int max_size = 100;

// function prototypes
void readFile(int matrixA[max_size][max_size], int matrixB[max_size][max_size], int & size, const char * filename);
void printMatrix(const int matrix[max_size][max_size], int size);
void addMatrix(const int matrixA[max_size][max_size], const int matrixB[max_size][max_size], int matrix_results[max_size][max_size], int size);
void multiplyMatrix(const int matrixA[max_size][max_size], const int matrixB[max_size][max_size], int matrix_results[max_size][max_size], int size);
void subtractMatrix(const int matrixA[max_size][max_size], const int matrixB[max_size][max_size], int matrix_results[max_size][max_size], int size);

int main() {
    int arrA[max_size][max_size];
    int arrB[max_size][max_size];
    int arrR[max_size][max_size]; //result matrix
    int size;

    readFile(arrA, arrB, size, "matrix_input.txt");

    std::cout << "Nikka Vuong" << std::endl; 
    std::cout << "Lab #6: Matrix manipulation\n" << std::endl;

    // prints elements for matrix A
    std::cout << "Matrix A:" << std::endl;
    printMatrix(arrA, size);
    std::cout << std::endl;

    // prints elements for matrix B
    std::cout << "Matrix B:" << std::endl;
    printMatrix(arrB, size);
    std::cout << std::endl;

    // add matrix a and b
    std::cout << "Matrix Sum (A + B):" << std::endl;
    addMatrix(arrA, arrB, arrR, size);
    printMatrix(arrR, size);
    std::cout << std::endl;
    
    // multiply matrix a and b
    std::cout << "Matrix Product (A * B):" << std::endl;
    multiplyMatrix(arrA, arrB, arrR, size);
    
    printMatrix(arrR, size);
    std::cout << std::endl;

    // subtract matrix b and a
    std::cout << "Matrix Difference (A - B):" << std::endl;
    subtractMatrix(arrA, arrB, arrR, size);
    printMatrix(arrR, size);
    std::cout << std::endl;
    
    return 0;
}

//functions below
void readFile(int matrixA[max_size][max_size], int matrixB[max_size][max_size], int & size, const char * filename) {
    std::ifstream file(filename);
    if (!file){
        std::cerr << "File Error" << filename << std::endl;
        exit(1);
    }
    file >> size;
    // matrix A
    for (int i = 0; i < (size); ++i) { //iterates through rows
        for (int j = 0; j < size; ++j) { //iterates through columns
            file >> matrixA[i][j]; //stores values
        }
    }
    //matrix B
    for (int i = 0; i < (size); ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrixB[i][j];
        }
    }
}

void printMatrix(const int matrix[max_size][max_size], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::left << std::setw(3) << matrix[i][j] << " "; 
        }
        std::cout << std::endl;
    }
}

void addMatrix(const int matrixA[max_size][max_size], const int matrixB[max_size][max_size], int matrix_results[max_size][max_size], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix_results[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrix(const int matrixA[max_size][max_size], const int matrixB[max_size][max_size], int matrix_results[max_size][max_size], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix_results[i][j] = 0;
            for (int k = 0; k < size; k++) {
                matrix_results[i][j] += (matrixA[i][k] * matrixB[k][j]); 
            } 
        }
    }
}

void subtractMatrix(const int matrixA[max_size][max_size], const int matrixB[max_size][max_size], int matrix_results[max_size][max_size], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix_results[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}
