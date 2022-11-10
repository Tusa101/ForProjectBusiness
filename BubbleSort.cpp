// BubbleSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;




void ShellSort(int*& array, int& len) 
{
    int h = 1;

    while (h <= len / 3) 
    {
        h = h * 3 + 1;
    }

    while (h > 0) {
        for (int outer = h; outer < len; outer++) 
        {
            int tmp = array[outer];
            int inner = outer;

            while (inner > h - 1 && array[inner - h] > tmp) 
            {
                array[inner] = array[inner - h];
                inner -= h;
            }

            array[inner] = tmp;
        }

        h = (h - 1) / 3;
    }
}



int& Partition(int*& arr, int& l, int& r)
{
    int pivot = arr[(l-r)/2];
    int m = l;
    for (int i = l; i < r - 1; i++)
    { 
        if (arr[i] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[m];
            arr[m] = temp;
            m++;
            return m;
        }
    }
}
void HoarSort(int*& arr, int& l, int& r)
{
    if (r - l == 1)
    {
        int m = Partition(arr, l, r);
        HoarSort(arr, l, m);
        HoarSort(arr, m, r);
    }
}

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
    int l = 0;
    int* arr_for_sort = new int[len];
    FillArr(arr_for_sort, len);
    HoarSort(arr_for_sort, l, len);
    //BubbleSort(arr_for_sort, len);
    ShellSort(arr_for_sort, len);
    DisplayArr(arr_for_sort, len);
}

