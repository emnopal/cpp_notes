#include <iostream>
using namespace std;
int power(int x,int y) {
int ans;
for (int i=0; i<y; i++)
ans *= x;
return ans;
}
int main(){
cout << power(4,2);
return 0;
}