#include <iostream>

using namespace std;

int main()
{
	const int size{3};
	int arr[size][size]{ { 1, 2, 3 },{8, 9, 4},{7, 6, 5} };// массив который будет осортирован в порядке прохода массива "улиткой"

	int snailArr[size*size]; // массив для вывода отсортированных элементов
	int index{0};
	int line{ 0 };
	int right{ size };
	int down{ size - 1 };
	int left{ size - 1 };
	int up{ size - 2 };
	while(index<(size*size))
	{
		if (right > 0)
		{
			for (int upperLine{ line }; upperLine < (right + line); ++upperLine)
			{
				snailArr[index]=arr[line][upperLine];
				++index;
			}
			++line;
			right -= 2;
		}
		if (down > 0)
		{
			int rightColumm{line};
			for (; line<(down + rightColumm); ++line)
			{
				snailArr[index] = arr[line][size - rightColumm];
				++index;
			}
			down -= 2;
			--line;
		}
		if (left > 0)
		{
			for (int lowerLine{ line - 1 };lowerLine>=(line-left);--lowerLine)
			{
				snailArr[index]=arr[line][lowerLine];
				++index;
			}
			--line;
			left -= 2;
		}
		if (up > 0)
		{
			int leftColumm{ line };
			for (;line>(leftColumm-up);--line)
			{
				snailArr[index] = arr[line][leftColumm - up];
				++index;
			}
			up -= 2;
			++line;
		}
	}

	for (const auto& element : snailArr)
	{
		cout << " " << element << " ";
	}

	cout << endl;
	return 0;
}