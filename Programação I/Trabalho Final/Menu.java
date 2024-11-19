public class Menu{
	public void Main(){
		System.out.printf("Bem-vindo à loja de itens para seu personagem\n");
		System.out.printf("1-Abrir loja\n");
		System.out.printf("2-Inventário\n");
		System.out.printf("0-Encerrar\n");
	}
	public void Store(){
		System.out.printf("\n\nMenus da loja:\n");
		System.out.printf("1-Visualizar todos os itens\n");
		System.out.printf("2-Visualizar Alimentos\n");
		System.out.printf("3-Visualizar Armas\n");
		System.out.printf("4-Visualizar Poções\n");
		System.out.printf("0-Encerrar\n");
	}
	public void Select(){
		System.out.printf("\n\nInforme o ID do item que deseja comprar: \n");
		System.out.printf("Digite 0 para retornar\n");
	}
	public void Action(Store s, int i){
		System.out.printf("Você selecionou o item: %s\n",s.getItem(i).name);
		System.out.printf("1-Comprar\n");
		System.out.printf("2-Vender\n");
		System.out.printf("3-Consumir\n");
	}
}
