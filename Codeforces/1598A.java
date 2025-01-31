import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static Scanner tcl = new Scanner(System.in);
    public static void solve() {
        int n = tcl.nextInt();
        tcl.nextLine();
        String s1 = tcl.nextLine();
        String s2 = tcl.nextLine();

        ArrayList<Integer> nivel = new ArrayList<>();
        for (int i = 0; i < s1.length(); i++) {
            nivel.add(Integer.parseInt(s1.substring(i, i + 1)));
        }
        for (int i = 0; i < s2.length(); i++) {
            nivel.add(Integer.parseInt(s2.substring(i, i + 1)));
        }

        ArrayList<ArrayList<Integer>> listaAdyacencia = new ArrayList<>();
        for (int i = 0; i < 2 * n; i++) {
            listaAdyacencia.add(new ArrayList<>());
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                int celda = i * n + j;
                // Abajo
                if (i == 0 && nivel.get(celda + n) == 0) {
                    listaAdyacencia.get(celda).add(celda + n);
                }
                // Arriba
                if (i == 1 && nivel.get(celda - n) == 0) {
                    listaAdyacencia.get(celda).add(celda - n);
                }
                // Izquierda
                if (j != 0 && nivel.get(celda - 1) == 0) {
                    listaAdyacencia.get(celda).add(celda - 1);
                }
                // Derecha
                if (j != n - 1 && nivel.get(celda + 1) == 0) {
                    listaAdyacencia.get(celda).add(celda + 1);
                }
                //Diagonal abajo-derecha
                if (i == 0 && j != n - 1 && nivel.get(celda + n + 1) == 0) {
                    listaAdyacencia.get(celda).add(celda + n + 1);
                }
                //Diagonal abajo-izquierda
                if (i == 0 && j != 0 && nivel.get(celda + n - 1) == 0) {
                    listaAdyacencia.get(celda).add(celda + n - 1);
                }
                //Diagonal arriba-derecha
                if (i == 1 && j != n - 1 && nivel.get(celda - n + 1) == 0) {
                    listaAdyacencia.get(celda).add(celda - n + 1);
                }
                //Diagonal arriba-izquierda
                if (i == 1 && j != 0 && nivel.get(celda - n - 1) == 0) {
                    listaAdyacencia.get(celda).add(celda - n - 1);
                }
            }
        }

        int salida = 2 * n - 1;

        Stack<Integer> pila = new Stack<>();
        ArrayList<Boolean> visitado = new ArrayList<>();
        for (int i = 0; i < 2 * n; i++) {
            visitado.add(false);
        }

        pila.push(0);

        while (!pila.empty()) {
            int celda = pila.peek();

            if (celda == salida) {
                System.out.println("YES");
                return;
            }

            if (visitado.get(celda)) {
                pila.pop();
                continue;
            }

            visitado.set(celda, true);

            for (int i = 0; i < listaAdyacencia.get(celda).size(); i++) {
                int vecino = listaAdyacencia.get(celda).get(i);
                if (!visitado.get(vecino)) {
                    pila.push(vecino);
                }
            }
        }


        /*for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < listaAdyacencia.get(i).size(); j++) {
                System.out.print(listaAdyacencia.get(i).get(j) + " ");
            }
            System.out.print("\n");
        }*/


        System.out.println("NO");
    }

    public static void main(String[] args) {
        int t = tcl.nextInt();

        while (t-- != 0) {
            solve();
        }
    }
}

