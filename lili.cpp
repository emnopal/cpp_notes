#include <iostream>

using namespace std;

struct Range_error : out_of_range {
	int index;
    Range_error(int i) :out_of_range("Range error: " +to_string(i)), index(i) { }
};

struct Exit : runtime_error {
	Exit() : runtime_error("Exit") {}
};

inline void error(const string& s)
{
	throw runtime_error(s);
};

void sorting(int a[], int n)
{
   int i, j, min, temp;
   for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[min] > a[j]) min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main()
{
    
    cout << "Number of case : ";
    int T;
    cin >> T;
    if (T<1 || T> 10) error("please input case between 1 and 10");
    for (int k = 0; k < T; k++)
    {
        int kk = k + 1;
        cout << "===================case #" << kk <<"===================\n";
        cout << "Number of data : ";
        int N;
        cin >> N;
        if (N < 1 || N > 200) error("please input data between 1 and 200");
        cout << "Number of row : ";
        int M;
        cin >> M;
        if (M > N) error("please input row less than data");
        if (M < 1 || M > 200) error("please input row between 1 and 200");
        //kolom
        int x;
        x = N/M + 1;

        int in[N];
        for (int i = 0; i < N; i++)
        {
            cin >> in[i];
            if (in[i] < 0) error("can't input negative number");
            if (in[i] > 1000000000) error("too many number");
        }

        int n = sizeof(in)/sizeof(in[0]);
        /*
        cout << endl << endl << "isi n = "<< n << endl
             << "isi size of(in) = " << sizeof(in) << endl
             << "isi size of(in[0]) = " << sizeof(in[0])
             << endl << endl;
        sort(in, in+n);
        */
        sorting(in, n);

        int list[M][x];
        for (int i = 0; i < M; i++)
        {
            list[i][0] = in[i];
            for (int j = 0; j < x; j++)
            {
                int b = j + 1;
                int pt = i + M*b;
                if (pt >= N)
                {
                    list[i][b] = -1;
                    break;
                }
                list[i][b] = in[pt];
            }
        }
        cout << endl << "Case #" << kk << ":\n";
        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < x; j++)
            {
                if(list[i][j]==-1) break;
                cout<<list[i][j] <<"\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}

/*
https://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
https://www.tutorialspoint.com/cplusplus-program-to-implement-sorted-array
https://www.geeksforgeeks.org/sort-c-stl/
http://www.materidosen.com/2017/06/array-dua-dimensi-c-lengkap-contoh.html
*/
