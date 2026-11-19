//
// Created by tomas on 28-02-2025.
//

#include <chrono>

bool isBissexto(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int dias_do_mes(int m, int y)
{
    if (m == 2) return isBissexto(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

void advance(int delta, int& d, int& m, int& y)
{
    d += delta;

    while (d > dias_do_mes(m, y))
    {
        d -= dias_do_mes(m, y);
        m++;
        if (m > 12)
        {
            m = 1;
            y++;
        }
    }
}

int main()
{
    return 0;
}