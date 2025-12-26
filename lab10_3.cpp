#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

int main() {
    int count = 0;
    float sum = 0;
    float sum_of_square = 0;
    string textline;

    ifstream source("score.txt");

    // วนลูปอ่านข้อมูลทีละบรรทัด
    while (getline(source, textline)) {
        float num = stof(textline); 
        sum += num;
        sum_of_square += num * num;
        count++;
    }

 
    float mean = sum / count;
    
    // คำนวณ SD: sqrt((sum_sq / N) - mean^2)
    float sd = sqrt((sum_of_square / count) - (mean * mean));


    cout << "Number of data = " << count << endl;
    
    cout << setprecision(3);
    cout << "Mean = " << mean << endl;
    cout << "Standard deviation = " << sd << endl;

    source.close();
    return 0;
}
