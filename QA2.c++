#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

std::vector<double> solve_biquadratic(double a, double b, double c) {
    std::vector<double> solutions;

    if (a == 0) {
        if (b != 0) {
            double x = -c / b;
            if (x >= 0) {
                solutions.push_back(std::sqrt(x));
                solutions.push_back(-std::sqrt(x));
            }
        }
        return solutions;
    }

    double D = b * b - 4 * a * c;

    if (D < 0)
        return solutions; // no real solutions

    double sqrt_D = std::sqrt(D);

    double x1 = (-b + sqrt_D) / (2 * a);
    double x2 = (-b - sqrt_D) / (2 * a);

    if (x1 >= 0) {
        solutions.push_back(std::sqrt(x1));
        solutions.push_back(-std::sqrt(x1));
    }

    if (x2 >= 0 && x1 != x2) {
        solutions.push_back(std::sqrt(x2));
        solutions.push_back(-std::sqrt(x2));
    }

    return solutions;
}

double checker(double param)
{
    while (true)
    {
        try
        {
            if (!(std::cin >> param))
            {
                std::cin.clear();

                while (std::cin.get() != '\n');

                throw "Value is non digit!";
            }
            else
                break;
        }

        catch (const char* exception)
        {
            std::cout << exception << '\n';

            std::cout << "Type new agument value: ";
        }
    }
    return param;
}

int main() {
    double a = 0, b = 0, c = 0;

    std::cout << "Type a, b and c: ";

    a = checker(a);

    b = checker(b);

    c = checker(c);

    std::vector<double> solutions = solve_biquadratic(a, b, c);

    std::sort(solutions.begin(), solutions.end()); // сортировка корней
    auto last = std::unique(solutions.begin(), solutions.end()); // удаление дубликатов
    solutions.erase(last, solutions.end()); // очистка вектора от дубликатов

    int rootCount = solutions.size(); // подсчет уникальных корней

    if (a != 0) {
        if (solutions.size() == 4)
            std::cout << "The equation has four roots\n";
        else if (solutions.size() == 3)
            std::cout << "The equation has three roots, one of them is a double root.\n";
        else if (solutions.size() == 2)
            std::cout << "The equation has two roots, both of them are double roots.\n";
        else if (solutions.size() == 1)
            std::cout << "The equation has one root, it is a quadruple root.\n";
    }
    else if (b != 0) {
        std::cout << "The equation is a quadratic equation and has two root.\n";
    }
    else {
        std::cout << "The equation has no roots.\n";
        exit(0);
    }


    for (double x : solutions)
        std::cout << x << ' ';

    std::cout << '\n';

    return 0;
}
