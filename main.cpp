#include <iostream>
#include <vector>
using namespace std;

// clase 0
class Punto {
public:
  int x;
  int y;
// constructor vacío
  Punto() {
    x = 0;
    y = 0;
  }
// constructor con parametros
  Punto(int x1, int y1) {
    x = x1;
    y = y1;
  }
};
// clase 1
class Forma {
private:
  string color;
  Punto *cordenadaCentro;
  string nombreForma;

public:
  // constructor de forma
  Forma(string colors, Punto *corCentro, string nameForma) {
    color = colors;
    cordenadaCentro = corCentro;
    nombreForma = nameForma;
  }
// retorna los valores de cordenada como string
  string getCoordenadaCentro() {
    string coord;
    coord += std::to_string(this->cordenadaCentro->x);
    coord += ",";
    coord += std::to_string(this->cordenadaCentro->y);
    return coord;
  }
// funcion que muestra por pantalla que tiene una forma
  void imprimir() {
    cout << "forma: " << this->nombreForma << endl;
    cout << "centro: " << this->getCoordenadaCentro() << endl;
    cout << "color: " << this->color << endl;
    cout << endl;
  };
  // funcion cambiar color
  void setColor(string colorNuevo) { this->color = colorNuevo; }
  // funcion obtener color
  string getColor() { return this->color; }
  // funcion mover el centro de la forma

  string getNombreForma() { return this->nombreForma; }

// le suma o le resta valor a las coordenadas
  void moverForma(int x1, int y1){
    this->cordenadaCentro->x += x1;
    this->cordenadaCentro->y += y1;
  };
};
// clase 2
class Rectangulo : public Forma {
private:
  int ladoMenor;
  int ladoMayor;

public:
  // constructor rectangulo
  Rectangulo(string colors, Punto *corCentro, string nameForma, int ladoJunior,
             int ladoSenior)
      : Forma(colors, corCentro, nameForma) {
    ladoMenor = ladoJunior;
    ladoMayor = ladoSenior;
  }
// función que imprime un rectangulo (en este caso)
  void imprimir() {
    cout << "forma: " << this->getNombreForma() << endl;
    cout << "ladoMenor: " << this->ladoMenor << endl;
    cout << "ladoMayor: " << this->ladoMayor << endl;
    cout << "centro: " << this->getCoordenadaCentro() << endl;
    cout << "color: " << this->getColor() << endl;
    cout << endl;
  }
  int calcularArea() { return this->ladoMenor * this->ladoMayor; }
  int calcularPerimetro() { return 2 * this->ladoMenor + 2 * this->ladoMayor; }
  void tamañoFigura();
};
// clase 3
class Elipse : public Forma {
private:
  int radioMayor;
  int radioMenor;
  // constructor eclipse
public:
  Elipse(string colors, Punto *corCentro, string nameForma, int R, int r)
      : Forma(colors, corCentro, nameForma) {
    radioMayor = R;
    radioMenor = r;
  }
};
// clase 4
class Cuadrado : public Rectangulo {
public:
  Cuadrado(string colors, Punto *corCentro, string nameForma, int lado)
      : Rectangulo(colors, corCentro, nameForma, lado, lado) {}
};
// clase 5
class Circulo : public Elipse {
public:
  Circulo(string colors, Punto *corCentro, string nameForma, int R)
      : Elipse(colors, corCentro, nameForma, R, R) {}
};

int main() {
  // definición de vector (arreglo) de formas
  vector<Forma *> formas;
  formas.push_back(new Rectangulo("Rojo", new Punto(4, 6), "Rectángulo", 2, 4));
  formas.push_back(new Cuadrado("Rojo", new Punto(5, 9), "Cuadrado", 2));
  formas.push_back(new Elipse("Rojo", new Punto(2, 6), "Elipse", 2, 4));
  formas.push_back(new Circulo("Amarillo", new Punto(2, 2), "Círculo", 4));

  cout << "------------------------" << endl;
  cout << "FORMAS INICIALES: " << endl;
  cout << endl;
  // Bucle que recorre el listado de formas y las imprime
  for (int i = 0; i < formas.size(); i++) {
    formas[i]->imprimir();
  }
// Bucle que recorre el listado de formas y les cambia el color y mueve la coordenada
  for (int i = 0; i < formas.size(); i++) {
    formas[i]->setColor("Verde");
    formas[i]->moverForma(1, 2);
  }

  cout << "------------------------" << endl;
  cout << "FORMAS ALTERADAS: " << endl;
  cout << endl;
// Bucle que recorre el listado de formas y las imprime
  for (int i = 0; i < formas.size(); i++) {
    formas[i]->imprimir();
  }

  return 0;
}
