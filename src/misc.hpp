#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

string nameFile(int boardSize){ // Regresa el nombre del archivo
    string s = "Caballos" + (boardSize < 10 ? "0" + to_string(boardSize) : to_string(boardSize)) + ".txt";
    return s;
}

bool isSecPos(int row, int col, int boardSize, vector<vector<int>> board) { // Devuelve si es o no una posicion segura
  static int x[8] = {-2, -1, 1, 2, -2, -1, 1, 2}; // Movimientos en x posibles para un caballo
  static int y[8] = {-1, -2, -2, -1, 1, 2, 2, 1}; // Movimientos en y posibles para un caballo

  for (int i = 0; i < 8; i++) { // Evaluar los 8 posibles movimientos
    int newRow = row + x[i], newCol = col + y[i]; // Incrementar a las posiciones actuales los posibles movimientos
    if (newRow >= 0 && newRow < boardSize && newCol >= 0 && newCol < boardSize && board[newRow][newCol] == 1) {  
      // Si son menores que cero o mayores que el tamaño del tablero, no es una posicion segura
      // Tampoco lo es, si en la posicion con los movimientos sumados existe un caballo colocado (== 1)
      return false;
    }
  }
  // Si para ningun movimiento posible existe un caballo atacando se considera una posicion segura
  return true;
}

string solutionToString(int boardSize, vector<vector<vector<int>>> solution){ // Devuelve en cadenala solucion
    string s;
    
    for (int i = 0; i < min(10, (int)solution.size()); i++) { // Recorre el arreglo solucion y guarda en una cadena todo el contenido
    for (int j = 0; j < boardSize; j++) {
      for (int k = 0; k < boardSize; k++) {
        s += to_string( solution[i][j][k] ) + " ";
      }
      s += "\n";
    }
    s += "\n";
  }

  return s;
}