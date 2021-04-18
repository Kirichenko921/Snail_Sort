#include <iostream>

using namespace std;

int main()
{
	const int sizeRow{6};// ���������� �����
	const int sizeCollum{ 6 }; // ���������� ��������
	int arr[sizeRow][sizeCollum]{ { 1, 2, 3,4,5,6},{20,21,22,23,24,7},
		{19,32,33,34,25,8},{18,31,36,35,26,9},{17,30,29,28,27,10},
		{16,15,14,13,12,11} };// ������ ������� ����� ����������� � ������� ����������� �������� ������� "�������"
	const int sizeSnail{ sizeRow * sizeCollum };// ������ ������� � ������� ����� ���������� ��������������� ��������*/
	/*const int sizeRow{7};// ���������� �����
	const int sizeCollum{ 6}; // ���������� ��������
	int arr[sizeRow][sizeCollum]{ { 1, 2, 3,4,5,6},{22,23,24,25,26,7},
		{21,36,37,38,27,8},{20,35,42,39,28,9},{19,34,41,40,29,10},
		{18,33,32,31,30,11},{17,16,15,14,13,12,} };// ������ ������� ����� ����������� � ������� ����������� �������� ������� "�������"
	const int sizeSnail{ sizeRow * sizeCollum };// ������ ������� � ������� ����� ���������� ��������������� ��������*/
	/*const int sizeRow{7};// ���������� ����� 
	const int sizeCollum{ 10}; // ���������� ��������
	int arr[sizeRow][sizeCollum]{ { 1, 2, 3,4,5,6,7,8,9,10},{30,31,32,33,34,35,36,37,38,11},
		{29,52,53,54,55,56,57,58,39,12},{28,51,66,67,68,69,70,59,40,13},{27,50,65,64,63,62,61,60,41,14},
		{26,49,48,47,46,45,44,43,42,15},{25,24,23,22,21,20,19,18,17,16} };// ������ ������� ����� ����������� � ������� ����������� �������� ������� "�������"
	const int sizeSnail{ sizeRow * sizeCollum };// ������ ������� � ������� ����� ���������� ��������������� ��������*/
	int snailArr[sizeSnail]; // ������ ��� ������ ��������������� ���������
	int index{0}; // ������ ��� ���������������� �������
	int rowMin{ 0 }; // ������ ��� ������������ ������� ������
	int rowMax{ sizeRow - 1 };// ������ ��� ������������ ������ ������
	int collumMin{ 0 };        // ������ ��� ������������ ������ �������
	int collumMax{ sizeCollum - 1 }; // ������ ��� ������������ ������� �������
	
	while(index< sizeSnail) // ���� �� ������ ���� ������ ����� ���������� �����������
	{
		
	
		if (index < sizeSnail) //  �������� ������� ��� ����� �������
		{
			for (int upperLine{collumMin}; upperLine <= collumMax; ++upperLine)
			{
				snailArr[index]=arr[rowMin][upperLine];
				++index;
			}
			++rowMin; // ������� ��� ���������
		}
		if (index < sizeSnail) // �������� �� �������� ������� ������� ������ ����
		{
			
			for (int rightColumm{ rowMin }; rightColumm <=rowMax; ++rightColumm)
			{
				snailArr[index] = arr[rightColumm][collumMax];
				++index;
			}
			--collumMax; // ������� ������ ������� ���������
		}
		if (index < sizeSnail)// �������� ������ ��� ������ ������
		{
			for (int lowerLine{ collumMax };lowerLine>=(collumMin);--lowerLine)
			{
				snailArr[index]=arr[rowMax][lowerLine];
				++index;
			}
			--rowMax; // ������ ��� ���������
		}
		if (index < sizeSnail)
		{
			
			for (int leftColumm{ rowMax }; leftColumm >=rowMin;--leftColumm) //  �������� ����� ������� ����� �����
			{
				snailArr[index] = arr[leftColumm][collumMin];
				++index;
			}
			++collumMin;// ������� ����� ������� ���������
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