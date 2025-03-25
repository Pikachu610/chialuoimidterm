#include <bits/stdc++.h>
using namespace std;
double ly = 1, lx = 0.5;
double ny = 40, nxtong = 120;
double nx=30;
double dx = lx / nx, dy = ly / ny;
double daytamgiac= 0.5/ tan(60*3.14159265358979323846/180) + 0.5/ tan(45*3.14159265358979323846/180);

vector<double> x, y;
vector<vector<double>> X(ny + 1, vector<double>(nxtong + 1, 0));
vector<vector<double>> Y(ny + 1, vector<double>(nxtong + 1, 0));
//hinh thang 1 
double lx_hinhthang1 = 0.5/tan(60*3.14159265358979323846/180), ly1_hinhthang1 = 0.5, ly2_hinhthang1 = 1;
double dx_hinhthang1 = lx_hinhthang1 / nx, dy1_hinhthang1 = ly1_hinhthang1 / ny, dy2_hinhthang1 = ly2_hinhthang1 / ny;
vector<double> x_hinhthang1, y1_value_hinhthang1,y2_value_hinhthang1;
//hinh thang 2
double lx_hinhthang2 = 0.5/ tan(45*3.14159265358979323846/180), ly1_hinhthang2 = 0.5, ly2_hinhthang2 = 1;
double dx_hinhthang2 = lx_hinhthang2 / nx, dy1_hinhthang2 = ly1_hinhthang2 / ny, dy2_hinhthang2 = ly2_hinhthang2 / ny;
vector<double> x_hinhthang2, y1_value_hinhthang2, y2_value_hinhthang2;

void xuatData()
{
    ofstream outfile;
    outfile.open("midterm.tec");
    outfile << "VARIABLES = X Y" << endl;
    outfile << "ZONE I = " << nxtong + 1 << ", J = " << ny + 1 << ", F = POINT" << endl;
    for (int i = 0; i <= ny; i++)
    {
        for (int j = 0; j <= nxtong; j++)
        {
            outfile << X[i][j] << '\t' << Y[i][j] << endl;
        }
    }
    cout<<daytamgiac << "❤️     ❤️     ❤️    Đã xuất được file midterm.tec     ❤️     ❤️     ❤️  " << endl;
    outfile.close();
}
int main()
{
    //hcn1
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
    //hcn2
    for (int j = 90; j <= nxtong; j++)
    {
        x.push_back((j-90) * dx );
        for (int i = 0; i <= ny; i++)
        {
            X[i][j] = x[(j-90)]+ daytamgiac+lx;
        }
    }
    for (int i = 0; i <= ny; i++)
    {
        y.push_back(i * dy);
        for (int j = 90; j <= nxtong; j++)
        {
            Y[i][j] = y[i];
        }
    }
    // hinh thang 1
    for (int j = 30; j <= 2*nx; j++)
    {
        x_hinhthang1.push_back((j-30) * dx);
    }
    for (int i = 0; i <= ny; i++)
    {
        y1_value_hinhthang1.push_back(i * dy1_hinhthang1 + (ly2_hinhthang1 - ly1_hinhthang1));
        y2_value_hinhthang1.push_back(i * dy2_hinhthang1);
    }
    for (int j = 30; j <= 2*nx; j++)
    {
        for (int i = 0; i <= ny; i++)
        {
            X[i][j] = x_hinhthang1[(j-30)]+lx;
        }
    }
    for(int i=0; i<=ny; i++){
        for(int j=30; j<=2*nx;j++){
            Y[i][j] = (y1_value_hinhthang1[i]-y2_value_hinhthang1[i])*x_hinhthang1[(j-30)] / lx_hinhthang1 + y2_value_hinhthang1[i] ;
        }
    }

    // hinh thang 2

    for (int j = 90; j <= 3*nx; j++)
    {
        x_hinhthang2.push_back((j-90) * dx);
    }
    for (int j = 0; j <= ny; j++)
    {
        y1_value_hinhthang2.push_back(j * dy1_hinhthang2);
        y2_value_hinhthang2.push_back(j * dy2_hinhthang2+(ly1_hinhthang2-ly2_hinhthang2));
    }
    for (int j = 90; j <= 3*nx; j++)
    {
        for (int i = 0; i <= ny; i++)
        {
            X[i][j] = x_hinhthang2[(j-90)]+ lx+lx_hinhthang1;
        }
    }
    for (int i = 0; i <= ny; i++)
    {
        for (int j = 90; j <= 3* nx; j++)
        {
            Y[i][j] =ly2_hinhthang2/2+ y1_value_hinhthang2[i] + (y2_value_hinhthang2[i] - y1_value_hinhthang2[i]) / lx_hinhthang2 * x_hinhthang2[(j-90)];
        }
    }  
    xuatData();
    return 0;
}