#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double m = 500.0;
    double D = 50.0;
    const double g = 9.81;
    double h = 1000.0;

    double Tmin, Tmax, dT;

    
    do {
        cout << "Введите минимальную тягу Tmin (Н): ";
        cin >> Tmin;
        cout << "Введите максимальную тягу Tmax (Н): ";
        cin >> Tmax;
        cout << "Введите шаг изменения тяги dT (Н): ";
        cin >> dT;

        if (Tmin >= Tmax || dT <= 0) {
            cout << "\nОшибка! Tmax должно быть больше Tmin, а шаг dT — положительным." << endl;
            cout << "Пожалуйста, повторите ввод.\n" << endl;
        }
    } while (Tmin >= Tmax || dT <= 0);

    int n = floor((Tmax - Tmin) / dT) + 1;
    double* T = new double[n];

    for (int i = 0; i < n; i++) {
        T[i] = Tmin + i * dT;
    }

    double min_t = 10000000000000000000; 
    int ind_min = -1;

    for (int i = 0; i < n; i++) {
        
        if (T[i] <= D) {
            continue; 
        }

        
        double ay = ((T[i] - D) / m) * ((T[i] - D) / (m * g));

        if (ay > 0) {
            double t = sqrt(2 * h / ay);
            if (t < min_t) {
                min_t = t;
                ind_min = i; 
            }
        }
    }

    cout << "\n=== РЕЗУЛЬТАТЫ ОПТИМИЗАЦИИ ===" << endl;
    if (ind_min == -1) {
        cout << "Ни при какой заданной тяге самолет не набирает высоту." << endl;
    } else {
        cout << "Оптимальная тяга: " << T[ind_min] << " Н" << endl;
        cout << "Минимальное время набора высоты: " << min_t << " с" << endl;
    }

    delete[] T;

    return 0;
}
