#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel {
    float r, g, b, a; // Cores
    bool isOn; // Incluído ou não
};

class Sculptor {
private:
    Voxel ***v; // matriz 3D
    int nx, ny, nz; // Dimensões
    float r, g, b, a; // cor do desenho atual
public:
    Sculptor(int _nx, int _ny, int _nz);
    ~Sculptor();
    
    void setColor(float r, float g, float b, float a);
    
    // Funções de desenho
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    
    // Funções de transformação
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    
    // Método para salvar a escultura
    void writeOFF(const char* filename);
};

#endif // SCULPTOR_H
