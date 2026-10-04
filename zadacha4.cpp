#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    double h, a_y;

    cout << "Введите требуемую высоту h (м): ";
    cin >> h;
    
    cout << "Введите вертикальное ускорение a_y (м/с^2): ";
    cin >> a_y;

    
    if (h <= 0) {
        cout << "Ошибка: высота должна быть положительной!" << endl;
    } 
    else if (a_y <= 0) {
        cout << "Ошибка: с таким ускорением (a_y <= 0) самолет не набирает высоту!" << endl;
    } 
    else {
        
        double t = sqrt((2 * h) / a_y);
        cout.precision(7);
        cout << "Самолет наберет высоту " << h << " м за " << t << " секунд." << endl;
    }

    return 0;
}
