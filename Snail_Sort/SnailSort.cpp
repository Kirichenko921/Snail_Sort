#include <iostream>

using namespace std;

int main()
{
	const int sizeRow{6};// количество строк
	const int sizeCollum{ 6 }; // количество столбцов
	int arr[sizeRow][sizeCollum]{ { 1, 2, 3,4,5,6},{20,21,22,23,24,7},
		{19,32,33,34,25,8},{18,31,36,35,26,9},{17,30,29,28,27,10},
		{16,15,14,13,12,11} };// массив который будет осортирован в порядке определённом проходом массива "улиткой"
	const int sizeSnail{ sizeRow * sizeCollum };// размер массива в который будут помещаться отсортированные элементы*/
	/*const int sizeRow{7};// количество строк
	const int sizeCollum{ 6}; // количество столбцов
	int arr[sizeRow][sizeCollum]{ { 1, 2, 3,4,5,6},{22,23,24,25,26,7},
		{21,36,37,38,27,8},{20,35,42,39,28,9},{19,34,41,40,29,10},
		{18,33,32,31,30,11},{17,16,15,14,13,12,} };// массив который будет осортирован в порядке определённом проходом массива "улиткой"
	const int sizeSnail{ sizeRow * sizeCollum };// размер массива в который будут помещаться отсортированные элементы*/
	/*const int sizeRow{7};// количество строк 
	const int sizeCollum{ 10}; // количество столбцов
	int arr[sizeRow][sizeCollum]{ { 1, 2, 3,4,5,6,7,8,9,10},{30,31,32,33,34,35,36,37,38,11},
		{29,52,53,54,55,56,57,58,39,12},{28,51,66,67,68,69,70,59,40,13},{27,50,65,64,63,62,61,60,41,14},
		{26,49,48,47,46,45,44,43,42,15},{25,24,23,22,21,20,19,18,17,16} };// массив который будет осортирован в порядке определённом проходом массива "улиткой"
	const int sizeSnail{ sizeRow * sizeCollum };// размер массива в который будут помещаться отсортированные элементы*/
	int snailArr[sizeSnail]; // массив для вывода отсортированных элементов
	int index{0}; // индекс для отсортированного массива
	int rowMin{ 0 }; // индекс для отслеживания верхней строки
	int rowMax{ sizeRow - 1 };// индекс для отслеживания нижней строки
	int collumMin{ 0 };        // индекс для отслеживания левого столбца
	int collumMax{ sizeCollum - 1 }; // индекс для отслеживания правого столбца
	
	while(index< sizeSnail) // если не прошли весь масиив будем продолжать сортировать
	{
		
	
		if (index < sizeSnail) //  проходим верхний ряд слева направо
		{
			for (int upperLine{collumMin}; upperLine <= collumMax; ++upperLine)
			{
				snailArr[index]=arr[rowMin][upperLine];
				++index;
			}
			++rowMin; // верхний ряд обработан
		}
		if (index < sizeSnail) // проходим по крайнему правому столбцу сверху вниз
		{
			
			for (int rightColumm{ rowMin }; rightColumm <=rowMax; ++rightColumm)
			{
				snailArr[index] = arr[rightColumm][collumMax];
				++index;
			}
			--collumMax; // крайний правый столбец обработан
		}
		if (index < sizeSnail)// проходим нижний ряд справа налево
		{
			for (int lowerLine{ collumMax };lowerLine>=(collumMin);--lowerLine)
			{
				snailArr[index]=arr[rowMax][lowerLine];
				++index;
			}
			--rowMax; // нижний ряд обработан
		}
		if (index < sizeSnail)
		{
			
			for (int leftColumm{ rowMax }; leftColumm >=rowMin;--leftColumm) //  проходим левый столбец снизу вверх
			{
				snailArr[index] = arr[leftColumm][collumMin];
				++index;
			}
			++collumMin;// крайний левый столбец обработан
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