#include "Homework2.hpp"

Homework2::Homework2()
{
}

int Homework2::calculateGCD(int number1, int number2)
{
    if (number1 == 0) {return number2;}
    else if (number2 == 0) {return number1;}
    else if (number1 == number2) {return number1;}

    if (number2 > number1){
        int temp;
        temp = number1;
        number1 = number2;
        number2 = temp;
    }

    while (number2 != 0)
    {
        int new_number1 = number2;
        number2 = number1 - int(number1/number2) * number2;
        number1 = new_number1;
    }
    
    
    return number1;
}

Homework2::~Homework2()
{
}