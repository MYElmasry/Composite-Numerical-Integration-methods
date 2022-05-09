#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    char e;
    cout<<"Choose a composite method:"<<endl<<"\t1. Composite Midpoint"<<endl<<"\t2. Composite Trapezoidal"<<endl<<"\t3. Composite Simpson"<<endl;
    cin>>n;
    MenuMethods:
    if(n<1||n>3){
            cout<<"\t\tChoice must be from 1 to 3. Retry again\n\n";
            cin>>n;
            goto MenuMethods;
        }
    cout<<"Choose an equation:"<<endl<<"\ta. x^2"<<endl<<"\tb. x^4"<<endl<<"\tc. sin(x)"<<endl<<"\td. e^x"<<endl;
    cin>>e;
    MenuEquations:
    if(e<'a'||e>'d'){
            cout<<"\t\tChoice must be from a to d. Retry again\n\n";
            cin>>e;
            goto MenuEquations;
        }
    double a,b,h,result=0;
    cout<<"Enter a, b and h respectively: "<<endl;
    cin>>a>>b>>h;
    if(n==1){
        if(e=='a'){
            double mid = a+h/2;
            result = mid *mid;
            while(mid+h < b){
                mid+=h;
                result+=mid*mid;
            }
            cout<<endl<<"The approximation for the integration of the function x^2 = "<<result*h<<endl;

        }
        else if(e=='b'){
            double mid = a+h/2;
            result = pow(mid,4);
            while(mid+h < b){
                mid+=h;
                result+= pow(mid,4);
            }
            cout<<endl<<"The approximation for the integration of the function x^4 = "<<result*h<<endl;
        }
        else if(e=='c'){
            double mid = a+h/2;
            result = sin(mid);
            while(mid+h < b){
                mid+=h;
                result+= sin(mid);
            }
            cout<<endl<<"The approximation for the integration of the function sin(x) = "<<result*h<<endl;
        }
        else if(e=='d'){
            double mid = a+h/2;
            result = exp(mid);
            while(mid+h < b){
                mid+=h;
                result+= exp(mid);
            }
            cout<<endl<<"The approximation for the integration of the function e^x = "<<result*h<<endl;
        }

    }
    else if(n==2){
        if(e=='a'){
            double mid = h;
            result = mid *mid;
            while(mid+h < b){
                mid+=h;
                result+=mid*mid;
            }
            cout<<endl<<"The approximation for the integration of the function x^2 = "<<(h/2)*((a*a)+(2*result)+(b*b))<<endl;
        }
        else if(e=='b'){
            double mid = h;
            result = pow(mid,4);
            while(mid+h < b){
                mid+=h;
                result+=pow(mid,4);
            }
            cout<<endl<<"The approximation for the integration of the function x^4 = "<<(h/2)*(pow(a,4)+(2*result)+pow(b,4))<<endl;
        }
        else if(e=='c'){
            double mid = h;
            result = sin(mid);
            while(mid+h < b){
                mid+=h;
                result+=sin(mid);
            }
            cout<<endl<<"The approximation for the integration of the function sin(x) = "<<(h/2)*(sin(a)+(2*result)+sin(b))<<endl;
        }
        else if(e=='d'){
            double mid = h;
            result = exp(mid);
            while(mid+h < b){
                mid+=h;
                result+=exp(mid);
            }
            cout<<endl<<"The approximation for the integration of the function e^x = "<<(h/2)*(exp(a)+(2*result)+exp(b))<<endl;
        }

    }
    else if(n==3){
        if(e=='a'){
            double mid = h,r1=0,r2=0;
            int counter = 1;
            while(mid+h<=b){
                if(counter%2==1){
                    r1+=mid*mid;
                }
                else{
                  r2+=mid*mid;
                }
                counter++;
                mid+=h;
            }
            cout<<endl<<"The approximation for the integration of the function x^2 = "<<(h/3)*((a*a)+(4*r1)+(2*r2)+(b*b))<<endl;
        }
        else if(e=='b'){
            double mid = h,r1=0,r2=0;
            int counter = 1;
            while(mid+h<=b){
                if(counter%2==1){
                    r1+=pow(mid,4);
                }
                else{
                  r2+=pow(mid,4);
                }
                counter++;
                mid+=h;
            }
            cout<<endl<<"The approximation for the integration of the function x^4 = "<<(h/3)*(pow(a,4)+(4*r1)+(2*r2)+pow(b,4))<<endl;
        }
        else if(e=='c'){
            double mid = h,r1=0,r2=0;
            int counter = 1;
            while(mid+h<=b){
                if(counter%2==1){
                    r1+=sin(mid);
                }
                else{
                  r2+=sin(mid);
                }
                counter++;
                mid+=h;
            }
            cout<<endl<<"The approximation for the integration of the function sin(x) = "<<(h/3)*(sin(a)+(4*r1)+(2*r2)+sin(b))<<endl;
        }
        else if(e=='d'){
            double mid = h,r1=0,r2=0;
            int counter = 1;
            while(mid+h<=b){
                if(counter%2==1){
                    r1+=exp(mid);
                }
                else{
                  r2+=exp(mid);
                }
                counter++;
                mid+=h;
            }
            cout<<endl<<"The approximation for the integration of the function e^x = "<<(h/3)*(exp(a)+(4*r1)+(2*r2)+exp(b))<<endl;
        }
    }
    return 0;
}
