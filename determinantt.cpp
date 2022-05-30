//Determinant
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int n, i, j, k;
    cout.precision(4); //set precision
    cout.setf(ios::fixed);
    cout << "\nEnter the order(n): \n";
    cin >> n;      //input the no. of equations
    float a[n][n]; //declare an array to store the elements of augmented-matrix
    double det = 1;
    int flag = 0;
    cout << "\nEnter the elements of the matrix row-wise:\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j]; //input the elements of array
    for (i = 0; i < n; i++) //Pivotisation
        for (k = i + 1; k < n; k++)
            if (abs(a[i][i]) < abs(a[k][i]))
            {
                flag++;
                for (j = 0; j < n; j++)
                {
                    double temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }

    cout << "\nThe matrix after Pivotisation is:\n";
    for (i = 0; i < n; i++) //print the new matrix
    {
        for (j = 0; j < n; j++)
            cout << a[i][j] << setw(16);
        cout << "\n";
    }
    for (i = 0; i < n - 1; i++) //loop to perform the gauss elimination
        for (k = i + 1; k < n; k++)
        {
            double t = a[k][i] / a[i][i];
            for (j = 0; j < n; j++)
                a[k][j] = a[k][j] - t * a[i][j]; //make the elements below the pivot elements equal to zero or elimnate the variables
        }

    cout << "\n\nThe matrix after gauss-elimination is as follows:\n";
    for (i = 0; i < n; i++) //print the new matrix
    {
        for (j = 0; j < n; j++)
            cout << a[i][j] << setw(16);
        cout << "\n";
    }

    for (i = 0; i < n; i++)
    {
        det = det * a[i][i];
    }
    if (flag % 2 == 0)
    {
        det = det;
    }
    else
    {
        det = -det;
    }
    cout << "\n\n The determinant is: " << det;

    return 0;
}