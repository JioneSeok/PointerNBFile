#include <iostream>
#include <fstream>
using namespace std;

int mult(int* n) {
	int a = *n * 5;
	return a;
}

float square(float* f) {
	float b = pow(*f, 2);
	return b;
}

int main() {
	int n = 1234;
	int number1[] = { 1000, 2000, 3000, 4000, 5000 };
	float number2[] = { -0.5, 0, 0.5 };

	int data1[5];
	float data2[3];

	for (int i = 0; i < 5; i++) {
		data1[i] = mult(&number1[i]);
	}

	for (int i = 0; i < 3; i++) {
		data2[i] = square(&number2[i]);
	}

	fstream file;
	file.open("mybin.dat", ios::binary | ios::out);

	if (!file) {
		cout << "file not write" << endl;
		return 99;
	}

	file.write((char*)&n, 4);
	file.write((char*)data1, sizeof(int) * 5);
	file.write((char*)data2, sizeof(float) * 3);
	file.close();


}