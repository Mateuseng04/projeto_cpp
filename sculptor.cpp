#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>

struct Voxel {
    float r, g, b, a; // Colors
    bool isOn; // Included or not
};

class Sculptor {
private:
    Voxel ***v; // 3D matrix
    int nx, ny, nz; // Dimensions
    float r, g, b, a; // Current drawing color
public:
    Sculptor(int _nx, int _ny, int _nz);
    ~Sculptor();
    void setColor(float r, float g, float b, float a);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void writeOFF(const char* filename);
};

// Definitions
Sculptor::Sculptor(int _nx, int _ny, int _nz) {
    nx = _nx; ny = _ny; nz = _nz;
    r = g = b = a = 0.5;
    v = new Voxel**[nx];
    for (int i = 0; i < nx; i++) {
        v[i] = new Voxel*[ny];
        for (int j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];
        }
    }
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                v[i][j][k].isOn = false;
            }
        }
    }
}

Sculptor::~Sculptor() {
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            delete[] v[i][j];
        }
        delete[] v[i];
    }
}

void Sculptor::setColor(float r, float g, float b, float a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z) {
    if ((x >= 0 && x < nx) && (y >= 0 && y < ny) && (z >= 0 && z < nz)) {
        v[x][y][z].isOn = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z) {
    if ((x >= 0 && x < nx) && (y >= 0 && y < ny) && (z >= 0 && z < nz)) {
        v[x][y][z].isOn = false;
    }
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    for (int i = x0; i < x1; i++) {
        for (int j = y0; j < y1; j++) {
            for (int k = z0; k < z1; k++) {
                putVoxel(i, j, k);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    for (int i = x0; i < x1; i++) {
        for (int j = y0; j < y1; j++) {
            for (int k = z0; k < z1; k++) {
                cutVoxel(i, j, k);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if ((pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2)) <= pow(radius, 2)) {
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if ((pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2)) <= pow(radius, 2)) {
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if ((pow(i - xcenter, 2) / (float) (rx * rx)) + (pow(j - ycenter, 2) / (float) (ry * ry)) + (pow(k - zcenter, 2) / (float) (rz * rz)) <= 1) {
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if ((pow(i - xcenter, 2) / (float) (rx * rx)) + (pow(j - ycenter, 2) / (float) (ry * ry)) + (pow(k - zcenter, 2) / (float) (rz * rz)) <= 1) {
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename) {
    std::ofstream fout;
    fout.open(filename);
    if (!fout.is_open()) {
        exit(1);
    }

    fout << "OFF\n";

