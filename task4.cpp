
#include <iostream>

int main()
{
	int numerator, denominator, gcd;

	std::cin >> numerator;
	std::cin >> denominator;

	std::cout << "you've entered : " << numerator << " / " << denominator << std::endl;

	__asm {

		mov ecx, denominator
	

		start :
		mov ebx, ecx
			xor edx, edx

			mov eax, numerator
			cmp eax, 0
			jge above_zero

			mov edx, -1
			imul edx
			xor edx, edx
			jmp above_zero
			above_zero:
			idiv ebx
			cmp edx, 0
			je check_den

			dec ecx
			jmp start

			check_den :
		xor edx, edx
			mov eax, denominator
			idiv ebx
			cmp edx, 0
			je reduction

			dec ecx
			jmp start
			reduction :

		mov gcd, ebx

			mov eax, numerator
			mov ebx, 1
			imul ebx; edx:eax
			idiv gcd; numerator / gcd
			mov numerator, eax; numerator_ = numerator / gcd

			mov eax, denominator
			imul ebx; edx:eax; edx:eax
			idiv gcd; denominator / gcd
			mov denominator, eax

	}

	std::cout << "gcd : " << gcd << std::endl;
	std::cout << "result : " << numerator << " / " << denominator << std::endl;

}
