#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char header[44];
	short data[1000];
	unsigned int* samplerate;

	ifstream aaa;
	aaa.open("BeatlesLetItBewav_30s.wav", ios::binary | ios::in);
	if (!aaa) return 123;
	
	aaa.read(header, 44);

	for (int i = 0; i < 1000; i++) {
		aaa.read((char*)data, 2000);
	}

	samplerate = (unsigned int*)(header + 24);

	cout << "samplerate  " << *samplerate << endl;

	aaa.close();

	ofstream bbb("Data.txt");
	float dt = 1. / *samplerate;
	for (int j = 0; j < 500; j++) {
		bbb << j * dt << " " << data[j * 2] << " " << data[j * 2 + 1] << endl;
	}
	bbb.close();

	return 0;
}