#                 ESCULTOR 3D
## Descrição do Projeto

O projeto a seguir consiste em uma série de códigos para gerar figuras baseadas em cubos. O projeto foi inteiramente desenvolvido em C++, utilizando o paradigma de Programação Orientada a Objetos (POO). 

Além da linguagem de programação, também foram utilizadas aplicações que permitem a visualização da figura gerada, como o **geomiview** e o **meshlab**. Os softwares utilizados assim o foram pois são capazes de ler e interpretar arquivos .OFF, que são os tipos de arquivos utilizados para armazenar as figuras em C++.

Os arquivos .OFF são fundamentais para este tipo de projeto, pois permitem uma forma padronizada de se escrever e desenhar sólidos em 3D.


## Estrutura do código

O código deste projeto é fragmentado em três arquivos principais: main.cpp, sculptor.cpp e sculptor.h. No main, utilizamos os recursos da classe sculptor, a qual define as funções utilizadas que serão essenciais para o desenho da figura em 3D. E no cabeçalho sculptor.h, temos as definições dos parâmetros da classe. 

As esculturas 3D tratadas neste projeto são, basicamente, matrizes tridimensionais em que cada um de seus espações será preenchido por um _Voxel_, uma representação do espaço 3d tal qual o pixel é para o espaço 2D. O voxel pode assumir as cores vermelho (_red_), verde (_green_) ou azul (_blue_) e ser transparente o opaco. A definição do _Voxel_ é dada pelo seguinte código:

```cpp
struct Voxel {
   float r, g, b, a; // Cores
   bool isOn; // Incluído ou não
  };
```
Além da estrutura dos _Voxels_, também temos a classe Sculptor, que será responsável por um atributo da tela das esculturas, a matriz do tipo _voxel_. Além desse atributo, temos os métodos para desenhar formas geométricas, definir as cores e solidez do que será desenhado e outro método para salvar um arquivo do tipo .OFF. A seguir, o cabeçalho da classe.

```cpp
#ifndef SCULPTOR_H
#define SCULPTOR_H

class sculptor {
protected:

  int nx, ny, nz;
  float r, g, b, alpha;
public:

Voxel ***v; // Matriz 3d de voxels

Sculptor();
~Sculptor();	

void setColor(float r, float g, float b, float alpha);

//Funções de deseho
void putVoxel(int x, int y, int z);
void cutVoxel(int x, int y, int z);
// Fuções de transformação
void putBox(int x0, int x1, int y0, int y1, int z0);
void cutBox(int x0, int x1, int y0, int y1, int z0);
void putDisc(int xcenter, int ycenter, int zcenter, int r, int h, int axis = 1);
void cutDisc(int xcenter, int ycenter, int zcenter, int r, int h, int axis = 1);
void putSphere(int xcenter, int ycenter, int zcenter, int r);
void cutSphere(int xcenter, int ycenter, int zcenter, int r);
void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

// Método para salvar a escultura
void writeOFF(char *filename);
};

#endif // SCULPTOR_H
```cpp

