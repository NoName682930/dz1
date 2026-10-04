#include <iostream>
#include <string>

using namespace std;

struct Aircraft {
    string name;
    double m;
    double S;
    double T;
    double CL;
    double CD;
   
    double L;
    double D;
    double ay; 
};

int main() {
    const double g = 9.81;
    const double r = 1.225;
    double V = 150.0;
    int N;

    cout << "Введите количество конфигураций самолета N: ";
    cin >> N;

    
    Aircraft* planes = new Aircraft[N];

   
    for (int i = 0; i < N; i++) {
        cout << "\nВведите данные для самолета " << i + 1 << ":" << endl;
        cout << "Название: ";
        cin >> planes[i].name;
        cout << "Масса (кг): ";
        cin >> planes[i].m;
        cout << "Площадь крыла S (м^2): ";
        cin >> planes[i].S;
        cout << "Тяга T (Н): ";
        cin >> planes[i].T;
        cout << "C_L: ";
        cin >> planes[i].CL;
        cout << "C_D: ";
        cin >> planes[i].CD;

        
        planes[i].L = 0.5 * r * V * V * planes[i].S * planes[i].CL;
        planes[i].D = 0.5 * r * V * V * planes[i].S * planes[i].CD;
        
        
        planes[i].ay = (planes[i].L - planes[i].m * g) / planes[i].m;
    }

    
    double max_ay = -100000000000000; 
    int best_index = -1;

    for (int i = 0; i < N; i++) {
        if (planes[i].ay > max_ay) {
            max_ay = planes[i].ay;
            best_index = i; 
        }
    }

    
    cout << "\n=== РЕЗУЛЬТАТЫ РАСЧЕТОВ ===" << endl;
    for (int i = 0; i < N; i++) {
        cout << planes[i].name << " -> L: " << planes[i].L 
             << " Н, D: " << planes[i].D 
             << " Н, a_y: " << planes[i].ay << " м/с^2" << endl;
    }

    if (best_index != -1) {
        cout << "\nСамолет с наибольшим вертикальным ускорением: " << planes[best_index].name 
             << " (a_y = " << max_ay << " м/с^2)" << endl;
    }

    
    delete[] planes;

    return 0;
}
