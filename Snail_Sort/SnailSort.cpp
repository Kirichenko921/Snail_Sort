#include <iostream>

using namespace std;

int main()
{
	const int sizeRow{7};// количество строк 
	const int sizeCollum{ 10}; // количество столбцов
	int arr[sizeRow][sizeCollum]{ { 1, 2, 3,4,5,6,7,8,9,10},{30,31,32,33,34,35,36,37,38,11},
		{29,52,53,54,55,56,57,58,39,12},{28,51,66,67,68,69,70,59,40,13},{27,50,65,64,63,62,61,60,41,14},
		{26,49,48,47,46,45,44,43,42,15},{25,24,23,22,21,20,19,18,17,16} };// массив который будет осортирован в порядке определённом проходом массива "улиткой"
	const int sizeSnail{ sizeRow * sizeCollum };// размер массива в который будут помещаться отсортированные элементы
	int snailArr[sizeSnail]; // массив для вывода отсортированных элементов
	int index{0}; // индекс для отсортированного массива
	int line{ 0 }; // индекс для отслеживания сортируемой строки
	int right{ sizeCollum };// индекс для отслеживания сортируемо строки
	int down{ sizeRow - 1 };
	int left{ sizeCollum };
	int up{ sizeRow - 2 };
	
	
	while(index< sizeSnail)
	{
		
	
		if (index < sizeSnail)
		{
			for (int upperLine{ line }; upperLine < (right + line); ++upperLine)
			{
				snailArr[index]=arr[line][upperLine];
				++index;
			}
			++line;
			right -= 2;
		}
		if (index < sizeSnail)
		{
			int rightColumm{line};
			for (; line<(down + rightColumm); ++line)
			{
				snailArr[index] = arr[line][sizeCollum - rightColumm];
				++index;
			}
			down -= 2;
			--line;
		}
		if (index < sizeSnail)
		{
			for (int lowerLine{ left-2 };lowerLine>=(sizeCollum -left);--lowerLine)
			{
				snailArr[index]=arr[line][lowerLine];
				++index;
			}
			--line;
			left -= 1;
		}
		if (index < sizeSnail)
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
		if (element % 10==0)
		{
			cout << endl;
		}
	}

	cout << endl;
	return 0;
}