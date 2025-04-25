#include<iostream>
using namespace std;

class EquilateralTriangle{
    float a,circumference, area;

public:
    void setA(float length);
    friend class Homework;
};

void EquilateralTriangle::setA(float length){
    a=length;
    circumference=a*3;
    area=(1.73*a*a)/4;
}

class Homework{
public:
    void PrintResult(EquilateralTriangle et){
    cout<<"Circumference is: "<<et.circumference<<endl;
    cout<<"Area is: "<<et.area<<endl;
    }
};

int main()
{
    
}
