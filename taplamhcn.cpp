#include <bits/stdc++.h>
using namespace std;
double ly = 2, lx = 1;
double ny = 50, nx = 30;
double dx = lx / nx, dy = ly / ny;
vector<double> x, y;
vector<vector<double>> X(ny + 1, vector<double>(nx + 1, 0));
vector<vector<double>> Y(ny + 1, vector<double>(nx + 1, 0));
void xuatData()
{
    ofstream outfile;
    //dùng để ghi file, ifstream dùng để đọc file
    outfile.open("taplamhcn.tec");
    outfile << "VARIABLES = X Y" << endl;
    outfile << "ZONE I = " << nx + 1 << ", J = " << ny + 1 << ", F = POINT" << endl;
    for (int i = 0; i <= ny; i++)
    {
        for (int j = 0; j <= nx; j++)
        {
            outfile << X[i][j] << '\t' << Y[i][j] << endl;
        }
    }
    cout << "❤️     ❤️     ❤️   xuất được file chialuoitulam1.tec     ❤️     ❤️     ❤️  " << endl;
    outfile.close();
}
int main()
{
    for (int j = 0; j <= nx; j++)
    {
        x.push_back(j * dx);
        for (int i = 0; i <= ny; i++)
        {
            X[i][j] = x[j];
        }
    }
    for (int i = 0; i <= ny; i++)
    {
        y.push_back(i * dy);
        for (int j = 0; j <= nx; j++)
        {
            Y[i][j] = y[i];
        }
    }
    xuatData();
    return 0;
}