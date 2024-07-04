#include <iostream>
#include "sculptor.h" // Inclua o arquivo da classe Sculptor

int main(void) {
    Sculptor joao(200, 200, 200);

    joao.setColor(0, 0, 1, 1);
    joao.putVoxel(10, 10, 10);
    joao.putBox(50, 51, 40, 41, 40, 41); // Os valores de x1, y1, z1 devem ser maiores que x0, y0, z0
    joao.cutBox(50, 51, 40, 41, 40, 41);
    joao.putSphere(50, 50, 50, 20); // Corrigido o valor do raio
    joao.cutSphere(50, 50, 50, 20);
    joao.putEllipsoid(50, 50, 50, 20, 30, 40); // Corrigido os valores dos raios
    joao.cutEllipsoid(50, 50, 50, 20, 30, 40);

    joao.writeOFF((char*) "C:/este computador/dowloads/joao.off");

    return 0;
}
