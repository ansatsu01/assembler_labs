#include <iostream>

int main()
{
    int a;
    std::cout << "enter the number" << std::endl;
    std::cin >> a;

    __asm {

        mov ecx, 11
        mov eax, a
        m1 :
        mul a
            loop m1

            add eax, a
            mov ebx, eax

            mov ecx, 7
            mov eax, a
            m2 :
        mul a
            loop m2

            add eax, ebx
            mov a, eax

    }

    std::cout << "res: " << a << std::endl;

}  