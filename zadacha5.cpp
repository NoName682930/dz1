#include <iostream>
#include <string>

using namespace std;


struct samolet {
    string name; 
    double m;    
    double S;    
    double T;   
    double CL;  
    double CD;  
};

int main() {
    setlocale(LC_ALL, "Russian");
    const double g = 9.81;
    const double r = 1.225; 
    double V = 150.0; 

    
    samolet planes[3] = {
        {"Истребитель", 15000.0, 40.0, 80000.0, 0.6, 0.05},
        {"Пассажирский", 60000.0, 120.0, 180000.0, 0.8, 0.04},
        {"Легкий ЛА", 2000.0, 15.0, 5000.0, 0.5, 0.06}
    };

    double max_ay = -1000.0; 
    int best_index = -1;    
    
    for (int i = 0; i < 3; i++) {
        double L = 0.5 * r * V * V * planes[i].S * planes[i].CL;
        double D = 0.5 * r * V * V * planes[i].S * planes[i].CD;
        
        double ax = (planes[i].T - D) / planes[i].m;
        double ay = (L - planes[i].m * g) / planes[i].m;

        cout << planes[i].name << ": Подъемная сила = " << L << " Н, Ускорение a_y = " << ay << " м/с^2" << endl;

        
        if (ay > max_ay) {
            max_ay = ay;
            best_index = i;
        }
    }

    cout << "\nБыстрее всех наберет высоту: " << planes[best_index].name << "!" << endl;

    return 0;
}
