#include <iostream>
#include <Matrix.h>
#include <fstream>
using namespace std;

int main()
{
    fstream file;

    file.open("test.txt");
    //did not open correctly
    if(!file.is_open()){
        cout << "unable to open file" << endl;
        exit(1);
    }

    //initialize Matrix of values, assuming each n is two digits
    Matrix<string> matrix(30,30);

    string item;
    int row=0; int col=0;
    while(!file.eof()){
        file >> item;
        for(int index ){

        }

        row++;
    }
    return 0;
}



