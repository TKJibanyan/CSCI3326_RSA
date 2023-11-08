//  main.cpp
//  RSACryptsystem
//  Created by Tony Khamphouy on 11/6/23.

#include "tools.hpp"
#include "rsa.hpp"

int main(int argc, const char * argv[]) {
    banner();
    int p = 17;
    int q = 29;
    int n = p * q;
    int phi = (p-1)*(q-1);
    int e = 5;
    int message = 19;
    RSA alice = RSA(p, q, e, message); //create an alice object
    
    //brute force
    int d = -1;
    for(int i=2; i < n; ++i){
        if((e * i) % phi == 1){
            d = i;
            break;
        }
    }
    
    int C = alice.fastExponential(message, e, n); //encrypt the message
    int M_Prime = alice.fastExponential(C, d, n); //decrypt the message
    alice.print(); //prints out
    cout << "d: " << d << endl;
    cout << "C: " << C << endl;
    cout << "M_Prime: " << M_Prime << endl;
    bye();
    return 0;
}
