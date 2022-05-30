
// Program with memory leak
#include <iostream>
using namespace std;

// function with memory leak
void func_to_show_mem_leak(){
    int *ptr = new int(1000000);
    return;
}

int main(){
    func_to_show_mem_leak();
    return 0;
}
