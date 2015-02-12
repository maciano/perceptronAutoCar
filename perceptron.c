#include <stdio.h>
#include <conio.h>
#include <iostream.h>

double recta(double,double,double);
double min(double y1,double y2);
void mostrar(void);

double MatrizValores[5][4]={0};
double presion;
int vd[5][4];

int main()
{
  int Dist=10;
  int Veloc=10;
  double PRESIONF;
  double Emu;
// Cargamos el cuadro de relaciones

  int vd[5][4]={0};

  //sin presion
  vd[0][0]=1;
  vd[1][0]=1;
  vd[2][0]=1;
  vd[3][0]=1;
  vd[3][1]=1;
  vd[4][0]=1;
  vd[4][1]=1;
  //presion media
  vd[0][1]=45;
  vd[3][2]=45;              // 0 = sin presion
  vd[3][3]=45;              // 1 = presion ligera
  //presion ligera        // 2 = presion media
  vd[1][1]=15;              // 3 = presion fuerte
  vd[2][1]=15;
  vd[4][2]=15;
  vd[4][3]=15;
  //presion fuerte
  vd[0][2]=80;
  vd[1][2]=80;
  vd[2][2]=80;
  vd[0][3]=80;
  vd[1][3]=80;
  vd[2][3]=80;

  cout<<"Ingrese Distancia: ";
  cin>>Dist;
  cout<<"Ingrese Velocidad: ";
  cin>>Veloc;


  //////// VELOCIDAD
  double ValorV[2]={0};
  int  act=0;
  int Vj=0;                    /// solo nos interesa saber la posicion del primer cuadro ya que los demas son vecinos
      
    if (Veloc >=0 && Veloc < 2) {
                    //***** DETENIDO ****;
        int x11=0;
        int x12=2;
            ValorV[act]=1;
        cout<<"\nEntro en DETENIDO ";
                cout<<"VEloc="<<Veloc;
        Vj=0;
        act++;
                getch();
    }
        if(Veloc>0 && Veloc<10) {
                    //***** LENTO *****;
        int x21=0;
        int x22=5;
        ValorV[act]=recta(x21,x22,Veloc);
        cout<<"\nEntro en LENTO ";
        cout<<"\nFC= "<<ValorV[act];
        Vj=1;
                act++;
        }
    if(Veloc>5 && Veloc<30) {
                    //***** BASTANTERAPIDO *****;
        int x31=5;
        double x32=17.5;
                ValorV[act]=recta(x31,x32,Veloc);
        cout<<"\nEntro en BASTANTERAPIDO";
        cout<<"nFC= "<<ValorV[act];
        Vj=2;
                act++;
        }
    if (Veloc>25 && Veloc<37.5) {

                    //***** MuyRapido ******;
                int x41=25;
        double x42=37.5;
        ValorV[act]=recta(x41,x42,Veloc);
        cout<<"\nEntro en MUY RAPIDO ";
        cout<<"\nFC= "<<ValorV[act];
        Vj=3;
        act++;
        }
    if(Veloc>=37.5) {
                    //****** MuyRapido2 ************

        ValorV[act]=1;
        cout<<"\nEntro en MUY RAPIDO CONSTANTE ";
        Vj=3;
    }
    


  //////// DISTANCIA
    double ValorD[2]={0};
    int act2=0;
    int Ei=0;
    if(Dist>=0 && Dist<2){
        //********* EN ************;
        int x11=0;
        int x12=2;
        ValorD[act2]=1;
        cout<<"\nEntro en EN ";
        cout<<"\nFC= "<<ValorD[act2];
                Ei=0;
                act2++;
    }
    if(Dist>0 && Dist<10) {
            //***** MUY CERCA *********;
        int x21=0;
        int x22=5;
        ValorD[act2]=recta(x21,x22,Veloc);
        cout<<"\nEntro en MUY CERCA ";
        cout<<"\nFC= "<<ValorD[act2];
        Ei=1;

                act2++;
    }
    if (Dist>5 && Dist<30) {
        //***** CERCA *************;
        int x31=5;
        double x32=17.5;
                ValorD[act2]=recta(x31,x32,Veloc);
        cout<<"\nEntro en CERCA ";
        cout<<"\nFC= "<<ValorD[act2];
                Ei=2;
                act2++;
    }
    if(Dist>20 && Dist<40) {
        //***** BASTANTE LEJOS ****;
        int x41=20;
        int x42=30;
        ValorD[act2]=recta(x41,x42,Veloc);
              cout<<"\nEntro en BASTANTE LEJOS ";
        cout<<"\nFC= "<<ValorD[act2];
                Ei=3;
                act2++;
    }
    if(Dist>30 && Dist<40){
        //***** LEJOS ************;
        int x51=30;
                int x52=40;
        ValorD[act2]=recta(x51,x52,Veloc);
        cout<<"\nEntro en LEJOS ";
        cout<<"\nFC= "<<ValorD[act2];
                Ei=4;
            act2++;
    }
    if(Dist>=40){
        //***** lejos constante *****
        ValorD[act2]=1;
                Ei=4;

          }
      
      getch();

  
// *************  Cálculo de la Presion *****************************************

for(int i=0;i<2;i++)
    for(int j=0;j<2;j++){
        cout<<"\nEi="<<Ei<<" i="<<i<<" j="<<j<<" Vj="<<Vj<<endl;
        MatrizValores[Ei+i][Vj+j]=min(ValorD[i],ValorV[j]);
        }
mostrar();

getch();
for (i=0;i<5;i++)
    for(int j=0;j<4;j++){  //hacemos el producto de la presion media en la zona y el valor minimo que seleccionamos

        presion+=MatrizValores[i][j]*vd[i][j];
        
        cout<<"\nvd="<<vd[i][j];
        cout<<" * "<<MatrizValores[i][j];
        
        }
for (i=0;i<5;i++)
    for(int j=0;j<4;j++)
    Emu+=MatrizValores[i][j];
cout<<"\n Emu="<<Emu;
getch();

PRESIONF=presion/Emu;
cout<<"\La Presion debe ser="<<PRESIONF<<"%";


//********************************************************************************



return 0;
}


double recta(double x1, double x2, double var)
{
  if (var>x2) var=(2*x2)-var; // Como son simétricas las rectas adaptamos la segunda a la primera ( / \ ).
  return((var-x1)/(x2-x1)); //Ecuación de la recta conocidos dos puntos.

}

double min(double y1,double y2)
{
  if (y1<y2)
    return y1;
  else
      return y2;
}

void mostrar()
{
for (int i=0;i<5;i++)
    for(int j=0;j<4;j++)  //hacemos el producto de la presion media en la zona y el valor minimo que seleccionamos
        cout<<" "<<MatrizValores[i][j];

}
