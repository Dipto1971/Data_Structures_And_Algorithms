#include <iostream>
using namespace std;

void fun (int n){
    if(n == 0) return;
    cout << n << " ";
    fun(n-1);
    cout << n << " ";
    // functions will wait for the inner function to complete before executing the next line AND the execution will proceed till the base case is reached
}

int main(){
    fun(3); 
    // output: 3 2 1 1 2 3
    return 0;
}