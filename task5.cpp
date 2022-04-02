/*
#include <iostream>

int main()
{
    // 10^x = 2^ x*log(2)10

    double x(0), res(0), one(1), ten(10);
    

    std::cout << "enter x" << std::endl;
    std::cin >> x;

    int int_part = (int)x;
    double doub_part = x - int(x);

    

    __asm {

        finit
        mov ecx, int_part
        dec ecx
        fld ten
        l1:
        fmul ten
        loop l1
        fst res

        fld doub_part
        fld ten
        fyl2x   // x*log(2)10     

        f2xm1    // 2^x*log(2)10 -1
        fadd one
        fmul res
        fst res

    }
    std::cout << res;
}*/