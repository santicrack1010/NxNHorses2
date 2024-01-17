#include "misc.hpp"

using namespace std;

int boardSize;
int maxHorses;  
vector<vector<int>> board;
vector<vector<vector<int>>> solution;

void backtracking(int, int);

int main() {
  cout << "Ingrese el tamano del tablero: " << endl;
  cin >> boardSize;

  maxHorses = ceil(boardSize * boardSize / 2.0); // Obtener el maximo de caballos
  board = vector<vector<int>>(boardSize, vector<int>(boardSize, 0));  // Rellenar tablero con ceros
  ofstream archivoSalida(nameFile(boardSize)); // Crear archivo de salida

  backtracking(0, 0); // Llamada a funcion para obtencion de resultados

  archivoSalida << maxHorses << endl // Guardar Maximo de caballos por solucion
                << solution.size() << endl // Guardar la cantidad de soluciones
                << solutionToString(boardSize, solution); // Guardar las soluciones

  archivoSalida.close();
}

void backtracking(int n, int pos) {
  if (n == maxHorses) { // Si no alcanzamos ese maximo, no es una solucion
    solution.push_back(board); // Guardar solucion
    return;
  }
  for (int i = pos; i < boardSize * boardSize; i++) { // Recorrer desde la posicion actual
    int row = i / boardSize; // Incrementos de Fila
    int col = i % boardSize; // Imcrementos de Columna

    if (isSecPos(row, col, boardSize, board)) { // Si es una posicion segura
      board[row][col] = 1; // Colocar 1 en tablero que indica un caballo colocado
      backtracking(n + 1, i + 1); // Llamada recursiva contemplando el caballo ya elegido e incrementando la posicion
      board[row][col] = 0; // Si se regresa, quita el ultimo caballo e intenta con una nueva posicion
    }
  }
}