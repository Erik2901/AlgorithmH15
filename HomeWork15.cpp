#include <iostream>
#define SZ 64

int symbolSum(char carr[]) {
    int sum = 0;
    for (size_t i = 0; i < SZ; i++)
    {
        sum += carr[i];
    }
    return sum;
}

void coins(int* arr,int* arrcount, const int n, int coinsum) {
    int tmp;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] > arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
        }
    }
    for (size_t i = 0; i < n;)
    {
        if (coinsum >= arr[i])
        {
            arrcount[i]++;
            coinsum = coinsum - arr[i];
            i = 0;
        }
        else {
            i++;
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        if (arrcount[i] > 1)
        {
            std::cout << arrcount[i] << " coins of " << arr[i] << std::endl;
        }
        else
        {
            std::cout << arrcount[i] << " coin of " << arr[i] << std::endl;
        }
    }
}

int main()
{
    ////// exercise 1

    char carr[SZ] = "Hello World!";

    std::cout << symbolSum(carr) << std::endl;

    ///////

    /////// exercise 2

    const int n = 5;
    int arr[] = { 50,10,5,2,1 };
    int arrcount[] = { 0,0,0,0,0 };
    int coinsum = 98;

    coins(arr, arrcount, n, coinsum);

    ////////

    system("pause");
    return 0;
}
