import java.util.Scanner;

public class Casting{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Digite sua idade (Double): ");
		double idade = sc.nextDouble();

		int intIdade = (int) idade;
		System.out.println("Sua idade (int) é: " + intIdade);

		sc.close();
	}
}

