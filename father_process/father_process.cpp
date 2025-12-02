#include <iostream>
#include <conio.h>

using namespace std;

int main(int argc, char *argv[])
{
    int i;

    cout << "ProcessArgs is started!" << endl;

    cout << "My name is: ";

    cout << argv[0] << endl;

    for (i = 1; i < argc; ++i) {
        cout << "Param" << i << " = " << argv[i] << endl;
    }

    cout << "Press any key to finish this process! \n";
    _getch();
    return 0;
}
