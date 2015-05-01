#ifndef TTT_H
#define TTT_H
#include<iostream>
#include<math.h>
#include<cmath>
#include <iomanip>      // for setprecision

using namespace  std;
// **************/////// functions to claculate equation ,true Y,error ,relative error
// f(x)=2xy
float h;
float end;
void get_h(){
    //float h;
    cout<<"enter the step (h) : ";
    cin>>h;
    cout<<"enter the end of Xn : ";
    cin>>end;
}


// calculat function
float equation(float x, float y)
{
    return  2*x*y;
}


// calculate true y
float true_y(float x)
{
   return pow(exp(1),pow(x,2)-1);

}
//calCULAT error   error = |true_time - approxumate_time |
float error(float y,float ytrue){
    return abs(y-ytrue);
}
float relative_error(float i, float y){
    return error(y,true_y(i))*100/(abs(true_y(i)));
}


/*
 *
 *just  eulat method to call it two times
 * */
float eular_method(float x, float y){
        //claculate (yi+1)
        float yy=y+h*equation(x,y);

return yy;
}


// ***************//////////////////*******************///////////////

// calculation eular method

float eular(){
    float y, yy=y=1;
    for (float i = 1; i < end; i+=h) {
        //claculate el yy (yi+1)
        cout<<i;
        cout<<"\t| "<<yy;
        //yy=y+h*equation(i,y);
       yy= eular_method(i,y);

        // cout true y
        cout<<"\t| "<<fixed<<setprecision(3)<< true_y(i);
        // cout el error
        cout<<"\t| "<< error(y,true_y(i));
        // cout el relative error
        cout<<"\t| "<< error(y,true_y(i))*100/(abs(true_y(i)))<<" %";
        cout<<endl;
        // bensawy el yy b el y 3lshan ye pass el yy akenha y gdeda lel equation
        y=yy;
    }
    cout<<endl;
return yy;
}


/*
* improved eular :
*/
float improve_eular(){

    float yyimp=1, y=1;
    for (float i = 1; i < end; i+=h) {
       cout<<i <<"\t| "<<yyimp;
        yyimp = y + 0.5*h*(equation(i, y) + equation(i + h, eular_method(i,y)));
        cout<<"\t| "<<fixed<<setprecision(3)<<true_y(i);
        cout<<"\t| "<<error(y,true_y(i));
        cout<<"\t| "<<relative_error(i,y)<<" %";
        cout<<endl;
       y=yyimp;

    }
            return yyimp;
}



/*
 *
 * hean function
 *

*/
float hean(){

    float yhean=1;
    float k1, k2;
    float y=1;

    for (float i = 1; i < end; i+=h) {
        k1 = equation(i, y);
        k2 = equation(i + h, y + k1*h);

        //claculate el yhean (yi+1)
        yhean = y + h*(0.5*k1 + 0.5 * k2);


        cout<<i<<"\t| "<<fixed<<setprecision(3)<<yhean;
        cout<<"\t| "<< true_y(i);
        cout<<"\t| "<< error(y,true_y(i));
        cout<<"\t| "<<relative_error(i,y)<<" %"<<endl;

        y=yhean;
    }
   cout<<yhean;
    return yhean;
}


/*
 *
 * range kutta
 **
*/
float range_kutta(){

    float yyrange=1 ,y=1;

    for (float i = 1; i < end; i+=h) {
        float k1=equation(i,y);
        float p=1,q=1,a1=0.5,a2=0.5;
       float  k2=equation(i+p*h,y+q*k1*h);
    yyrange=i+h*(a1*k1+a2*k2);
    cout<<i<<"\t| "<<fixed<<setprecision(5)<<yyrange;
    cout<<"\t| "<<true_y(i);
    cout<<"\t| "<<error(y,true_y(i));
    cout<<"\t| "<<relative_error(i,y)<<" %"<<endl;
    y=yyrange;
    }
    return yyrange;
}

/*
 *
 * fourth range kutta
 *
 *
*/
float range_kutta_fourth(){
    float k1,k2,k3,k4;
    float y=1;
    float yyrangekuttaFourth=1;
    for (float i = 1; i < end; i+=h) {

        k1=equation(i,y);
        // k2=equation( x+0.5*5,y+0.5h)
        k2=equation(i+0.5*h,y+0.5*h*k1);
        k3=equation(i+0.5*h,y+0.5*k2*h);
        k4=equation(i+h,y+k3*h);
        yyrangekuttaFourth=y+((h/6)*(k1+2*k2+2*k3+k4));
        cout<<i<<"\t| "<< fixed<<setprecision(5)<<yyrangekuttaFourth;
        cout<<"\t| "<<true_y(i);
        cout<<"\t| "<<error(y,true_y(i));
        cout<<"\t| "<<relative_error(i,y)<<" %"<<endl;
        y=yyrangekuttaFourth;

    }
return yyrangekuttaFourth;
}


/*
 *
 * display
 * */
void display(){

    cout<<"  Xi"<<"\t"<<"  Yi"<<"\t"<<"  true Y"<<"  error"<<"\t"<<"  relError"<<endl;
    cout<<"_______________________________________________"<<endl;
}



#endif // TTT_H
