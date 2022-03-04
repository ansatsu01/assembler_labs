#include <iostream>

int main()
{
    __int16 a3, a2, a1;
    __int16 b3, b2, b1;
    __int16 c3(0), c2(0), c1(0);
    std::cin >> a3 >> a2 >> a1;
    std::cin >> b3 >> b2 >> b1;

    __asm
    {
    mov AX, a1
    add AX, b1
    mov c1, AX

    mov AX, a2
    adc AX, b2
    mov c2, AX

    mov AX, a3
    adc AX, b3
    mov c3, AX
    }


    std::cout.unsetf(std::ios::dec);
    std::cout.setf(std::ios::hex);

    std::cout << c3 << " " << c2 << " " << c1 << std::endl;

    std::cout.unsetf(std::ios::hex);
    std::cout.setf(std::ios::dec);

    std::cout << c3 << " " << c2 << " " << c1 << std::endl;


    std::cout << (c3 << 32 | c2 << 16 | c1);

    return  0;
    }
