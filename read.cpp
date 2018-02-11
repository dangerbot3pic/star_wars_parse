#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{
    ifstream infile;
    string tmp;
    long temp;

    infile.open("tst1.txt");

    while(true)
    {
        infile >> temp;
        cout<<temp<<endl;
        infile >> tmp;
        cout<<tmp<<endl;
    }
}