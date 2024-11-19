/* Sistema de Inventário
 * Cada usuário terá 15 slots e conseguirá carregar até 35kg de peso
 * A estamina do usuário é float de 0 a 100.
 */
import java.util.Scanner;




public class Main{
	public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	int cmd = 999;
	int i;
	int selected = -1;
	//Item(id,name,space,weight,stackable)
	//Food					(stamina)
	Food f1 = new Food(111,"Peixe Assado",1,0.33,true,12);
	Food f2 = new Food(112,"Pão",1,0.20,true,10);
	Food f3 = new Food(113,"Cebola Assada",1,0.50,true,5);
	Food f4 = new Food(114,"Queijo",1,1.00,true,25);
	Food f5 = new Food(115,"Água",1,0.50,true,10);
	Food f6 = new Food(116,"Vinho tinto",1,0.80,true,-30);
	Food f7 = new Food(117,"Mingau de Aveia",1,0.60,true,40);
	Food f8 = new Food(118,"Tomate",1,0.20,true,5);
	Food f9 = new Food(119,"Maçã",1,0.20,true,15);
	Food f0 = new Food(110,"Bolo",1,2.50,false,60);
	//Weapon				(damage,onehanded)
	Weapon w1 = new Weapon(311,"Faca",1,0.4,false,10,true);
	Weapon w2 = new Weapon(312,"Espada",3,1.5,false,20,true);
	Weapon w3 = new Weapon(313,"Cimitarra",3,2,false,22,true);
	Weapon w4 = new Weapon(314,"Besta",2,5,false,15,true);
	Weapon w5 = new Weapon(315,"Estilingue",1,0.1,false,1,true);
	Weapon w6 = new Weapon(316,"Canhão",8,25,false,99,false);
	Weapon w7 = new Weapon(317,"Trabuco",2,1,false,25,true);
	Weapon w8 = new Weapon(318,"Lança",5,1.2,false,20,false);
	Weapon w9 = new Weapon(319,"Arco Longo",4,0.8,false,30,false);
	Weapon w0 = new Weapon(310,"Machado",2,1.0,false,20,true);
	//Potion				(health,strenght,speed)
	Potion p1 = new Potion(211,"Poção de Vida",1,0.5,false,50,0,0);
	Potion p2 = new Potion(212,"Poção de Força",1,0.5,false,0,50,0);
	Potion p3 = new Potion(213,"Poção de Velocidade",1,0.5,false,0,0,50);
	Potion p4 = new Potion(214,"Super Poção de Vida",1,0.5,false,100,-25,-25);
	Potion p5 = new Potion(215,"Super Poção de Força",1,0.5,false,-25,100,-25);
	Potion p6 = new Potion(216,"Super Poção de Velocidade",1,0.5,false,-25,-25,100);
	Potion p7 = new Potion(217,"Poção de Vida e Força",1,0.5,false,30,30,0);
	Potion p8 = new Potion(218,"Poção de Vida e Velocidade",1,0.5,false,30,0,30);
	Potion p9 = new Potion(219,"Poção de Força e Velocidade",1,0.5,false,0,30,30);
	Potion p0 = new Potion(210,"Poção Geral",1,0.5,true,33,33,33);
	// Store & Player Inventory
	Store s0 = new Store(100);
	s0.setItem(0,f1);s0.setItem(1,f2);s0.setItem(2,f3);s0.setItem(3,f4);s0.setItem(4,f5);	
	s0.setItem(5,f6);s0.setItem(6,f7);s0.setItem(7,f8);s0.setItem(8,f9);s0.setItem(9,f0);	

	s0.setItem(10,w1);s0.setItem(11,w2);s0.setItem(12,w3);s0.setItem(13,w4);s0.setItem(14,w5);	
	s0.setItem(15,w6);s0.setItem(16,w7);s0.setItem(17,w8);s0.setItem(18,w9);s0.setItem(19,w0);	

	s0.setItem(20,p1);s0.setItem(21,p2);s0.setItem(22,p3);s0.setItem(23,p4);s0.setItem(24,p5);	
	s0.setItem(25,p6);s0.setItem(26,p7);s0.setItem(27,p8);s0.setItem(28,p9);s0.setItem(29,p0);	
	//s0.printStore();
	Menu menu  = new Menu();
	Player player = new Player(15);//todos os itens ocupam pelo menos 1 slot
	while(cmd != 0){
		menu.Main();
		cmd = sc.nextInt();
		if(cmd==1){
			menu.Store();
			cmd = sc.nextInt();
			if(cmd == 1) s0.printStore();
			if(cmd == 2) s0.printFood();
			if(cmd == 3) s0.printWeapon();
			if(cmd == 4) s0.printPotion();
			if(cmd==0) break;
			menu.Select();
			cmd = sc.nextInt();
			if(cmd==0){
				cmd=-1;//Retorna para o menu da loja
			}
			else{
				for(i=0;i<=s0.invLen();i++){
					if(s0.getItem(i).id == cmd){
						selected = i;	
						break;
					}
					else{
						selected = -1;
					}
				}
				if(selected != -1){
					menu.Action(s0, selected);
					cmd = sc.nextInt();
					if(cmd == 1){
						player.addItem(s0.getItem(selected));
					}
				}
			}
		}
		if(cmd==2){
			player.printInventory();
		}
	}
	}
}
