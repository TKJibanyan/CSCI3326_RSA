
//  rsa.hpp
//  RSACryptsystem
//  Created by Tony Khamphouy on 11/7/23.
#ifndef rsa_hpp
#define rsa_hpp

#include <stdio.h>
#include "tools.hpp"

class RSA{
private:
    int phi;
    int prime1;
    int prime2;
    int combPrime;
    int message;
    int expo;
public:
    RSA(){}
    RSA(int p, int q, int e, int M): prime1(p), prime2(q), message(M), expo(e){
        combPrime = prime1 * prime2;
        phi = (prime1 - 1) * (prime2 - 1);}
    ~RSA()=default;
    int fastExponential(int m, int e, int mod);
    void print();
};


#endif /* rsa_hpp */
