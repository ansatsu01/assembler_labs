#include <iostream>
// 27-15  12-7

int main()
{
    int arr[5]{ 5, 3, 4, 1 ,2 };
    int res(0);

    __asm {


        mov ecx, 5

        sort:
        mov esi, 0
            dec ecx
            mov edx, ecx
            sub edx, 1

            sort_loop :

            mov eax, arr[esi * 4]

            shr eax, 7
            mov edx, eax
            shl edx, 26
            shr edx, 26
            mov res, edx
            xor edx, edx
            mov edx, eax
            shr edx, 8
            shl edx, 6
            mov eax, res
            or eax, edx
            mov arr[esi * 4], eax

            mov eax, arr[(ESI * 4) + 4]

            shr eax, 7
            mov edx, eax
            shl edx, 26
            shr edx, 26
            mov res, edx
            xor edx, edx
            mov edx, eax
            shr edx, 8
            shl edx, 6
            mov eax, res
            or eax, edx

            mov ebx, eax

            cmp EAX, EBX
            ja change
            mov arr[(esi * 4) + 4], ebx
            mov arr[esi * 4], eax


            change :
        mov arr[esi * 4], ebx
            mov arr[(esi * 4) + 4], eax

            cmp EDX, 0
            je end

            cmp esi, edx
            je sort
            inc esi
            jmp sort_loop

            end :

    }

    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << std::endl;
    }
}