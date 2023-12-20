#include <iostream>

void program0()
{
    int n, rev, temp;
    std::cout << "Enter a natural number: ";
    std::cin >> n;

    // проверка, что были введены числа
    if (std::cin.fail()) // извлечение не производилось
    {
        std::cout << "\nInput error!!!";
        // сбрасываем биты состояния обратно в goodbit, чтобы мы могли использовать ignore()
        std::cin.clear();
        // очищаем недопустимый ввод из потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    // проверка что число натуральное
    if (n < 1)
    {
        std::cout << "Number isn't natural";
        return;
    }

    while (true) 
    {
        temp = n;
        rev = 0;
        while (temp != 0) 
        {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        if (n == rev) 
        {
            break;
        }
        else 
        {
            n += rev;
        }
    }
    if (n > 0)
    {
        std::cout << "Your polindrom: " << n << std::endl;
    }
    else
    {
        std::cout << "Your polindrom is too big";
    }


}

void program1()
{
    int cur, max1, max2, count;
    std::cout << "Enter sequence of numbers: ";
    std::cin >> cur;

    max1 = cur;
    max2 = INT_MIN;
    count = 1;

    if (cur != 0)
    {
        while (true)
        {
            std::cin >> cur;

            if (cur == 0)
                break;

            count++;

            if (max1 < cur)
            {
                max2 = max1;
                max1 = cur;
            }
            else if (max2 < cur)
            {
                max2 = cur;
            }
        }
    }
    else
        count--;

    // проверка, что были введены числа
    if (std::cin.fail()) // извлечение не производилось
    {
        std::cout << "\nInput error!!!";
        // сбрасываем биты состояния обратно в goodbit, чтобы мы могли использовать ignore()
        std::cin.clear();
        // очищаем недопустимый ввод из потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (count > 1)
    {
        std::cout << "Max numbers: " << max1 << " " << max2 << std::endl;
    }
    else if (count == 1)
    {
        std::cout << "Your sequence has only 1 number: " << max1 << std::endl;
    }
    else
    {
        std::cout << "Your sequence has no numbers: " << std::endl;
    }
}

void program2()
{
    int num;
    std::cout << "Representing an even natural number as the sum of two primes:\nEnter a number: ";
    std::cin >> num;

    // проверка, что были введены числа
    if (std::cin.fail()) // извлечение не производилось
    {
        std::cout << "\nInput error!!!";
        // сбрасываем биты состояния обратно в goodbit, чтобы мы могли использовать ignore()
        std::cin.clear();
        // очищаем недопустимый ввод из потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    // проверка на четность
    if (num % 2 != 0)
    {
        std::cout << "You number isn'n even!";
        return;
    }

    // проверка на натуральность
    if (num < 1)
    {
        std::cout << "You number isn'n natural!";
        return;
    }

    for (int i = 2; i <= num / 2; ++i) 
    {
        bool Primi = true;
        for (int j = 2; j * j <= i; ++j) 
        {
            if (i % j == 0) 
            {
                Primi = false;
                break;
            }
        }

        if (Primi) 
        {
            int k = num - i;
            bool Primk = true;
            for (int j = 2; j * j <= k; ++j) 
            {
                if (k % j == 0) 
                {
                    Primk = false;
                    break;
                }
            }

            if (Primk) 
            {
                std::cout << i << " + " << k << " = " << num << std::endl;
            }
        }
    }
}




int main()
{
    bool answer;

    //program0(); //1
    //program1(); //2
    //program2(); //3


    std::cout << "\nOne more? (1 - yes, 0 - no): ";
    std::cin >> answer;

    if (answer)
    {
        main();
    }
    return 0;
}
