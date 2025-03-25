#include <bits/stdc++.h>
using namespace std;
double nx = 30, ny = 50, lx = 1, ly = 3;
double dx = lx / nx, dy = ly / ny;

vector<double> x, y1_value, y2_value;
vector<vector<double>> X(ny + 1, vector<double>(nx + 1, 0));
vector<vector<double>> Y(ny + 1, vector<double>(nx + 1, 0));

void xuatData()
{
    ofstream outfile;
    outfile.open("hinhtrontronghcn.tec");
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
    for (int j = 0; j <= nx; j++)
    {
        x.push_back(j * dx);
        y2_value.push_back(sqrt(x[j] * (lx - x[j])));
    }
    for (int j = 0; j <= nx; j++)
    {
        for (int i = 0; i <= ny; i++)
        {
            X[i][j] = x[j];
        }
    }
    for (int i = 0; i <= ny; i++)
    {
        for (int j = 0; j <= nx; j++)
        {
            Y[i][j] = (ly - y2_value[j]) * i  / ny + y2_value[j];
        }
    }
    xuatData();
    return 0;
}
