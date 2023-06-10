/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int a[5][2];
    int it=0,s=0,limit=5*2;
    cout<<"enter a 2d array :"<<endl;
    for(int i=0; i<limit; i++)
    {
        if(s<2)
        {
            cin>>a[it][s];
            s++;
        }
        else
        {
            s=0;
            it++;
            i--;
        }
    }
    

    return 0;
}

