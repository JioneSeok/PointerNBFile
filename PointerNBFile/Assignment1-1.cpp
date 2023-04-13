#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int num = 1234;
	int number1[] = { 1000, 2000, 3000, 4000, 5000 };
	float number2[] = { -0.5, 0, 0.5 };

	int data1[5];
	float data2[3];

	for (int i = 0; i < 5; i++) {
		data1[i] = number1[i] * i;
	}

	for (int i = 0; i < 3; i++) {
		data2[i] = pow(number2[i], 2);
	}

	fstream file;
	file.open("mybin.dat", ios::binary | ios::out);

	if (!file) {
		cout << "file not write" << endl;
		return 99;
	}

	file.write((char*)&num, 4);
	file.write((char*)data1, sizeof(int) * 5);
	file.write((char*)data2, sizeof(float) * 3);
	file.close();

	file.open("mybin.dat", ios::binary | ios::in);

	if (!file) {
		cout << "file not write" << endl;
		return 99;
	}

	file.read((char*)&num, 4);
	file.read((char*)data1, sizeof(int) * 5);
	file.read((char*)data2, sizeof(float) * 3);
	file.close();



}