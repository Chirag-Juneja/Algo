#include <iostream>
#define LOG(x) std::cout << x << std::endl

void merge(int *array, int begin, int middle, int end)
{
    int n = middle - begin + 1;
    int m = end - middle;
    int *L = new int[n];
    int *R = new int[m];

    for (int i = 0; i < n; i++)
    {
        L[i] = array[i + begin];
    }

    for (int i = 0; i < m; i++)
    {
        R[i] = array[i + middle + 1];
    }

    int i = 0, j = 0, k = begin;

    while (i < n && j < m)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < m)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *array, int begin, int end)
{
    if (begin < end)
    {

        int middle = begin + (end - begin) / 2;
        mergeSort(array, begin, middle);
        mergeSort(array, middle + 1, end);
        merge(array, begin, middle, end);
    }
}

int main(int argc, char *argv[])
{
    int array[] = {9, 7, 4, 3, 5, 68, 1, 6};

    mergeSort(array, 0, sizeof(array) / 4);

    for (int i = 0; i < sizeof(array) / 4; i++)
    {
        LOG(array[i]);
    }

    return 0;
}