#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char header[44];
    short data[1000];
    unsigned int* samplerate;

    ifstream musicfile;
    musicfile.open("musicfile.wav", ios::binary | ios::in);
    if (!musicfile) return 777;
    musicfile.read(header, 44);
    for (int i = 0; i < 1000; i++) {
        musicfile.read((char*)data, 2000);
    }
    samplerate = (unsigned int*)(header + 24);

    cout << "samplerate  " << *samplerate << endl;

    musicfile.close();

    ofstream abc("Data.txt");
    float dt = 1.0 / *samplerate;
    for (int i = 0; i < 500; i++) {
        abc << i * dt << " " << data[i * 2] << " " << data[i * 2 + 1] << endl;
    }
    abc.close();

    return 777;
}