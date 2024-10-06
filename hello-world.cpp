#include <iostream>

int main() {
    unsigned int n, mod;
    unsigned long long m[4]={1,0,0,1}, a[4];
    std::cout << "Hello world! Enter modulo: ";
    std::cin >> mod;
    std::cout << "Enter index of Fibonacci number: ";
    std::cin >> n;
    
    for (int i = 0; i < 32; i++) {
        a[0]=m[0]*m[0]+m[1]*m[2]%mod;
        a[1]=m[0]*m[1]+m[1]*m[3]%mod;
        a[2]=m[2]*m[0]+m[3]*m[2]%mod;
        a[3]=m[2]*m[1]+m[3]*m[3]%mod;
        if (n&(1<<(31-i))) {
            m[0]=a[0]+a[1]%mod;
            m[1]=a[0]%mod;
            m[2]=a[2]+a[3]%mod;
            m[3]=a[2]%mod;
        } else {
            m[0]=a[0]%mod;
            m[1]=a[1]%mod;
            m[2]=a[2]%mod;
            m[3]=a[3]%mod;
        }
    }
    std::cout << "F_" << n << " = " << m[1] << " (mod " << mod << ")" << std::endl;
    return 0;
}