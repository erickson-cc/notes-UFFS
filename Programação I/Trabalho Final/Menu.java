public class Menu{
	/**
	 * Classe  que imprime os menus de navegação
	 */
	public void Main(){
		System.out.printf("Bem-vindo à loja de itens para seu personagem\n");
		System.out.printf("1-Abrir loja\n");
		System.out.printf("2-Inventário\n");
		System.out.printf("0-Encerrar\n");
	}
	public void Store(){
	/* Opções da loja, onde poderemos listar por subclasses */
		System.out.printf("\n\nMenus da loja:\n");
		System.out.printf("1-Visualizar todos os itens\n");
		System.out.printf("2-Visualizar Alimentos\n");
		System.out.printf("3-Visualizar Armas\n");
		System.out.printf("4-Visualizar Poções\n");
		System.out.printf("0-Encerrar\n");
	}
	public void Select(){
		/*
		 * Menu que indica o item selecionado
		 */
		System.out.printf("\n\nInforme o ID do item que deseja selecionar: \n");
		System.out.printf("Digite 0 para retornar\n");
	}
	public void Action(Store s, int i){
		/*
		 * Indica o que fazer com o item selecionado. Esse método se refere aos itens da loja
		 */
	//	System.out.println("Class name: "+s.getItem(i).getClass());
		System.out.printf("Você selecionou o item: %s\n",s.getItem(i).name);
		System.out.printf("1-Comprar\n");
	//	System.out.printf("2-Vender\n");
	//	System.out.printf("3-Consumir\n");
		}
	public void InventoryAction(Player p, int i){
		/* Indica o que fazer com o item selecionado. Esse método se refere oas itens do inventário
		 */
		System.out.printf("Você selecionou o item: %s\n",p.inventory[i].name);
		System.out.printf("1-Descartar\n");
		if(p.inventory[i].getClass() != Weapon.class){
			System.out.printf("2-Consumir\n");
		}
	}
}
