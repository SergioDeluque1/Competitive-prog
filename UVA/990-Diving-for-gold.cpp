#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Tesoro {
    int profundidad;
    int oro;
    int indice;
};

int t, w, n;
vector<Tesoro> tesoros;
int dp[31][1001];
bool tomado[31][1001];

int calcularTiempo(int profundidad) {
    return w * profundidad + 2 * w * profundidad;
}

int resolver(int idx, int tiempoRestante) {
    if (idx == n || tiempoRestante <= 0) {
        return 0;
    }
    
    if (dp[idx][tiempoRestante] != -1) {
        return dp[idx][tiempoRestante];
    }
    
    
    int noTomar = resolver(idx + 1, tiempoRestante);
    
    
    int tiempoNecesario = calcularTiempo(tesoros[idx].profundidad);
    int tomar = 0;
    
    if (tiempoNecesario <= tiempoRestante) {
        tomar = tesoros[idx].oro + resolver(idx + 1, tiempoRestante - tiempoNecesario);
    }
    
    if (tomar > noTomar) {
        tomado[idx][tiempoRestante] = true;
        dp[idx][tiempoRestante] = tomar;
    } else {
        tomado[idx][tiempoRestante] = false;
        dp[idx][tiempoRestante] = noTomar;
    }
    
    return dp[idx][tiempoRestante];
}

void reconstruirSolucion(vector<int>& seleccionados) {
    int tiempoRestante = t;
    
    for (int i = 0; i < n; i++) {
        if (tomado[i][tiempoRestante]) {
            seleccionados.push_back(i);
            tiempoRestante -= calcularTiempo(tesoros[i].profundidad);
        }
    }
}

int main() {
    bool primerCaso = true;
    
    while (cin >> t >> w) {
        cin >> n;
        
        tesoros.clear();
        tesoros.resize(n);
        
        for (int i = 0; i < n; i++) {
            cin >> tesoros[i].profundidad >> tesoros[i].oro;
            tesoros[i].indice = i;
        }
        
        // Inicializar DP
        memset(dp, -1, sizeof(dp));
        memset(tomado, false, sizeof(tomado));
        
        // Resolver
        int oroMaximo = resolver(0, t);
        
        // Reconstruir solución
        vector<int> seleccionados;
        reconstruirSolucion(seleccionados);
        
        // Imprimir resultados
        if (!primerCaso) {
            cout << endl;
        }
        primerCaso = false;
        
        cout << oroMaximo << endl;
        cout << seleccionados.size() << endl;
        
        for (int idx : seleccionados) {
            cout << tesoros[idx].profundidad << " " << tesoros[idx].oro << endl;
        }
    }
    
    return 0;
}