import java.util.Scanner;

public class Maior{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int num1;
		int num2;

		System.out.println("Informe o primeiro número: ");
		num1=sc.nextInt();

		System.out.println("Informe o segundo número: ");
		num2=sc.nextInt();

		if (num1>num2){
			System.out.printf("A comparação entre os número %s e %s resultou que %s é maior",num1,num2,num1);
		}
		else if (num2>num1){
			System.out.printf("A comparação entre os número %s e %s resultou que %s é maior",num1,num2,num2);
		}
		if (num1==num2){
			System.out.printf("A comparação entre os número %s e %s resultou que ambos são iguais",num1,num2);
		}
		sc.close();

	}
}
