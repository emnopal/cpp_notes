#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    int i,j,k,n;
    
    // Amount of Arrays
    cout<<"\nEnter the no. of data pairs to be entered:\n";        
    cin>>n;
    
    // Input X and Y Values
    double x[n],y[n],a,b;
    
    // X Value
    cout<<"\nEnter the x-axis values:\n";                
    for (i=0;i<n;i++)
        cin>>x[i];
    
    // Y Value
    cout<<"\nEnter the y-axis values:\n";                
    for (i=0;i<n;i++)
        cin>>y[i];
    
    // Count X and Y Value
    double xsum=0,x2sum=0,ysum=0,xysum=0;           
    for (i=0;i<n;i++){

        xsum=xsum+x[i];                        
        ysum=ysum+y[i];                        
        x2sum=x2sum+pow(x[i],2);                
        xysum=xysum+x[i]*y[i];                    
    }

    a=(n*xysum-xsum*ysum)/(n*x2sum-xsum*xsum);            
    b=(x2sum*ysum-xsum*xysum)/(x2sum*n-xsum*xsum);        
    double y_fit[n];                            
    
    // For Showing a Result
    for (i=0;i<n;i++)
        y_fit[i]=a*x[i]+b;                  
    cout<<"S.no"<<setw(5)<<"x"<<setw(19)<<"y(observed)"<<setw(19)<<"y(fitted)"<<endl;
    cout<<"-----------------------------------------------------------------\n";
    for (i=0;i<n;i++)
        cout<<i+1<<"."<<setw(8)<<x[i]<<setw(15)<<y[i]<<setw(18)<<y_fit[i]<<endl;   
    cout <<;
    cout<<"\nThe linear fit line is of the form:\n"<<a<<"x + "<<b<<"\nlinear form is ax+b"<<endl;      
    return 0;
}   