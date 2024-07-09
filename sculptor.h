#ifndef SCULPTOR_H
#define SCULPTOR_H

class Sculptor {
protected:

  int nx, ny, nz;
  float r, g, b, alpha;

public:

struct Voxel ***v;
// Matriz 3d de voxels

Sculptor(int nx_ = 1, int ny_ = 1, int nz_ = 1);
~Sculptor();	

void setColor(float r, float g, float b, float alpha);

//Funções de deseho
void putVoxel(int x, int y, int z);
void cutVoxel(int x, int y, int z);
// Fuções de transformação
void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
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