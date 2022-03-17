#include <iostream>

int main()
{
	int count(1), arr[60];

	__asm
	{
		mov esi, 0
		mov arr[esi], 0
		add esi, 4
		mov arr[esi], 1
		add esi, 4
		beginning:

		mov eax, 0
			mov ebx, 0
			cdq
			add eax, arr[esi - 8];
		add ebx, arr[esi - 4];

		add eax, ebx
			jo finish

			mov arr[esi], eax
			inc count
			add esi, 4
			jmp beginning
			finish :
	}

	for (int i = 0; i < count; i++)
	{
		std::cout << i << "  " << arr[i] << std::endl;
	}

	return 0;
}
