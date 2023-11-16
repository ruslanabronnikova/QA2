#include <iostream>
#include <cmath>
#include <vector>

std::vector<double> solve_biquadratic(double a, double b, double c) {
    std::vector<double> solutions;

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

    if (solutions.empty()) 
        std::cout << "The equation has no solutions in real numbers!\n";
    else {
        std::cout << "Answer: ";

        for (double x : solutions) 
            std::cout << x << ' ';

        std::cout << '\n';
    }

    return 0;
}
