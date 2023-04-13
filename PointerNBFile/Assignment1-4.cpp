#include <iostream>
#include <fstream>
using namespace std;

void mult5(int* ran) {
	for (int i = 0; i < 5; i++) {
		ran[i] = 1000 * (i + 1) * 5;
		cout << ran[i] << " ";
	}
}

void sq(float* data) {
	float p = -0.5;
	for (int i = 0; i < 3; i++) {
		data[i] = p * p;
		p += 0.5;
		cout << data[i] << " ";
	}
}

void All() {
	char* header;
	header = new char[36];

	ofstream xx("mybin_4.dat", ios::binary | ios::out);
	int* first;
	first = (int*)header;
	*first = 1234;
	int* ran;
	ran = (int*)(header + 4);
	ran = new int[5];
	float* data;
	data = (float*)(header + 24);
	data = new float[3];

	mult5(ran);
	cout << endl;
	sq(data);

	if (!xx) {
		cout << "file not write" << endl;
	}
	xx.write(header, 36 * sizeof(char));
	xx.close();

	ifstream xx("mybin_4.dat", ios::binary | ios::in);
	xx.write(header, 36 * sizeof(char));
	xx.close();

	cout << " <chek numbers>" << endl;
	for (int i = 0; i < 9; i++) {
		cout << i << ": " << data[i] << endl;
	}
}
int main() {
	All();
	return 1;


}