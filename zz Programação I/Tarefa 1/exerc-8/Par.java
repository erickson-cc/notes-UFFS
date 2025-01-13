import java.util.Scanner;

public class Par{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int num;

		System.out.println("Digite um número inteiro qualquer: ");
		num = sc.nextInt();

		if(num%2==0){
			System.out.println("Número Par");
		}
		else{
			System.out.println("Número Ímpar");
		}
		sc.close();
	}
}
