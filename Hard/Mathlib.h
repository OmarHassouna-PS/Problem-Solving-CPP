#pragma once

#include <iostream>
#include <math.h>
#include <time.h>

const float PI = 3.14159;

namespace Math {
    
    float CircleAreaByCircumference(float L) {
    return pow(L, 2) / (4 * PI);
    }

    float CircleAreaByDiameter(float D) {
    return (PI * pow(D, 2)) / 4;
    }

    float CircleAreaByRadius(float R) {
    return PI * pow(R, 2);
    }

    float CircleAreaByATriangle(float A, float B, float C) {
    int P = (A + B + C) / 2;
    return PI * pow(((A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)))),2);
    }

    float CircleAreaByITriangle(float A, float B) {
    return PI * (pow(B, 2) / 4) * ((2 * A - B) / (2 * A + B));
    }

    int Factorial(int N) {
    if (N == 1)
        return 1;

    return N * Factorial(N - 1);
    }

    string OddOrEven(int Number) {
    if (Number % 2 == 0) {
        return "Even";
    }
    else {
        return "Odd";
    }
    }

    bool CheckPrime(int Number) {
    int M = round(Number / 2);
    for (size_t i = 2; i <= M; i++) {
        
        if (Number % i == 0)
            return false;
    }
    return true;
    }

    float calculationRectangleArea(float a, float b) {
    return a * sqrt(pow(b,2) - pow(a,2));
    }

    
    float TriangleArea(float a, float h) {
    return h * (a / 2);
    }

    int RandomNumber(int From, int To) {
    
    return rand()% (To - From + 1) + From;
    }

    void SwapInt (int& A, int& B ) {
    int Tmp = A;
    A = B;
    B = Tmp;
    }

    int FrequencyNumber (int Number, int Frequency) {
    int Remainder = 0, Count = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        if (Frequency == Remainder)
            Count++;
    }
    return Count;
    }

    int ReverseNumber (int Number) {
    int Remainder = 0, Number2 = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        Number2 = Number2 * 10 + Remainder;
    }
    return Number2;
    }

    bool PerfectNumber (int Number) {
    int Sum = 0;
    for (size_t i = 1; i <= (Number / 2); i++)
    {
        if (Number % i == 0)
            Sum += i;      
    }
    return Number == Sum;
    }

    bool PrimeNumber(int Number) {

    int M = round(Number / 2);

    for (size_t i = 2; i <= M; i++) {
        
        if (Number % i == 0)
            return false;
    }
    return true;
    }

    void CreatArray (int array[], int size, int From, int To) {
    for (size_t i = 0; i < size; i++)
    {
        array[i] = RandomNumber(From, To);
    }
    }

    int SumOfDigits (int Number) {
    int Sum = 0, Remainder = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        Sum += Remainder;
    }
    return Sum;
    }

}
