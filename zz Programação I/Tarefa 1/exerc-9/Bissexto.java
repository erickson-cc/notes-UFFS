import java.util.Scanner;

public class Bissexto{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int ano;

		System.out.println("Informe o ano: ");
		ano = sc.nextInt();

		if(ano%4==0){
			if(ano%100!=0){
				System.out.println("Ano Bissexto");
			}
			else if(ano%400==0){
				System.out.println("Ano Bissexto");
			}
			else{
				System.out.println("Ano Não-Bissexto");
			}
		}
		else{
			System.out.println("Ano Não-Bissexto");
		}
		sc.close();
	}
}
