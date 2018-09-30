#include <iostream>
using  namespace std;

int main()
{
	int size, i, j, temp;
	int arr[] = { 17,19,19,2,3,4,5,1,2,43 };
	size = sizeof(arr) / sizeof(int);			//to find size of int array find the amount of bytes in array using sizeof(arr) then divid by sizeof(int) to get amount of elements

	for (i = 1; i < size; i++) {
		temp = arr[i];
		j = i - 1;
		while ((temp < arr[j]) && (j >= 0))
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}

	cout << "Array after sorting : \n";
	for (i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
