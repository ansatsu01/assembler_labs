#include <iostream>

int main()
{
	// ax^2 + b/x+11 + c = 0

	double trash, a, b, c, x, res(0), zero(0), eleven(11), two(2), dividor, left(-10), right(0),
		middle(0), m_res1(0), m_res2(0), root(0), diff;
	int find_root(0);
	std::cout << "ax^2 + b/x+11 + c" << std::endl;
	std::cout << "enter a,b,c :" << std::endl;
	std::cin >> a >> b >> c;

	__asm {

		finit

		calculating :

		fld left
			fst x
			fmul left
			fmul a
			fadd c
			fstp m_res1

			fld left
			fadd eleven
			fstp dividor

			fld b
			fdiv dividor
			fadd m_res1
			fst m_res1

			fcom zero
			fstsw ax
			sahf
			je it_is_root

			fstp m_res1

			fld right
			fst x
			fmul right
			fmul a
			fadd c
			fstp m_res2

			fld right
			fadd eleven
			fstp dividor

			fld b
			fdiv dividor
			fadd m_res2

			fcom zero
			fstsw ax
			sahf
			je it_is_root

			fstp m_res2

			fld m_res1
			fmul m_res2

			fcom zero
			fstsw ax
			sahf
			ja no_roots


			fld right
			fadd left
			fdiv two
			fst middle
			fst x

			fmul middle
			fmul a
			fadd c
			fstp res

			fld middle
			fadd eleven
			fstp dividor

			fld b
			fdiv dividor
			fadd res

			fcom zero
			fstsw ax
			sahf
			je it_is_root

			fcom zero
			fstsw ax
			sahf
			ja change_left

			fcom zero
			fstsw ax
			sahf
			jb change_right


			change_right :

		fld middle
			fstp right
			jmp calculating

			change_left :

		fld middle
			fstp left
			jmp calculating

			jmp end_

			it_is_root :

		fld x
			fstp root

			inc find_root
			jmp end_


			no_roots :
		fld zero
			fstp root

			end_ :


	}

	if (find_root == 0) {
		std::cout << "no roots bro" << std::endl;
	}
	else {
		std::cout << "root : " << root << std::endl;
	}
}