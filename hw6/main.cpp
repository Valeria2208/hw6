//
//  main.cpp
//  hw6
//
//  Created by Valeria Dudinova on 17.10.2024.
//

#include <iostream>
using namespace std;

// Класс A для использования в шаблоне
class A
{
private:
    int value;
public:
    A(int v = 0) : value(v) {}

    // Перегрузка оператора +
    A operator+(const A& other) const
    {
        return A(value + other.value);
    }

    // Перегрузка оператора -
    A operator-(const A& other) const
    {
        return A(value - other.value);
    }

    // Перегрузка оператора *
    A operator*(const A& other) const
    {
        return A(value * other.value);
    }

    // Перегрузка оператора /
    A operator/(const A& other) const
    {
        if (other.value != 0) {
            return A(value / other.value);
        } else {
            throw runtime_error("Division by zero!");
        }
    }

    void display() const
    {
        cout << value;
    }

    void input()
    {
        cin >> value;
    }
};

// Шаблонный класс Matrix
template <typename T>
class Matrix {
private:
    int rows, cols;
    T** data;

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i)
        {
            data[i] = new T[cols];
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    void fillFromKeyboard()
    {
        cout << "Enter matrix elements (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                data[i][j].input();
            }
        }
    }

    void display() const
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                data[i][j].display();
                cout << " ";
            }
            cout << endl;
        }
    }

    // Перегрузка оператора +
    Matrix operator+(const Matrix& other) const
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Перегрузка оператора -
    Matrix operator-(const Matrix& other) const
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Перегрузка оператора *
    Matrix operator*(const Matrix& other) const
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] * other.data[i][j];
            }
        }
        return result;
    }

    // Перегрузка оператора /
    Matrix operator/(const Matrix& other) const
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] / other.data[i][j];
            }
        }
        return result;
    }

    // Поиск максимального элемента
    T findMax() const
    {
        T max = data[0][0];
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (data[i][j] > max)
                {
                    max = data[i][j];
                }
            }
        }
        return max;
    }

    // Поиск минимального элемента
    T findMin() const
    {
        T min = data[0][0];
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (data[i][j] < min)
                {
                    min = data[i][j];
                }
            }
        }
        return min;
    }
};

int main()
{
    Matrix<A> matrix1(2, 2);
    Matrix<A> matrix2(2, 2);

    cout << "Filling the first matrix:\n";
    matrix1.fillFromKeyboard();

    cout << "Filling the second matrix:\n";
    matrix2.fillFromKeyboard();

    cout << "Sum of matrices:\n";
    Matrix<A> sumMatrix = matrix1 + matrix2;
    sumMatrix.display();

    cout << "Maximum element in the first matrix: ";
    matrix1.findMax().display();
    cout << endl;

    cout << "Minimum element in the second matrix: ";
    matrix2.findMin().display();
    cout << endl;

    return 0;
}
