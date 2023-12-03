#include <iostream>

int sum(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    return total;
}

int main()
{
    setlocale(LC_ALL, "ukr");
    int n;
    do {
        std::cout << "Введіть кількість елементів (мінімум 2): ";
        std::cin >> n;
    } while (n < 2);

    int* arr = new int[n];

    std::cout << "Введіть елементи: (0, 1, or 2): ";

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
        if (arr[i] < 0)
        {
            std::cout << "Ви ввели число, яке менше 0\n";
            continue;
        }
        if (arr[i] > 2)
        {
            std::cout << "Ви ввели число, яке більше 2\n";
            return 0;
        }
    }

    int zero = 0, one = 0, two = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0) zero++;
        else if (arr[i] == 1) one++;
        else if (arr[i] == 2) two++;
    }

    for (int i = 0; i < zero; i++) arr[i] = 0;
    for (int i = zero; i < zero + one; i++) arr[i] = 1;
    for (int i = zero + one; i < n; i++) arr[i] = 2;

    int total = sum(arr, n);

    std::cout << "Переставлений масив є: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    std::cout << "\nСума елементів дорівнює: " << total;

    return 0;
}
