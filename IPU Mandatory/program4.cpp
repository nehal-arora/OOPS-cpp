#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class matrix {
    int rows, cols;
    int **mat;

public:
    matrix(int r, int c) : rows(r), cols(c) {
        mat = new int*[rows];   // allocate memory for row pointers

        for (int i = 0; i < rows; i++)
            mat[i] = new int[cols];   // allocate each row
    }

    ~matrix() {
        for (int i = 0; i < rows; i++)
            delete[] mat[i];

        delete[] mat;
    }

    // Deep copy constructor
    matrix(const matrix& from) {
        cout << "(Deep) copy constructor is called" << endl;

        rows = from.rows;
        cols = from.cols;

        mat = new int*[rows];

        for (int i = 0; i < rows; i++)
            mat[i] = new int[cols];

        // Copy values
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = from.mat[i][j];
            }
        }
    }

    void initialize() {
        cout << "Enter values of matrix row wise, separated by space and each row on new line:" << endl;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    void print() const {
        cout << "Matrix:" << endl;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << setw(4) << mat[i][j];

            cout << endl;
        }
    }

    matrix multiply(matrix m2) const {
        // Matrix multiplication possible only if:
        // columns of first matrix == rows of second matrix
        if (cols != m2.rows) {
            throw invalid_argument("Matrix multiplication not possible.");
        }

        matrix m3(rows, m2.cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m2.cols; j++) {
                m3.mat[i][j] = 0;

                for (int k = 0; k < cols; k++) {
                    m3.mat[i][j] += mat[i][k] * m2.mat[k][j];
                }
            }
        }

        return m3;
    }
};

int main() {
    int r1, c1, r2, c2;

    cout << "Enter the # of rows and cols in 1st matrix: ";
    cin >> r1 >> c1;

    cout << "Enter the # of rows and cols in 2nd matrix: ";
    cin >> r2 >> c2;

    matrix m1(r1, c1), m2(r2, c2);

    m1.initialize();
    m1.print();

    m2.initialize();
    m2.print();

    try {
        matrix m3 = m1.multiply(m2);

        cout << "Resultant matrix:" << endl;
        m3.print();
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}