
#include <iostream>

int main()
{
	// ax + by = res
	int a, b, res, x, y(0), count(0);
	int X[30], Y[30];
	std::cin >> a >> b >> res;
	std::cout << "task: " << a << "x" << " + " << b << "y" << " = " << res << std::endl;

	__asm {

		mov esi, 0
		start:
		xor edx, edx
			mov ebx, y
			imul ebx, b
			mov eax, res
			cmp eax, ebx
			jb finish
			sub eax, ebx
			div a
			cmp edx, 0
			je m1
			inc y
			jmp start
			m1 :
		mov X[esi], eax
			mov ebx, y
			mov Y[esi], ebx
			add esi, 4
			inc y
			inc count
			jmp start

			finish :
	}


	std::cout << "num of decisions: " << count << std::endl;
	for (int i = 0; i < count; i++) {

		std::cout << X[i] << "    " << Y[i] << std::endl;
	}

	return 0;
}