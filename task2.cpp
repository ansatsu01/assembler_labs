/*
#include <iostream>

int main()
{
    //  sum 1/2k-1 = pi^2 / 8

   
    double  k, res(0), dividor, one(1), eight(8);
    std::cout << "enter the num of iterations" << std::endl;
    std::cin >> k;
    int k_for_loop = (int)k ;

        __asm {

            finit

            mov ecx, k_for_loop
            
            sum:

            fld k
            fadd k
            fsub one
            fstp dividor
            fld one
            fdiv dividor
            fdiv dividor
            fadd res
            fstp res

            fld k
            fsub one
            fstp k
            loop sum 

             fld res
             fmul eight
             fsqrt
             fstp res
        }
        
    std::cout << "pi : " << res << std::endl;
}*/