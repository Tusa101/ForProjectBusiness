// BubbleSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void BubbleSort(int*& arr_for_sort, const int& len)
{
    int temp;
    for (int i=0; i < len; i++)
        for (int j = 0; j < len-1; j++)
        {
            if (arr_for_sort[j]>arr_for_sort[j+1])
            {
                temp = arr_for_sort[j];
                arr_for_sort[j] = arr_for_sort[j + 1];
                arr_for_sort[j + 1] = temp;
            }
        }
}


void InsertSort(int*& arr_for_sort, const int& len)
{
	int cnt = 0;
	for(int i = 1; i < len; i++)
    	{
		for(int j = i; j > 0 && arr_for_sort[j-1]>arr_for_sort[j];j--)
        	{
			cnt++;
			int tmp=arr_for_sort[j-1];
			arr_for_sort[j-1]=arr[j];
			arr_for_sort[j]=tmp;
		}
	}
}

void FillArr(int*& arr_for_sort,const int& len)
{
    cout << "Enter values for your arr:\n";
    for (int i = 0; i < len; i++)
    {
        cout << i + 1 << " element:";
        cin >> arr_for_sort[i];
    }; 
}
void DisplayArr(int*& arr, const int& len)
{
    cout << "Sorted Array: \n";
    for (int i = 0; i < len; i++)
    {
        cout << i + 1 << " element:";
        cout << arr[i] << "\n";
    };
}

int main()
{
    int len;
    cout << "Enter array length: ";
    cin >> len;
    int* arr_for_sort = new int[len];
    FillArr(arr_for_sort, len);
    
    BubbleSort(arr_for_sort, len);
    DisplayArr(arr_for_sort, len);
}

