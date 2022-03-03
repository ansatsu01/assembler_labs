#include <iostream>

int main() {
    int x, res1, res2, res3;
    std::cin >> x;
    if(x==0){throw std::exception ("division by zero!");}

    // (x^5 + 2*(x^2 - 4) + x) / x^3

    __asm{

    mov eax, x
    imul x
    imul x
    imul x
    imul x
    add eax, x
    mov res1, eax  // res1 = x^5 + x

    mov ebx, 2
    mov eax, x
    imul x
    sub eax, 4
    imul ebx

    add res1, eax  // res1 = x^5 + 2*(x^2 - 4) + x

    mov ecx, x
    imul ecx, x
    imul ecx, x  // ecx = x^3

    mov eax, res1
    idiv ecx
    mov res1, eax

    }
    std::cout << res1 << std::endl ;


// (2x-1)(2x+1)(x+3) / 2x

    __asm{
    mov ebx, 2

    mov eax, x
    imul ebx
    sub eax, 1

    mov res2, eax     // res2 = 2x-1

    mov eax, x
    imul ebx
    add eax, 1

    imul res2
    mov res2, eax  //res2 = (2x-1)(2x+1)

    mov ecx, x
    imul ecx, ebx

    mov eax, x
    add eax, 3
    imul res2
    idiv ecx
    mov res2, eax  // res2 = (2x-1)(2x+1)(x+3)


    }
    std:: cout << res2 << std::endl;

    //(4x-1)(4x+1)/4

    __asm{

    mov ebx, 4
    mov eax, x
    imul ebx
    sub eax, 1
    mov res3, eax   // res3 = 4x-1

    mov eax, x
    imul ebx
    add eax, 1
    imul res3
    idiv ebx

    mov res3, eax
    }

    std::cout << res3;

    return 0;
}

