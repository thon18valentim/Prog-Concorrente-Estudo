#include <iostream>

enum moedas { dolar, euro, peso_argentino };
int area_retangulo(int altura, int largura);
double converter_moeda(double valor_original, moedas moeda_destino);
void compara_numeros(int a, int b);
double media(int vet[], int tamanho);
int mediana(int vet[], int tamanho);
int moda(int vet[], int tamanho);

class Complex {

private:
    float real;
    float img;

public: Complex(float num, float num2) : real{ num }, img{ num2 } {}

      friend bool operator==(const Complex& cpl1, const Complex& cpl2) {
          return cpl1.real == cpl2.real && cpl1.img == cpl2.img;
      }

      friend bool operator!=(const Complex& cpl1, const Complex& cpl2) {
          return cpl1.real != cpl2.real || cpl1.img != cpl2.img;
      }

      friend Complex operator+(const Complex& cpl1, const Complex& cpl2) {
          return Complex(cpl1.real + cpl2.real, cpl1.img + cpl2.img);
      }

      friend Complex operator-(const Complex& cpl1, const Complex& cpl2) {
          return Complex(cpl1.real - cpl2.real, cpl1.img - cpl2.img);
      }

      friend Complex operator*(const Complex& cpl1, const Complex& cpl2) {
          return Complex((cpl1.real * cpl2.real) + (cpl1.img * cpl1.img * -1), (cpl1.real * cpl2.img) + (cpl1.img * cpl2.real));
      }

      friend Complex operator/(const Complex& cpl1, const Complex& cpl2) {
          float parte_real_numerador = (cpl1.real * cpl2.real) + (cpl1.img * (cpl2.img * -1) * -1);
          float parte_img_numerador = (cpl1.real * (cpl2.img * -1)) + (cpl1.img * cpl2.real);
          float denominador = (cpl2.real * cpl2.real) + (cpl2.img * (cpl2.img * -1) * -1);
          return Complex(parte_real_numerador / denominador, parte_img_numerador / denominador);
      }

      float get_re() {
          return real;
      }

      float get_img() {
          return img;
      }
};

using namespace std;
int main()
{
    /*std::cout << "Hello World!\n";
    int vet[6] = { 1, 1, 1, 2, 2, 2 };
    std::cout << moda(vet, 6);*/

    Complex x{ 3.0, 1.5 };
    Complex y{ 2.1, 4.9 };
    Complex z{ 0.0, 0.0 };
    
    z = x + y;
    std::cout << z.get_re() << " , " << z.get_img() << "\n";
    z = x - y;
    std::cout << z.get_re() << " , " << z.get_img() << "\n";
    z = x * y;
    std::cout << z.get_re() << " , " << z.get_img() << "\n";
    z = x / z;
}

int area_retangulo(int altura, int largura) {
    return altura * largura;
}

double converter_moeda(double valor_original, moedas m) {
    switch (m)
    {
    case dolar:
        return valor_original / 5.17;
    case euro:
        return valor_original / 6.14;
    default:
        return valor_original / 0.05;
    }
}

void compara_numeros(int a, int b) {
    if (a > b) {
        std::cout << a << " e maior que " << b;
    }
    else if (b > a) {
        std::cout << b << " e maior que " << a;
    }
    else {
        std::cout << "Os valores passados sao iguais";
    }
}

double media(int vet[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vet[i];
    }
    return (double) soma / tamanho;
}

int mediana(int vet[], int tamanho) {
    int size = tamanho - 1;
    if (size % 2 == 0) {
        int i = vet[(size) / 2];
        int j = vet[(size) / 2 + 1];
        return (i + j) / 2;
    }
    else {
        return vet[(size) / 2];
    }
}

int moda(int vet[], int tamanho) {
    int *cont;
    int conta = 0, moda;

    cont = (int*)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; ++i) {
        cont[i] = 0;
    }

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (vet[i] == vet[j]) {
                cont[i] += 1;
                if (cont[i] > conta) {
                    conta = cont[i];
                    moda = vet[i];
                }
            }
        }
        cont[i] = 0;
    }
    free(cont);
    if (conta == 0) {
        return -1;
    }
    else {
        return moda;
    }
}
