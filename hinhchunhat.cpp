#include <bits/stdc++.h>
using namespace std;
double lx = 1, ly = 2;
double nx = 30, ny = 50;
double dx = lx / nx, dy = ly / ny;
double total_sum = 0;
const double PI = 3.14159265358979323846;
vector<double> x, y;
vector<vector<double>> X(ny + 1, vector<double>(nx + 1, 0));
vector<vector<double>> Y(ny + 1, vector<double>(nx + 1, 0));
void xuatData()
{
    ofstream outfile;
    outfile.open("chialuoitulam1.tec");
    outfile << "VARIABLES = X Y" << endl;
    outfile << "ZONE I = " << nx+1 << ", J = " << ny+1 << ", F = POINT" << endl;
    for (int i = 0; i <=  ny; i++)
    {
        for (int j= 0; j <= nx; j++)
        {
            outfile << X[i][j] << '\t' << Y[i][j] << endl;
        }
    }
    cout<<"❤️     ❤️     ❤️   xuất được file chialuoitulam1.tec     ❤️     ❤️     ❤️  "<<endl;
    outfile.close();
}
int main()
{

    for (int i = 0; i <= nx; i++)
    {
        x.push_back(i * dx);
    }
    for (int i = 0; i <= ny; i++)
    {
        double dy = (ly / ny) * (1 - cos(PI * i / ny));  // Nén lưới theo cosine
        double total_sum = total_sum +  dy ;
        
        if (i == 0) {
            y.push_back(0);  // Điểm đầu tiên (y = 0)
        } else {
            y.push_back(y[i - 1] + total_sum);  // Cộng dồn các dy để tính giá trị y
        }
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
