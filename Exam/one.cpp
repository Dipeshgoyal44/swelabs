#include <iostream>

using namespace std;

int countNegative(int array[], int array_size);
int countNegative(float array[], int array_size);

int main()
{
    int arrayint[5] = {5,8,1,2,4};
    float arrayfloat[5] = {5.1,7.3,2.2,1.1,2.8};
    int result1 = countNegative(arrayint,5);
    int result2 = countNegative(arrayfloat,5);
    if(result1==0){
        cout << "No Negative Integers \n";
    }else{
        cout << "Integer: " << result1 << " \n";
    }
    if(result2==0){
        cout << "No Negative float values \n";
    }else{
        cout << "Float: " << result2 << " \n";
    }
    
    return 0;
}

int countNegative(int array[], int array_size)
{
    int count =0;
    for(int i = 0; i < array_size; i++){
        if(array[i] < 0){
            count++;
        }
    }
    return count;
}

int countNegative(float array[], int array_size)
{
    int count =0;
    for(int i = 0; i < array_size; i++){
        if(array[i] < 0){
            count++;
        }
    }
    return count;
}