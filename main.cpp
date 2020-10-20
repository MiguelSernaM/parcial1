#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
#define PI 3.14159265
bool impacto(int,int,int,int,int);
int trayectoriax(int,int,int,double);
int dispardefensivo(int,int,int,double);
int disparofen(int,int,int,double);
int main()
{
    int d,xd,yd,xa=0,ya=0,opc;
    float gravedad=9.81,copt;
    d = 600;
    double angulo = 50.0;
    int impact = 0.05*d,impactd=0.25*d;
    xd = d;
    yd = 100;
    cout <<endl<<"| Que caso quiere simular:                         |"<<endl;
        cout << "| Generar disparos contra el canon defensivo    (1)|"<< endl;
        cout << "| Generar disparos contra el canon ofensivo     (2)|"<< endl;
        cout << "| Generar disparos que defiendan                (3)|"<< endl;
        cout << "| Generar disparos que defiendan y sin destruir (4)|"<< endl;
    cout<<"¿Que desea hacer?"<<endl;
    cin>>opc;
    switch(opc){

case 1:{
        cout<<"Generando 3 disparos efectivos"<<endl;
        for(int i = 0; i<3; i++){
            int o=trayectoriax(xd,yd,impact,angulo);
            angulo+=2;
        }

    break;
    }
case 2:{
    for(int i= 0; i<3;i++){
        if(angulo < 90){
            angulo = 91;
        }
        int o=trayectoriax(xd,yd,impact,angulo);
        angulo += 2;
    }
    }
case 3:{
     trayectoriax(xd,yd,impact,angulo);
     if(angulo <90){
         angulo=91;
     }
     for(int i=0;i<3;i++){
     disparofen(xd, yd, impact, angulo);
     angulo+=2;
     }
    }
case 4:{
    }
 //-----------------
    }

return 0;
}
int trayectoriax(int xd,int yd,int impact,double angulo){
    int cop = angulo,cond=0;
    int vx,vy;
    int posiciones[2]={};
    angulo =angulo*PI/180;
    int vx0,vy0,t=0;
    float raiz;
    for(int v00=0; v00<1000;v00++){
        vx0 = v00*cos(angulo);
        vy0 = v00*sin(angulo);
        for(t=0;t<1000;t++){
            vx=vx0*t;
            vy=vy0*t-(0.5*9.81*t*t);
            raiz=pow((xd-vx),2)+pow((yd-vy),2);
            if(sqrt(raiz)<impact){
                cond=1;
                break;
            }
        }
        if(cond == 1)
            break;

    }
    cout<<"Impacto en angulo: "<<cop<<" Velocidad x0: "<<vx0<<" Velocidad y0: "<<vy0<<" Tiempo: "<<t+2.5<<endl;
    return 0;
}
int dispardefensivo(int xd,int yd,int impact,double angulo,float){
    int cop = -angulo,cond=0;
    int vx,vy;
    angulo =angulo*-PI/180;
    int vx0,vy0,t=0;
    float raiz;
    for(int v00=0; v00<1000;v00++){
        vx0 = v00*cos(angulo);
        vy0 = v00*sin(angulo);
        for(t=0;t<1000;t++){
            vx=xd+vx0*t;
            vy=yd+vy0*t-(0.5*9.81*t*t);
            raiz=pow((0-vx),2)+pow((0-vy),2);
            if(sqrt(raiz)<impact){
                cond=1;
                break;
            }
        }
        if(cond == 1)
            break;

    }
    cout<<"Impacto Defensivo "<<cop<<" Velocidad x0: "<<vx0<<" Velocidad y0: "<<vy0<<" Tiempo: "<<t+2.5<<endl;
    return 0;
}
int disparofen(int xd,int yd,int impactd,double angulo){
    int posx, posy,cop;
    int vx0,vy0,vx,vy,raiz,cond=0;
    cop = angulo;
    float t;
    angulo =angulo*PI/180;
    for(int v00=0; v00<1000;v00++){
        vx0 = v00*cos(angulo);
        vy0 = v00*sin(angulo);
        for(t=0;t<1000;t++){
            vx=xd+vx0*t;
            vy=yd+vy0*t-(0.5*9.81*t*t);
            raiz=pow((xd-vx),2)+pow((xd-vy),2);
            if(sqrt(raiz)<impactd){
                cond=1;
                break;
            }
        }
        posx=vx0;
        posy=vy0;
        if(cond == 1)
            break;

    }
    cond=0;
    for(t=2.5;t<1000;t++){
        vx=xd+posx*t;
        vy=yd+posy*t-(0.5*9.81*t*t);
        raiz=pow((xd-vx),2)+pow((xd-vy),2);
        if(sqrt(raiz)<impactd){
            cond=1;
            break;
        }
    }

    cout<<"Impacto Defensivo en el angulo "<<cop<<" Velocidad x0: "<<vx0<<" Velocidad y0: "<<vy0<<" Tiempo: "<<t+2.5<<endl;
    return 0;



}
