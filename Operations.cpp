#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
int main()
{
string filename = "RAtttt.txt";
ofstream fout(filename.c_str()); 
if (!fout)
{
cerr << "error: open file for output failed!" << endl;
abort(); 
}
fout << "apple" << endl;
fout << "orange" << endl;
fout << "banana" << endl;
fout << "chikoo" << endl;
fout << "kiwi" << endl;
fout.close();
ifstream fin(filename.c_str()); 
if (!fin)
{
cerr << "error: open file for input failed!" << endl;
abort();
}
char ch;
while (fin.get(ch))
{ 
cout << ch;
}


fin.close();
return 0;
}
