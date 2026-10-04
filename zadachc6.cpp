#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int steps = 5;
    
    
    double V[steps] = {100.0, 120.0, 150.0, 180.0, 200.0};
    double r[steps] = {1.225, 1.112, 1.007, 0.909, 0.819}; 
    
    double S = 35.0;  
    double CL = 0.5; 

  
    cout << "--------------------------------------------------------" << endl;
    cout << setw(5) << "Шаг" << setw(15) << "Скорость"  << setw(15) << "Плотность" << setw(20) << "Подъемная сила L" << endl;
    cout << "--------------------------------------------------------" << endl;

    
    for (int i = 0; i < steps; i++) {
        double L = 0.5 * r[i] * V[i] * V[i] * S * CL;
        
        cout << setw(5) << i + 1 
             << setw(15) << V[i] 
             << setw(15) << r[i] 
             << setw(20) << L << endl;
    }

    return 0;
}
