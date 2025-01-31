import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        long n, m, a;
        n = teclado.nextLong();
        m = teclado.nextLong();
        a = teclado.nextLong();
        long lx = (n % a == 0) ? (n / a) : (n / a + 1);
        long ly = (m % a == 0) ? (m / a) : (m / a + 1);

        System.out.println(lx * ly);
    }
}
