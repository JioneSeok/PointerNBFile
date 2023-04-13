#include <iostream>
#include <fstream>
using namespace std;

void mult(int n, float* a, float* x) {
    for (int i = 0; i < n; i++) {
        a[i] = x[i] * 5;
    }
}
void square(int n, float* b, float* x) {
    for (int i = 0; i < n; i++) {
        b[i] = pow(b[i], 2);
    }
}

int main() {
    float n = 1234;
    float number1[] = { 1000, 2000, 3000, 4000, 5000 };
    float number2[] = { -0.5, 0, 0.5 };

    float data[9];
    data[0] = n;
    mult(5, data + 1, number1);
    square(3, data + 6, number2);


    fstream file;
    file.open("mybin.dat", ios::binary | ios::out);
    file.write((char*)data, sizeof(float) * 9);
    file.close();

}