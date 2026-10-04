#include <iostream>

using namespace std;

double calculateDrag(double r, double V, double S, double CD) {
    return 0.5 * r * V * V * S * CD;
}

int main() {
    
    double S, V, r, CD;
  
    cout << "Введите площадь крыла S (м^2): " << endl;
   cin >> S;
    cout << "Введите скорость полета V (м/с): " << endl;
    cin >> V;
    cout << "Введите плотность воздуха r (кг/м^3): " << endl;
    cin >> r;    
    cout << "Введите коэффициент сопротивления CD: "<< endl;
    cin >> CD;
    double drag = calculateDrag(r, V, S, CD);
    cout.precision(7);
    cout << "Аэродинамическое сопротивление L = " << drag << " Н." << endl;

    return 0;
}
