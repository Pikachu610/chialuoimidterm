#include <bits/stdc++.h>
using namespace std;
double lx = 0.5/ tan(60*3.14159265358979323846/180), ly1 = 0.5, ly2 = 1;
double ny = 40, nx = 60;
double dx = lx / nx, dy1 = ly1 / ny, dy2 = ly2 / ny;
vector<double> x, y1_value, y2_value;
vector<vector<double>> X(ny + 1, vector<double>(nx + 1, 0));
vector<vector<double>> Y(ny + 1, vector<double>(nx + 1, 0));
void xuatData()
{
    ofstream outfile;
    // dùng để ghi file, ifstream dùng để đọc file
    outfile.open("taplamhtvuong.tec");
    outfile << "VARIABLES = X Y" << endl;
    outfile << "ZONE I = " << nx + 1 << ", J = " << ny + 1 << ", F = POINT" << endl;
    for (int i = 0; i <= ny; i++)
    {
        for (int j = 0; j <= nx; j++)
        {
            outfile << X[i][j] << '\t' << Y[i][j] << endl;
        }
    }
    cout << "❤️     ❤️     ❤️   xuất được file     ❤️     ❤️     ❤️  " << endl;
    outfile.close();
}
int main()
{
    for (int j = 0; j <= nx; j++)
    {
        x.push_back(j * dx);
    }
    for (int i = 0; i <= ny; i++)
    {
        y1_value.push_back(i * dy1 + (ly2 - ly1));
        y2_value.push_back(i * dy2);
    }
    for (int j = 0; j <= nx; j++)
    {
        for (int i = 0; i <= ny; i++)
        {
            X[i][j] = x[j]+0.5;
        }
    }
    for(int i=0; i<=ny; i++){
        for(int j=0; j<=nx;j++){
            Y[i][j] = (y1_value[i]-y2_value[i])*x[j] / lx + y2_value[i] ;
        }
    }
    xuatData();
    return 0;
}