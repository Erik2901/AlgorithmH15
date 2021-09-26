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

void Coins(int* arr, int* arrcount, int coinsum) {
    int tmp;
    for (size_t i = 0; i < sizeof(arr); i++)
    {
        for (size_t i = 0; i < sizeof(arr) - 1; i++)
        {
            if (arr[i + 1] > arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
        }
    }
    for (size_t i = 0; i < sizeof(arr); i++)
    {
        arrcount[i] = coinsum / arr[i];
        coinsum = coinsum - (arrcount[i] * arr[i]);
    }
    for (size_t i = 0; i < sizeof(arr); i++)
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

    int arr[] = { 50,10,5,2,1 };
    int arrcount[sizeof(arr)] = { 0 };
    int coinsum = 98;

    Coins(arr, arrcount, coinsum);

    ////////

    system("pause");
    return 0;
}
