#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Aircraft {
    string name;
    double m;    
    double S;    
    double T;    
    double CL;  
    double CD;  
    double ay; 
    double t; 
};

int main() {
    const double g = 9.81;
    const double r = 1.225;
    double V = 150.0;
    double h = 2000.0; 

 
    Aircraft planes[3] = {
        {"Fightr", 15000.0, 40.0, 80000.0, 0.6, 0.05},
        {"Airliner", 60000.0, 120.0, 180000.0, 0.8, 0.04},
        {"Light_UAV", 2000.0, 15.0, 5000.0, 0.5, 0.06}
    };

    for (int i = 0; i < 3; i++) {
        
        double L = 0.5 * r * V * V * planes[i].S * planes[i].CL;
        planes[i].ay = (L - planes[i].m * g) / planes[i].m;

        if (planes[i].ay > 0) {
            planes[i].t = sqrt((2 * h) / planes[i].ay);
        } else {
            planes[i].t = 1000000000000000; 
        }
    }

    for (int i = 0; i < 3 - 1; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {
            if (planes[j].t > planes[j + 1].t) {
                Aircraft temp = planes[j];
                planes[j] = planes[j + 1];
                planes[j + 1] = temp;
            }
        }
    }

    cout << "Результаты сортировки по времени набора высоты:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << planes[i].name;
        if (planes[i].t == 10000000000000000) {
            cout << " | Высоту набрать не может" << endl;
        } else {
            cout << " | Время: " << planes[i].t << " c" << endl;
        }
    }

    return 0;
}
