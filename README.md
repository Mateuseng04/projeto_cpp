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
// Funções de transformação
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
```

### - Funções
As funções da classe _Sculptor_ são métodos utilizados para a criação de formas geométricas  a partir de _voxels_. A seguir, um resumo das funções utilizadas neste projeto.

1 - `void PutVoxel(int x, int y, int z) ` : Este método modifica os _voxels_ da matriz tridimensional v[x][y][z], mudando seus atributos **rgb** e o atributo da solidez, alterando **IsOn** para **_true_**, e, portanto, deixando-o sólido. Possui o retorno vazio.

2 - ` void cutVoxel(int x, int y, int z) ` : Este método, assim como o anterior, modifica os _voxels_ da matriz v e altera os valores v[x][y][z], que correspondem às cores **rgb**. Também altera o atributo **IsOn** para _false_, tornando o sólido invisível. Possui o retorno vazio.

3 - ` void putBox(int x0, int x1, int y0, int y1, int z0) ` : Este método se encarrega de construir uma caixa (um prisma de base retangular) a partir das coordenas recebidas pelo programa, em vez de um único _voxel_. Utiliza a função _PutVoxel()_ para realizar esta construção. O retorno é vazio.

4 - ` void cutBox(int x0, int x1, int y0, int y1, int z0) ` :  Este método se encarrega de cortar caixas (prismas de base retangular), a partir das coordenadas recebidas, utilizando a funcção _cutVoxel()_. O retorno é vazio.

5 - ` putDisc(int xcenter, int ycenter, int zcenter, int r, int h, int axis = 1) ` : Este método se encarrega de desenhar um disco no canvas de desenho, a partir das coordenadas que o programa dispõe. O método utiliza a função _putVoxel()_. Vale ressaltar que, como os _voxels_ são quadriculados, não é possível desenhar um disco perfeito com este método. O retorno é vazio.

6 - ` cutDisc(int xcenter, int ycenter, int zcenter, int r, int h, int axis = 1) ` : Este método se encarrega de retirar um disco do canvas de desenho utilizando a função _cutVoxel()_. Vale salientar as imperfeições de se desenhar um disco com _voxels_ quadriculados. O retorno da função é vazio.

7 - `putSphere(int xcenter, int ycenter, int zcenter, int r) ` : Este método se encarrega de desenhar uma esfra no canvas de desenho, a partir das coordenas de centro, raio e utilizando a equação da esfera. O método utiliza a função _putVoxel()_ para criar o desenho do objeto. Vale ressaltar que não é possível desenhar uma esfera perfeita com _voxels_ quadrado. O retorno é vazio.

8 - `putSphere(int xcenter, int ycenter, int zcenter, int r) ` :
Este método tem a função de retirar uma esfera do canvas de desenho. Funciona de maneira análoga ao anterior, exceto que utiliza a função _cutVoxel()_. Vale fisar, novamenta, a impossibilidade de representar uma esfera perfeita com _voxels_ quadrados. O retorno é vazio.

9 - `putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)`: Este método é utilizado para desenhar um elipsóide, a representação 3D de uma elipse, a partir da função _putVoxel()_ e da equação computacional do eplipsóide. Não é possível uma representação perfeita de um elipsóide com _voxels_ quadrados. O retorno é vazio.

10 -`cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)`: Funciona de maneira análoga ao anterior, exceto que este funciona a partir da função _cutVoxel()_, como objetivo de remover um elipsóide do canvas de desenho, dado as coordenadas necessárias. O retono é vazio.
