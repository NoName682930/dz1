#include <iostream> 

using namespace std; 

int main() {
    double S, V, r, CL, L;
    cout << "Введите площадь крыла S (м^2): ";
    cin >> S;
    cout << "Введите скорость полета V (м/с): ";
    cin >> V;
    cout << "Введите плотность воздуха r (кг/м^3): ";
    cin >> r;    
    cout << "Введите коэффициент подъемной силы CL: ";
    cin >> CL;
    L = 0.5 * r * V * V * S * CL;  
    cout.precision(7);  
    cout << "Подъемная сила L = " << L << " Ньютонов." << endl;

    return 0; 
}
