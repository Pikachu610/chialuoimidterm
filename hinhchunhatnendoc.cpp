#include <bits/stdc++.h>
using namespace std;
double lx = 1, ly = 2;
double nx = 30, ny = 50;
double dx = lx / nx, dy = ly / ny;
vector<double> x, y;
vector<vector<double>> X(ny + 1, vector<double>(nx + 1, 0));
vector<vector<double>> Y(ny + 1, vector<double>(nx + 1, 0));
void xuatData()
{
    ofstream outfile;
    outfile.open("hcnnendoc.tec");
    outfile << "VARIABLES = X Y" << endl;
    outfile << "ZONE I = " << nx+1 << ", J = " << ny+1 << ", F = POINT" << endl;
    for (int i = 0; i <=  ny; i++)
    {
        for (int j= 0; j <= nx; j++)
        {
            outfile << X[i][j] << '\t' << Y[i][j] << endl;
        }
    }
    cout<<"❤️     ❤️     ❤️   xuất được file hcnnendoc.tec     ❤️     ❤️     ❤️  "<<endl;
    outfile.close();
}
int main()
{
    
    double heso = 1;
    
    double tongtong = 0;
    
    for (int i = -nx/2; i <= nx/2; i++)
    {
        tongtong += heso*i*i +1;
    }
    for (int i = 0; i <= nx; i++)
    {
        if(i == 0) x.push_back(0);
        else
        x.push_back(x[i-1]+ ((heso*(i-1)-nx/2)*(heso*(i-1)-nx/2) + 1)/tongtong);
        if(i == nx){
            x.push_back(x[i]+ ((heso*(i)-nx/2)*(heso*(i)-nx/2) + 1)/tongtong);
        }
    }
    for (int i = 0; i <= ny; i++)
    {
        if(i == 0) y.push_back(0);

        else
        y.push_back(i * dy);
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
            Y[i][j] = y[i];
        }
    }
    xuatData();
    return 0;
}
