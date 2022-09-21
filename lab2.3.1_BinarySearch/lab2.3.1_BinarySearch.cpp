#include <iostream>
#define N 10000
#define M 10000
#include <chrono>

class Timer // подсчет времени
{
private:

    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now())
    {
    }

    void reset()
    {
        m_beg = clock_t::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};


int Bin_Search(int a, int b, int k, int mas[N]) // бинарный поиск
{    
    if (k < mas[0])
        return -1;
    else if (k == mas[0])
        return a;
    else if (k > mas[N - 1])
        return -1;
    a = 0;
    b = N - 1;
    while (a + 1 < b)
    {
        int c;
        c = (a + b) / 2;
        if (k > mas[c])
            a = c;
        else
            b = c;
    }
    if (mas[b] == k)
    {
        std::cout << "Number found cell №" << b << std::endl;
        return b;
    }

    else
    {
        std::cout << "Number not found" << std::endl;
        return -1;
    }

}

int main()
{
    int mas[N];   
    int k;    
    std::cout << "Enter number that you would like to find";
    std::cin >> k;

    for (int i = 0; i < N; i++) // создание массива
        mas[i] = rand() % 11000;

    //сортировка по возрастанию массива
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            if (mas[i] > mas[j])
                std::swap(mas[i], mas[j]);

    /*for (int i = 0; i < N; i++) // вывод массива цикл (проверка)
        std::cout << mas[i] << std::endl;*/

    Timer time;

    /*for(int i = 0 ; i < N ; i ++)//для цикла
    {
        if(mas[i] == a)
            b = i;
    }*/

    Bin_Search(0, N-1, k, mas);
   

    std::cout << std::endl;

    /*std::cout<<"Число найдено, ячейка № "<<b<<std::endl;//для цикла

    if( b == 0 )
        std::cout<<"Число не найдено"<<std::endl;//для цикла*/
    return 0;
}   
