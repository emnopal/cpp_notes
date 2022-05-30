#include <iostream>
using namespace std;

template<typename T>
class Matrix
{
public:
    Matrix(unsigned nrows, unsigned ncols) 
        : m_nrows(nrows), m_ncols(ncols)
    {
        m_data = new T[m_nrows*m_ncols]();
    }
    ~Matrix()
    {
        delete[] m_data;
    }
    void setElement(unsigned row, unsigned col, const T elem)
    {
        m_data[(row - 1) * m_ncols + (col - 1)] = elem;
    }
    template<typename T>
    friend ostream& operator<<(ostream& os, const Matrix<T>& mat);
private:
    T* m_data;
    unsigned m_nrows;
    unsigned m_ncols;
};

template<typename T>
ostream& operator<<(ostream& os, const Matrix<T>& mat)
{
    for (unsigned i = 0; i < mat.m_nrows; i++)
    {
        for (unsigned j = 0; j < mat.m_ncols; j++)
        {
            cout << mat.m_data[i*mat.m_ncols + j] << " ";
        }
        cout << endl;
    }
    return os;
}

int main(int argc, char** argv) {
    if (argc < 3)
    {
        cout << "Usage: <program name> <num rows> <num cols>" << endl;
    }

    int nrows = atoi(argv[1]), ncols = atoi(argv[2]);
    Matrix<int> intMatrix(nrows, ncols);
    cout << intMatrix;

    // your code goes here
    return 0;
}

