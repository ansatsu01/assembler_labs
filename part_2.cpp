#include <iostream>

int main()
{

    int num, sum(0);
    std::cin >> num;
    if (num == 0 || num < 0) {
        throw std::runtime_error("number isn't natural");
    }
    __asm {

    m1:
    mov BX, 10
    mov EDX, 0
    mov EAX, num
    div BX

    add sum, EDX
    mov num, EAX
    cmp num, 0
    jne m1

    }
    std::cout << "sum: " << sum << std::endl;
}

