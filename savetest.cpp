#include <iostream>
using namespace std;
int main()
{
    int array[3][3];
    int list[16]={2,2,2,3,3,2,4,5,6,7,5,4,3,3,9,0};
    int count=0;
for(int i=0; i<3; i++)//since it is a 4 by 4 matrix so 4 rows...
  for(int j=0; j<3; j++)//
  {
      array[i][j]=list[count];//
      count++;
      cout<<array[i][j]<<" ";
      cout << endl;
  }


return 0;

}