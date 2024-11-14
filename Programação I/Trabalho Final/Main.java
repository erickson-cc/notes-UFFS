/* Sistema de Inventário
 * Cada usuário terá 15 slots e conseguirá carregar até 35kg de peso
 * A estamina do usuário é float de 0 a 100.
 */
import java.util.Scanner;




public class Main{
	public static void Main(String[] args){
	//Food
	Food f1 = new Food(23,"oi",4,21,true,25);
	//Weapon
	Weapon w1 = new Weapon(123,"Arma",2,40,false,100,false);
	//Potion
	Potion p1 = new Potion(99,"Potion",3,41,true,50,0,0);

	Item[] store = {f1,w1,p1};
	}
}
