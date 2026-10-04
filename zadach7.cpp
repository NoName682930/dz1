#include <iostream>

using namespace std;

int main() {
    double T, L, D, m;
    const double g = 9.81;

    cout << "Введите массу самолета m (кг): ";
    cin >> m;
    cout << "Введите подъемную силу L (Н): ";
    cin >> L;

    
    double ay = (L - m * g) / m;
    
    cout << "Вертикальное ускорение: " << ay << " м/с^2" << endl;

    
    if (ay > 0.5) {
        cout << "Режим: Набор высоты " << endl;
    } 
    else if (ay >= 0.0 && ay <= 0.5) {
        cout << "Режим: Горизонтальный полет ️" << endl;
    } 
    else {
        cout << "Режим: Снижение " << endl;
    }

    return 0;
}
