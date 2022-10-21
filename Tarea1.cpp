//La clase Forma y Punto tienen una relacion de composicion
#include <iostream>
#include <cstring>
using namespace std;
class Punto
{
private:
    int x;
    int y;
public:
    //Constructor
    Punto(int = 0, int = 0);
    void setPuntoX(int);
    void setPuntoY(int);
    int getPuntoX();
    int getPuntoY();
    void Cambiar(int,int);
};

class Forma {
private:
    string Color;
    char nombre[30];
    Punto coordenada;//Objeto de la clase Punto
public:
    //Constructor, recibe un puntero a una cadena para establecer el nombre de la forma y una referencia constante a un objeto Punto
    //para establecer las coordenadas
    Forma(string , const char *, const Punto &);
    void setNombre(const char *);
    void setCoord(int,int);
    void setColor(string color);
    string getColor();
    void imprimir();
    void Mover(int,int);
    void ObtenerCambiarColor();
};

class Rectangulo: public Forma{
private:
    double LadoA;
    double LadoB;
public:
    //Constructor
    Rectangulo(string , const char *, const Punto &,double,double);
    void setLadoA(double);
    void setLadoB(double);
    double getLadoB();
    double getLadoA();
    void Imprimir();
    void Area();
    void Perimetro();
    void CambiarTamanio(double);
};

class Elipse: public Forma{
private:
    double RadioA;
    double RadioB;
public:
    //Constructor
    Elipse(string , const char *, const Punto &,double,double);
    void setRadioA(double);
    void setRadioB(double);
    double getRadioA();
    double getRadioB();
    void IMPRIMIR();
    void AREA();
};

class Cuadrado: public Rectangulo{

public:
    //Constructor
    Cuadrado(string , const char *, const Punto &,double,double);
};

class Circulo: public Elipse{
private:
    double radio;
public:
    //Constructor
    Circulo(string , const char *, const Punto &,double,double);
    void PERIMETRO();
};

//METODOS DE LA CLASE Punto
Punto::Punto(int enX, int enY){
    setPuntoX(enX);
    setPuntoY(enY);
}

void Punto::setPuntoX(int enX){
    x= enX;
}
void Punto::setPuntoY(int enY){
    y= enY;
}
int Punto::getPuntoX(){
    return x;
}
int Punto::getPuntoY(){
    return y;
}

void Punto::Cambiar(int _x,int _y){
    x=_x;
    y=_y;
}

//METODOS DE LA CLASE Forma
Forma::Forma(string color, const char *Nombre, const Punto & CORDE) : coordenada(CORDE){ //inicializador de miembros.
    setNombre(Nombre);
    Color=color;
}
void Forma::setNombre(const char *nombreForma){
    int cantLetras = strlen(nombreForma);
    if (cantLetras > 30){
        cantLetras = 30;
    }
    strncpy(nombre,nombreForma,cantLetras);
    nombre[cantLetras + 1] = '\0';
}
void Forma::setCoord(int enX, int enY){
    coordenada.setPuntoX(enX);
    coordenada.setPuntoY(enY);
}

void Forma::setColor(string color){
    Color=color;
}

string Forma::getColor(){
    return Color;
}

void Forma::Mover(int _x,int _y){
    coordenada.setPuntoX(_x);
    coordenada.setPuntoY(_y);
}

void Forma::ObtenerCambiarColor(){
    int i;
    string colores[]={"rosado","verde","morado","rojo","azul","negro","blanco","amarillo"};
    cout<<"Los colores disponibles son: "<<endl;
    for(i=0;i<8;i++){
        cout<<colores[i]<<endl;
    }
    cout<<"Ingrese el color que desea obtener: "<<endl;
    cin>>Color;
}


void Forma::imprimir(){
    cout << "Forma: "<< nombre << endl;
    cout << "Coordenadas: (" << coordenada.getPuntoX() << "," << coordenada.getPuntoY() << ")"<<endl;
    cout<<"Color: "<<Color<<endl;
    cout << endl;
}

//METODOS DE LA CLASE Rectangulo
Rectangulo::Rectangulo(string color, const char *Nombre, const Punto & CORDE,double ladoA, double ladoB) : Forma(color,Nombre,CORDE){
    LadoA=ladoA;
    LadoB=ladoB;
}

void Rectangulo::setLadoA(double ladoA){LadoA=ladoA;}

void Rectangulo::setLadoB(double ladoB){LadoB=ladoB;}

double Rectangulo::getLadoA(){return LadoA;}

double Rectangulo::getLadoB(){return LadoB;}

void Rectangulo::Imprimir(){
    cout<<"Lado A: "<<LadoA<<endl;
    cout<<"Lado B: "<<LadoB<<"\n";
    imprimir();
}
void Rectangulo::Area(){
    double area=0;
    area=LadoA*LadoB;
    cout<<"Area: "<<area<<endl;
}
void Rectangulo::Perimetro(){
    double perimetro=0;
    perimetro=(2*LadoA)+(2*LadoB);
    cout<<"Perimetro: "<<perimetro<<endl;
}
void Rectangulo::CambiarTamanio(double escala){
    double tamanio=0;
    tamanio=(2*LadoA)+(2*LadoB);
    tamanio=tamanio*escala;
    cout<<"Factor de Escala: "<<escala<<endl;
    cout<<"Tamanio: "<<tamanio<<endl;

}
//METODOS DE LA CLASE Elipse
Elipse::Elipse(string color, const char *Nombre, const Punto & CORDE,double radioA, double radioB) : Forma(color,Nombre,CORDE){
    RadioA=radioA;
    RadioB=radioB;
}
void Elipse::setRadioA(double radioA){RadioA=radioA;}
void Elipse::setRadioB(double radioB){RadioB=radioB;}
double Elipse::getRadioA(){return RadioA;}
double Elipse::getRadioB(){return RadioB;}
void Elipse::IMPRIMIR(){
    cout<<"Radio A: "<<RadioA<<endl;
    cout<<"Radio B: "<<RadioB<<"\n";
    imprimir();
}
void Elipse::AREA(){
    double pi=3.14;
    double area=0;
    area=pi*(RadioA*RadioB);
    cout<<"Area: "<<area<<endl;
}
//METODOS DE LA CLASE Cuadrado
Cuadrado::Cuadrado(string color, const char *Nombre, const Punto & CORDE,double ladoA, double ladoB) : Rectangulo(color,Nombre,CORDE,ladoA,ladoB) {

}
//METODOS DE LA CLASE Circulo
Circulo::Circulo(string color, const char *Nombre, const Punto & CORDE,double radioA, double radioB) : Elipse(color,Nombre,CORDE,radioA,radioB){
}
void Circulo::PERIMETRO(){
    double pi=3.14;
    double perimetro=0;
    perimetro=2*pi*getRadioA();
    cout<<"Perimetro: "<<perimetro<<endl;
}
int main(){
    Punto A(5,10);
    Punto B(15,25);
    Punto C(30,35);
    Punto D(40,45);
    //PRUEBAS DE OBJETOS DE CADA CLASE
    //Objeto tipo Forma
    Forma objetoF1("verde","elipse",A);
    cout << "Objeto Forma : "<< endl;
    objetoF1.imprimir();
    objetoF1.Mover(2,3);
    objetoF1.ObtenerCambiarColor();
    cout<<"\nDespues de mover el centro de la forma y cambiar color : "<<endl;
    objetoF1.imprimir();
    cout<<"\n***************************************************************************"<<endl;
    cout<<"Objeto Rectangulo : "<<endl;
    Rectangulo ObjetoR1("rosado","rectangulo",B,3,5);
    ObjetoR1.Imprimir();
    ObjetoR1.Area();
    ObjetoR1.Perimetro();
    ObjetoR1.CambiarTamanio(0.5);
    ObjetoR1.Mover(9,10); //Metodo heredado de Forma
    ObjetoR1.ObtenerCambiarColor(); //metodo heredado de Forma
    cout<<"\nDespues de mover el centro de la forma y cambiar color : "<<endl;
    ObjetoR1.imprimir(); //metodo heredado de Forma
    cout<<"\n***************************************************************************"<<endl;
    cout<<"Objeto Elipse : "<<endl;
    Elipse objetoE1("morado","Elipse",C,7,9);
    objetoE1.IMPRIMIR();
    objetoE1.AREA();
    objetoE1.Mover(11,22);//Metodo heredado de Forma
    objetoE1.ObtenerCambiarColor();//Metodo heredado de Forma
    cout<<"\nDespues de mover el centro de la forma y cambiar color : "<<endl;
    objetoE1.imprimir();//Metodo heredado de Forma
    cout<<"\n***************************************************************************"<<endl;
    cout<<"Objeto Cuadrado : "<<endl;
    Cuadrado objetoCuadrado("verde","Cuadrado",A,5.5,5.5);
    objetoCuadrado.imprimir();
    objetoCuadrado.Area();
    objetoCuadrado.Perimetro();
    objetoCuadrado.Mover(66,99);
    objetoCuadrado.ObtenerCambiarColor();
    objetoCuadrado.imprimir();
    cout<<"\n***************************************************************************"<<endl;
    cout<<"Objeto Circulo : "<<endl;
    Circulo objetoCirculo("amarillo","Circulo",B,23,23);
    objetoCirculo.AREA();
    objetoCirculo.PERIMETRO();
    objetoCirculo.imprimir();
    cout<<"\n***************************************************************************"<<endl;
    cout<<"Vector de Punteros de clase Forma que apunta a objetos creados"<<endl;
    Forma OBJETO1("verde","Rectangulo",A);
    Forma OBJETO2("morado","Elipse",B);
    Forma OBJETO3("rosado","Cuadrado",C);
    Forma OBJETO4("azul","Circulo",D);

    Forma *arreglo[4];

    arreglo[0]=&OBJETO1;
    arreglo[1]=&OBJETO2;
    arreglo[2]=&OBJETO3;
    arreglo[3]=&OBJETO4;

    for(int i=0;i<4;i++){
        arreglo[i]->ObtenerCambiarColor();
        arreglo[i]->Mover(50,60);
        cout<<endl;
    }
    for(int i=0;i<4;i++){
        arreglo[i]->imprimir();
        cout<<endl;
    }
    return 0;
}

