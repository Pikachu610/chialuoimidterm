#include <bits/stdc++.h>
using namespace std;
double  ly = 1;
double nxa = 20,nxb=25, ny = 50, nx= nxa+nxb;
double lxa = 0.5/ tan(60*3.14159265358979323846/180), lxb = 0.5/ tan(45*3.14159265358979323846/180);
double lx= lxa+lxb;
double dxa = lxa / nxa, dxb = lxb / nxb, dy = ly / ny;
double dx = lx / (nxa+nxb);
vector<double> xa,xb, y_1,y_2;
vector<double> xcn_1, ycn_1;
vector<vector<double>> X(ny + 1, vector<double>(3*(nxa+nxb) + 1, 0));
vector<vector<double>> Y(ny + 1, vector<double>(3*(nxa+nxb) + 1, 0));
void xuatData()
{
    ofstream outfile;
    outfile.open("DinhNgocLong.tec");
    outfile << "VARIABLES = X Y" << endl;
    outfile << "ZONE I = " << 3*(nxa+nxb)+1 << ", J = " << ny+1 << ", F = POINT" << endl;
    for (int i = 0; i <=  ny; i++)
    {
        for (int j= 0; j <= 3*(nxa+nxb); j++)
        {
            outfile << X[i][j] << '\t' << Y[i][j] << endl;
        }
    }
    cout<<"❤️     ❤️     ❤️   xuất được file mt3.tec     ❤️     ❤️     ❤️  "<<endl;
    outfile.close();
}
int main()
{
    // nén giữa hình chữ nhật bên trái
    // double heso = 1;
    // double tongtong = 0;
    // for (int i = -ny/2; i <= ny/2; i++)
    // {
    //     tongtong += heso*i*i +1;
    // }
    // for (int i = 0; i <= ny; i++)
    // {
    //     if(i == 0) ycn_1.push_back(0);
    //     else
    //     ycn_1.push_back(ycn_1[i-1]+ ((heso*i-ny/2-1)*(heso*i-ny/2-1) + 1)/tongtong);
    // }  

    //hcn bên trái
    for (int j = 0; j <= nx; j++)
    {
        xcn_1.push_back(j * dx);
        for (int i = 0; i <= ny; i++)
        {
            X[i][j] = xcn_1[j]-lx;
        }
    }
    for (int i = 0; i <= ny; i++)
    {
        //chia đều
        ycn_1.push_back(i * dy);
        //chia đều
        for (int j = 0; j <= nx; j++)
        {
            
            Y[i][j] = ycn_1[i];
        }
    }

    //nén trên dưới
    double tongtong = 0;
    for (int i = -ny/2; i <= ny/2; i++)
    {
        tongtong += -heso*i*i +1;
    }
    for (int i = 0; i <= ny; i++)
    {
        if(i == 0) y.push_back(0);
        else
        y.push_back(y[i-1]+ (-(heso*((i-1)-ny/2))*(((i-1)-ny/2)) + 1)/tongtong);
    }  

    //khung giữa
    for (int i = 0; i <= nxa; i++)
    {
        xa.push_back(i * dxa);
    }
    for (int i = 0; i <= nxb; i++)
    {
        xb.push_back(i * dxb);
    }
    for (int i = 0; i <= nxa; i++)
    {
        y_1.push_back(i * dxa*tan(60*3.14159265358979323846/180));
    }
    for (int i = nxb; i >= 0; i--)
    {
        y_2.push_back(i*dxb);
    }
    for (int j = nx; j <= nx+nxa; j++)
    {
        for (int i = 0; i <= ny; i++)
        {
            X[i][j] = xa[j-nx];
        }
    }
    for (int j = nx+nxa; j <= nx+nxa+nxb; j++)
    {
        for (int i = 0; i <= ny; i++)
        {
            X[i][j] = xb[j-nxa-nx]+lxa;
        }
    }
    for (int i = 0; i <= ny; i++)
    {
        for (int j = nx; j <= nxa+nx; j++)
        {
            Y[i][j] = (ly - y_1[(j-nx)]) * i  / ny + y_1[(j-nx)];
        }
    }
    for (int i = 0; i <= ny; i++)
    {
        for (int j = nxa+nx; j <= nx+nxa+nxb; j++)
        {
            Y[i][j] = (ly - y_2[j-nx-nxa]) * i  / ny + y_2[j-nxa-nx];
        }
    }

    // //hcn bên phải
    for (int j = 2*nx; j <= 3*nx; j++)
    {
        for (int i = 0; i <= ny; i++)
        {
            X[i][j] = xcn_1[j-2*nx]+lx;
        }
    }
    for (int i = 0; i <= ny; i++)
    {
        for (int j = 2*nx; j <= 3*nx; j++)
        {
            
            Y[i][j] = ycn_1[i];
        }
    }
    
    xuatData();
    return 0;
}