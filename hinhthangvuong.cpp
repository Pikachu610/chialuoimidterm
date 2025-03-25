#include <bits/stdc++.h>
using namespace std;

double lx = 0.5/ tan(45*3.14159265358979323846/180), ly1 = 0.5, ly2 = 1;
double nx = 50, ny = 30;
double dx = lx / nx, dy1 = ly1 / ny, dy2 = ly2 / ny;
vector<double> x, y1_value,y2_value;
vector<vector<double>> X(ny + 1, vector<double>(nx + 1, 0));
vector<vector<double>> Y(ny + 1, vector<double>(nx + 1, 0));
double daytamgiac= 0.5/ tan(60*3.14159265358979323846/180) + 0.5/ tan(45*3.14159265358979323846/180);
void xuatData()
{
    ofstream outfile;
    outfile.open("chialuoihinhthang888.tec");
    outfile << "VARIABLES = X Y" << endl;
    outfile << "ZONE I = " << nx+1 << ", J = " << ny+1 << ", F = POINT" << endl;
    for (int i = 0; i <=  ny; i++)
    {
        for (int j= 0; j <= nx; j++)
        {
            outfile << X[i][j] << '\t' << Y[i][j] << endl;
        }
    }
    cout<<"Xuat file thanh cong"<<endl;
    outfile.close();
}
int main()
{
    for (int i = 0; i <= nx; i++)
    {
        x.push_back(i * dx);
    }
    for (int j = 0; j <= ny; j++)
    {
        y1_value.push_back(j * dy1);
        y2_value.push_back(j * dy2+(ly1-ly2));
    }
    for (int j = 0; j <= nx; j++)
    {
        for (int i = 0; i <= ny; i++)
        {
            X[i][j] = x[j]+0.5/tan(60*3.14159265358979323846/180)+0.5;
        }
    }
    for (int i = 0; i <= ny; i++)
    {
        for (int j = 0; j <= nx; j++)
        {
            Y[i][j] =ly2/2+ y1_value[i] + (y2_value[i] - y1_value[i]) / lx * x[j];
        }
    }
    xuatData();
    return 0;
}
