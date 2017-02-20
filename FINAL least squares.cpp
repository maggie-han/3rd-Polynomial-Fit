 //Maggie Han
 //AP physics assignment 0
 //C programming Least Squares
 //Accept a set of data then effect 3rd degree polynomial fit
 //using least squares and Vandemonde matrix
 #include <iostream>
 #include <math.h>
 #include <iomanip>
 #include <cstdlib>

 using namespace std;
 int main()
    {
        //**************************************************input**********************************************
        int size,ro,co;
        cout<<"How many data points are available? ";
        cin>>size;
        ro=size;
        double x[size];
        double y[size];
        double v[size][4];
        double vt[4][size];
        double vtv[size][size];
        co=4;
        cout<<"Key in the x values: \n";
        for (int i=0;i<size;i++)
            cin>>x[i];
        cout<<"Key in the corresponding y values: \n";
        for (int i=0;i<size;i++)
            cin>>y[i];

        //**************************************************processing**********************************************
        //now create the vandermonde matrix in the form x^3+x^2+x^1+x^0 as well as its transpose
         for (int i=0;i<ro;i++)
        {
            for (int j=0;j<co;j++)
            {
                v[i][j]=pow((x[i]),(3-j));
                vt[j][i]=v[i][j];
            }
        }
        //Calculate vtv
        double temp;
        for (int i=0;i<4;i++)
        {
            for (int j=0;j<4;j++)
            {
                temp=0; //this allows the value of each term to cumulate to the sum that is vtv in each cell
                for (int k=0;k<size;k++)
                {
                    temp= temp+ vt[i][k]*v[k][j];
                }
                vtv[i][j]=temp; //writes value into vtv matrix
            }
        }

       //**************************************************output**********************************************
       system("cls");
       cout<<"This is the Vandermonde Matrix: ";
         for (int i=0;i<ro;i++)
        {
            cout<<"\n";
            for (int j=0;j<co;j++)
            {
                cout<<v[i][j]<<setw(15);
            }
        }

        cout<<"\n\nThis is the Transposed Vandermonde Matrix: ";
         for (int i=0;i<co;i++)
        {
            cout<<"\n";
            for (int j=0;j<ro;j++)
            {
                cout<<vt[i][j]<<setw(9);
            }
        }

        cout<<"\n\nThis is VtV: ";
        for (int i=0;i<4;i++)
        {
            cout<<"\n";
            for (int j=0;j<4;j++)
            {
                cout<<vtv[i][j]<<setw(15);
            }
        }

        //display the input data
        cout<<"\n\nThese are the data inputted";
        cout<<"\nx"<<setw(15)<<"y\n";
        for (int i=0;i<size;i++)
            cout<<x[i]<<setw(15)<<y[i]<<"\n";
    }
