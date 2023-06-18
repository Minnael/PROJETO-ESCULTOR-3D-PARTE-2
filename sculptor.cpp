#include <iostream>
#include <fstream>
#include <math.h>
#include "sculptor.h"


//METODO CONSTRUTOR
Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;
    r = g = b = a = 0.5; //DEFININDO CORES/TRANSPARENCIA

    //ALOCAÇÃO DA MATRIZ 3D
    v = new Voxel**[nx];

    for(int i=0; i<nx; i++){
        v[i] = new Voxel*[ny];
    }

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            v[i][j] = new Voxel[nz];
        }
    }

    //PERCORRENDO A MATRIZ E DESATIVANDO OS VOXELS
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                v[i][j][k].show = false;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;

            }
        }
    }
}

//METODO DESTRUTOR
Sculptor::~Sculptor(){
    //LIBERANDO A MEMÓRIA
    //ETAPA 3
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            delete[] v[i][j];
        }
    }

    //ETAPA 2
    for(int i=0; i<nx; i++){
        delete[] v[i];
    }

    //ETAPA 1
    delete[] v;
    nx = ny = nz = 0;
}


//DEFININDO AS CORES
void Sculptor::setColor(float _r, float _g, float _b, float _a){
    r = _r;
    g = _g; //CORES BÁSICAS
    b = _b;
    a = _a; //TRANSPARENCIA
}

//ANIMANDO VOXEL POR POSIÇÃO
void Sculptor::putVoxel(int x, int y, int z){
   v[x][y][z].show = true;
   v[x][y][z].r = r;
   v[x][y][z].g = g;
   v[x][y][z].b = b;
   v[x][y][z].a = a;
}

//RETIRAR ANIMACAO DE VOXEL POR POSIÇÃO
void Sculptor::cutVoxel(int x, int y, int z){
   v[x][y][z].show = false;
}

//DEFININDO O METODO CRIADOR DO ARQUIVO OFF
void Sculptor::writeOFF(const char* filename){
   std::ofstream arquivo;

   fixed(arquivo);

   int nVertices = 0;
   int nFaces = 0;
   int contador = 0;

   arquivo.open(filename);

   if(!arquivo.is_open()){
        exit(1);
   }

   arquivo << "OFF" << std::endl;

   for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].show){
                    nFaces = nFaces + 6;
                    nVertices = nVertices + 8;
                }
            }
        }
   }

   arquivo << nVertices << " " << nFaces << " "<< "0" << std::endl;

   for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].show){
                    arquivo << (i-0.5) << " " << (j+0.5) << " " << (k-0.5) << std::endl;
                    arquivo << (i-0.5) << " " << (j-0.5) << " " << (k-0.5) << std::endl;
                    arquivo << (i+0.5) << " " << (j-0.5) << " " << (k-0.5) << std::endl;
                    arquivo << (i+0.5) << " " << (j+0.5) << " " << (k-0.5) << std::endl;
                    arquivo << (i-0.5) << " " << (j+0.5) << " " << (k+0.5) << std::endl;
                    arquivo << (i-0.5) << " " << (j-0.5) << " " << (k+0.5) << std::endl;
                    arquivo << (i+0.5) << " " << (j-0.5) << " " << (k+0.5) << std::endl;
                    arquivo << (i+0.5) << " " << (j+0.5) << " " << (k+0.5) << std::endl;
                }
            }
        }
   }

   for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].show){
                    arquivo<<4<<" "<<(0+contador)<<" "<<(3+contador)<<" "<<(2+contador)<<" "<<(1 + contador)<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
                    arquivo<<4<<" "<<(4+contador)<<" "<<(5+contador)<<" "<<(6+contador)<<" "<<(7 + contador)<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
                    arquivo<<4<<" "<<(0+contador)<<" "<<(1+contador)<<" "<<(5+contador)<<" "<<(4 + contador)<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
                    arquivo<<4<<" "<<(0+contador)<<" "<<(4+contador)<<" "<<(7+contador)<<" "<<(3 + contador)<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
                    arquivo<<4<<" "<<(3+contador)<<" "<<(7+contador)<<" "<<(6+contador)<<" "<<(2 + contador)<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
                    arquivo<<4<<" "<<(1+contador)<<" "<<(2+contador)<<" "<<(6+contador)<<" "<<(5 + contador)<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
                    contador = contador + 8;

                }
            }
        }
   }

   arquivo.close();

}







