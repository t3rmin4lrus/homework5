#include <iostream>

using namespace std;

void print(int* array4, size_t mysize);

// task 1
bool PrintArray(double arr[], double size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return true;
}

int main()
{
	const double mysize = 5;
	double array[] = { 25.2, 56.4, 18.2, 10.5, 14.6 };

	if (PrintArray(array, mysize))
	{
		cout << "Lucke, i am your Jedi array!" << endl;
	}
	return 0;
}

//TASK 2

void DisplayArray(int numbers[], int length)
{
	for (int index = 0; index < length; ++index)
	{
		cout << numbers[index] << " ";
	}
	cout << endl;
}

int task2()
{
	int i;
	const int mysize = 10;
	int array1[10] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };

	DisplayArray(array1, 10);

	for (i = 0; i < 10; i++)
	{
		if (array1[i] == 0)
			array1[i] = 1;
		else if (array1[i] == 1)
			     array1[i] = 0;
	}

	for (i = 0; i < 10; i++)
	{
		cout << array1[i] << " ";
	}
	return 0;
}
	
//TASK 3: Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.

int task3()
{
	const int mysize = 8;
	int array2[mysize] = { 0 };
	int n;

	int const START_VAL = 1;
	int const move = 3;
	for (size_t i = 0; i < mysize; i++)
	{
		array2[i] = START_VAL + i * move;
	}

	for (size_t i = 0; i < mysize; i++)
	{
		cout << array2[i] << " ";
	}
	cout << '\n';

	return 0;
}

// TASK 4*: Написать функцию, которой на вход подаётся одномерный массив и число n(может быть положительным, или отрицательным), при этом метод должен циклически сместить все элементы массива на n позиций.

int function(int number, int base)
{
	int function = number % base;
	if (function < 0)
	{
		function = base + function;
	}
	return function;
}

int task4()
{
	size_t const mysize = 5;
	int shift = 5;

	int array4[mysize] = { 1, 2, 3, 4, 5 };

	int my_array4[mysize];
	for (size_t i = 0; i < mysize; i++) {
		my_array4[i] = array4[i];
	}

	for (size_t i = 0; i < mysize; i++) {
		size_t new_index = function((i + function(shift, mysize)), mysize);
		array4[new_index] = my_array4[i];
	}
	print(array4, mysize);

	return 0;
}

void print(int* array4, size_t mysize)
{
	for (size_t i = 0; i < mysize; i++)
	{
		cout << array4[i] << " ";
	}
	cout << '\n';
}

//TASK 5**: Написать функцию, которой передается не пустой одномерный целочисленный массив, она должна вернуть истину если в массиве есть место, в котором сумма левой и правой части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false, checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти символы в массив не входят.
bool balance(int* array5, size_t ARR_SIZE)
{
	size_t const MAX_BORDER_POS = ARR_SIZE - 1;
	bool is_balanced = false;
	int right_side_sum;
	int left_side_sum;

	for (size_t side = 1; side <= MAX_BORDER_POS; side++) {
		right_side_sum = 0;
		left_side_sum = 0;

		for (size_t i = 0; i < side; i++) {
			right_side_sum += array5[i];
		}
		for (size_t j = side; j < ARR_SIZE; j++) {
			left_side_sum += array5[j];
		}

		if (right_side_sum > left_side_sum) {
			is_balanced = false;
			break;
		}
		if (right_side_sum == left_side_sum) {
			is_balanced = true;
			break;
		}
	}

	return is_balanced;
}
int task5()
{
	size_t const ARR_SIZE = 3;

	
	int array5[ARR_SIZE] = { 3, 1, 2 }; 

	for (size_t i = 0; i < ARR_SIZE; i++) {
		cout << array5[i] << " ";
	}
	cout << '\n';

	bool is_balanced = balance(array5, ARR_SIZE);

	if (is_balanced) 
	{
		cout << "This array has balance! \n";
	}
	else 
	{
		cout << "This array has no balance! \n";
	}
	return 0;
}