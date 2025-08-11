import java.util.Scanner;

public class Area {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		float base;
		float altura;
		float area;

		System.out.println("Informe a base do triângulo: ");
		base = sc.nextFloat();

		System.out.println("Informe a altura do triângulo: ");
		altura = sc.nextFloat();

		area = base*altura/2.0f;
		System.out.printf("Área = %.2f",area);
		sc.close();
	}
}

