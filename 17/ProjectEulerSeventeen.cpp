#include<iostream>
#include<string>
#include<stdlib.h>
#include <stdexcept>

using namespace std;

int countLengthInRange(int a,int b);
int countInt(int n[]);
int getLengthOnes(int n);
int getLengthTeens(int n4);
int getLengthTens(int n3);

int main()
{

}

//counts number of characters when typing out all number between a and b, inclusive
//length of a[] and b[] must be 4
int countLengthInRange(int a[],int b[])
{
    //TODO: error check for inputs
    int acc=0,
    for(int i=0;a!=b;i++)
    {
        cout<<i%10;
        cout<<i%100;
    }
}


//size of n[] must be 4
int countInt(int n[])
{
    int length=0;
    for(int i=0;i<4;i++)
    {
        if(n[i]!=0)
        {
            if(i==0) length += getLengthOnes(n[i]) + 8; //"n" thousand
            else if(i==1)
            {
                length += getLengthOnes(n[i]) + 7; // "n" hundred
                if(n[2]!=0 || n[3]!=0) length+= 3;//"and"
            }
            else if(i==2)
            {
                if(n[3]!=0)
                {
                    if(n[2]==1) return length + getLengthTeens(n[3]); //teens
                    else return length + getLengthTens(n[2]) + getLengthOnes(n[3]); //"twenty one"
                }
                else return length + getLengthTens(n[2]); //aka "twenty"
            }
        }

    }

}
int getLengthOnes(int n4)
{
    if(n4<10 && n4 > 0)
    {
        if(n4==4 || n4==5 || n4==9)return 4;
        else if(n4==1 || n4==2 || n4==6) return 3;
        else return 5;
    }
    else if(n4==0)return 0;
    else{
        cout<<"input "; cout<<n4; cout<<" not accepted in getLengthOnes()"<<endl;
        exit(1);
    }
}
int getLengthTeens(int n4) //where n4 is the second digit of teens
{
   if(n4 > 1 && n4 < 10)
   {
       if(n4==1 || n4==2) return 6;
       else if(n4 == 5 || n4 == 6) return 7;
       else if(n4==7) return 9;
       else return 8;
   }
   else{
        cout<<"input"; cout<<n4; cout<<"not accepted in getLengthTeens()"<<endl;
        exit(1);
   }
}
int getLengthTens(int n3)
{
    if(n3 > 0 && n3 < 10)
    {
        if(n3==1) return 3;
        else if(n3==7)return 7;
        else if(n3==5 || n3==6 || n3==4)return 5;
        else return 6;
    }
       else{
        cout<<"input"; cout<<n3; cout<<"not accepted in getLengthTens()"<<endl;
        exit(1);
   }
}













