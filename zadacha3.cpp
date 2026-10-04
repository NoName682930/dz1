
#include <iostream>

using namespace std;

int main() {
    
    const double g = 9.80665; 
    
    
    double m , L , D , T ; 
	cout << "Введите массу (кг): " << endl;
   cin >> m;
    cout << "Введите подъемну силу (Н): " << endl;
    cin >> L;
    cout << "Введите опротивление (Н): " << endl;
    cin >> D;    
    cout << "Введите тягу (Н): "<< endl;
    cin >> T;

    
    double a_x = (T - D) / m;
    double a_y = (L - m * g) / m;
	cout.precision(7);
    cout << "Продольное ускорение a_x = " << a_x << " м/с^2" << endl;
    cout << "(отвечает за разгон или торможение самолета вдоль оси движения)\n" << endl;
    
    cout << "Вертикальное ускорение a_y = " << a_y << " м/с^2" << endl;
    cout << "(отвечает за набор высоты или снижение)\n" << endl;

    return 0;
}
