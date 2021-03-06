/*
  Accepted
 */
#include <stdio.h>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct item{
 int i, w, d;
 item(int I, int W, int D) : i(I), w(W), d(D) {}

 bool operator < (const item &that) const {
   return w > that.w;
 }
};


int main(){
 int r, c, i, j, w, C = 1;
 while (scanf("%d %d", &r, &c) && r + c){
   int start, end;
   scanf("%d %d", &i, &j); --i, --j;
   start = i*c + j;
   scanf("%d %d", &i, &j); --i, --j;
   end = i*c + j;

   //printf("Start y end son: %d %d\n", start, end);

   //g[3] contiene la lista de vecinos del nodo 3 (El primer nodo es el 0!)
   //Cada vector de vecinos tiene cuatro elementos: abajo, izquierda, arriba, derecha = 0, 1, 2, 3
   //cada vecino es una pareja de enteros donde "first" es la distancia del viaje
   //y "second" es el nodo de destino (-1 si está fuera del tablero).
   vector<vector<pair<int, int> > > g(r*c, vector<pair<int, int> >(4, make_pair(0, -1)));

   for (i = 0; i<r; ++i){
     for (j = 0; j < c - 1; ++j){ //Horizontales
       scanf("%d", &w);
       g[i*c + j][3] = make_pair(w, i*c + j + 1);
       g[i*c + j + 1][1] = make_pair(w, i*c + j);
     }

     for (j = 0; j < c && (i+1)*c + j < r*c; ++j){
       scanf("%d", &w);
       g[i*c + j][0] = make_pair(w, (i+1)*c + j);
       g[(i+1)*c + j][2] = make_pair(w, i*c + j);
     }
   }

   int d[r*c][5];
   for (i=0; i<r*c; ++i)
     for (j=0; j<5; ++j)
       d[i][j] = INT_MAX;

   d[start][4] = 0;

   priority_queue<item> q;
   q.push(item(start, 0, 4)); //4 = any direction

   while (!q.empty()){
     item top = q.top(); q.pop();

     //printf("Saque item: i = %d, w = %d, d = %d\n", top.i, top.w, top.d);

     if (top.w > d[top.i][top.d]) continue;

     if (top.d == 4){
       for (int dir=0; dir<4; ++dir){
         if (g[top.i][dir].first != 0){ //es un vecino válido
           int j = g[top.i][dir].second;

           if (top.w + 2*g[top.i][dir].first < d[j][dir]){
             d[j][dir] = top.w + 2*g[top.i][dir].first;
             q.push(item(j, d[j][dir], dir));
           }

           if(top.w + 2*g[top.i][dir].first < d[j][4]){
             d[j][4] = top.w + 2*g[top.i][dir].first;
             q.push(item(j, d[j][4], 4));
           }
         }
       }
     }else{
       if (g[top.i][top.d].first != 0){
         int j = g[top.i][top.d].second;

         if (top.w + g[top.i][top.d].first < d[j][top.d]){
           d[j][top.d] = top.w + g[top.i][top.d].first;
           q.push(item(j, d[j][top.d], top.d));
         }

         if (top.w + 2*g[top.i][top.d].first < d[j][4]){
           d[j][4] = top.w + 2*g[top.i][top.d].first;
           q.push(item(j, d[j][4], 4));

         }
       }
     }

   }

   //Ya el grafo está leído.
   printf("Case %d: ", C++);
   if (d[end][4] < INT_MAX)
     printf("%d", d[end][4]);
   else
     printf("Impossible");
   printf("\n");
 }
 return 0;
}
