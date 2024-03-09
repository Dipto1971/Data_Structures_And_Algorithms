#include <iostream>
using namespace std;

void fun (int n){
    if (n == 0) return;
    else{
        fun (n/2);
        cout << n << " "; // this line will be executed after the base case is reached because the function is calliing 
    }
}

int main(){
    fun(10);
    return 0;
}