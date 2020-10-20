#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
#define PI 3.14159265
bool impacto(int,int,int,int,int);
int trayectoriax(int,int,int,double,float);
int main()
{
    int d,xd,yd,xa=0,ya=0,opc;
    float gravedad=9.81,copt;
    d = 500;
    double angulo = 50.0;
    int impact = 0.05*d;
    xd = d;
    yd = 3;
    cout<<"1-Generar disparos (al menos tres) ofensivos que comprometan la integridad del cañón defensivo."<<endl;
    cout<<"2. Generar disparos (al menos tres) defensivos que comprometan la integridad del cañón ofensivo."<<endl;
    cout<<"3. Dado un disparo ofensivo, generar (al menos tres) disparos defensivos que impida que el cañón";
    cout<<"defensivo sea destruido sin importar si el cañón ofensivo pueda ser destruido"<<endl;
    cout<<"4. Dado un disparo ofensivo, generar (al emnos tres) disparo defensivos que impidan que los cañones defensivo y ofensivo puedan ser destruidos."<<endl;
    cout<<endl;
    cout<<"¿Que desea hacer?"<<endl;
    cin>>opc;
    switch(opc){

case 1:{
        cout<<"Generando 3 disparos efectivos"<<endl;
        for(int i = 0; i<3; i++){
            int o=trayectoriax(xd,yd,impact,angulo,gravedad);
            angulo+=2;
        }


    }
case 2:{
    }
case 3:{
    }
case 4:{
    }
 //-----------------
    }

return 0;
}
int trayectoriax(int xd,int yd,int impact,double angulo,float gravedad){
    int cop = angulo,cond=0;
    int vx,vy;
    bool sidio=false;
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

