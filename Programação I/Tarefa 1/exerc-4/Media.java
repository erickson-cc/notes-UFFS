import java.util.Scanner;

public class Media{
		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			int count;
//			int num;
			float media=0.0f;
			for(count=1;count<=3;count++){
				System.out.println("Digite o "+count+" número: ");
				int num = sc.nextInt();
				media = media +num/3.0f;
			}
			System.out.printf("A média é: %.2f",media);
			sc.close();
		}
}

