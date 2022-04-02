/*#include <iostream>

int main()
{
    // ln2 =  sum (-1)^k+1 * 1/k

    int check_sign(1), num_of_iter;
    double k(1), res(0), one(1), neg_one (-1);

    std::cout << "enter the num of iterations" << std::endl;
    std::cin >> num_of_iter;

        __asm {

            finit

            mov ecx, num_of_iter
            
            sum:

            fld one
            fdiv k
            fadd res
            fstp res
           
           xor edx, edx
           mov eax, check_sign
           mov ebx, 2
           div ebx
           cmp edx, 0
           jne m1

                fld k
                fsub one 
                fmul neg_one
                fstp k
                inc check_sign
                
                loop sum
                jmp end
            m1:

            fld k
            fadd one
            fmul neg_one
            fstp k
            inc check_sign

            loop sum 
                end:
        }
        
    std::cout << "ln2 : " << res << std::endl;
}
*/