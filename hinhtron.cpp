#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846
double R = 5; 
double nx = 30, ny = 50;  
double dr = R / nx, dalpha = 2 * PI / ny; 
vector<double> r,alpha;
vector<vector<double>> X(ny + 1, vector<double>(nx + 1, 0));
vector<vector<double>> Y(ny + 1, vector<double>(nx + 1, 0));

void xuatData()
{
    ofstream outfile;
    outfile.open("chialuoihinhtron.tec");
    outfile << "VARIABLES = X Y" << endl;
    outfile << "ZONE I = " << nx + 1 << ", J = " << ny + 1 << ", F = POINT" << endl;
    for (int i = 0; i <= ny; i++)
    {
        for (int j = 0; j <= nx; j++)
        {
            outfile << X[i][j] << '\t' << Y[i][j] << endl;
        }
    }
    cout << "Xuat file thanh cong!" << endl;
    outfile.close();
}

int main()
{
    // for (int i = 0; i <= nx; i++)
    // {
    //     double r = i * dr;  
    //     for (int j = 0; j <= ny; j++)
    //     {
    //         double alpha = j * dalpha; 
    //         X[j][i] = r * cos(alpha); 
    //         Y[j][i] = r * sin(alpha);  
    //     }
    // }
    for(int j = 0; j <= nx; j++)
    {
        r.push_back(j * dr);
    }
    for(int i = 0; i <= ny; i++)
    {
        alpha.push_back(i * dalpha);
    }
    for(int i = 0; i <= ny; i++)
    {
        for(int j = 0; j <= nx; j++)
        {
            X[i][j] = r[j] * cos(alpha[i]);
            Y[i][j] = r[j] * sin(alpha[i]);
        }
    }
    xuatData();
    return 0;
}