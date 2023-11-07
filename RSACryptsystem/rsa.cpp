//  rsa.cpp
//  RSACryptsystem
//  Created by Tony Khamphouy on 11/7/23.

#include "rsa.hpp"
int
RSA::fastExponential(int m, int e, int mod){
    if(e == 0){
        return 1;
    }
    else if(expo % 2 == 0){
        int temp = fastExponential(m,e/2,mod);
        return (temp * temp) % mod;
    }
    else{
        return (m * fastExponential(m, e-1, mod)) % mod;
    }
}

void
RSA::print(){
    cout << "p: " << prime1 << endl;
    cout << "q: " << prime2 << endl;
    cout << "n: " << combPrime << endl;
    cout << "phi: " << phi << endl;
    cout << "e: " << expo << endl;
    cout << "Message: " << message << endl;
}
