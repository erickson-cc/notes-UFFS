public class Player{
	public Item[] inventory;
	public Player(int size){
		this.inventory = new Item[size];
	}
	private int getSpace(){
		int i;
		int size = 0;
		for(i=0;this.inventory[i] != null;i++){
			size += this.inventory[i].space;
		}
		return size;
	}
	public int getLen(){
		int i;
		int len=0;
		for(i=0;this.inventory[i] != null; i++){
			len += 1;
		}
		return len;
	}
	private double getWeight(){
		int i;
		double weight = 0;
		for(i=0;this.inventory[i] != null; i++){
			weight += this.inventory[i].weight;
		}
		return weight;
	}
	public void addItem(Item product){//Vai adicionar item ao inventario
		int i;
		int size = this.getSpace();
		double weight = this.getWeight();
		if(size + product.space <= 15){
			if(weight + product.weight <= 35){
				this.inventory[this.getLen()] = product;
			}
			else{
				System.out.printf("Você não consegue carregar mais do que isso\n\n");
			}
		}
		else{
			System.out.printf("Você não tem espaço no inventário\n\n");
		}
	}
	public void removeItem(Item product){
		int i;
		int len = this.getLen();
		for(i=0;i<=len;i++){
			if(this.inventory[i]==product){
				this.inventory[i] = null;
				for(i=i;i<=len;i++){
					if(i>0){
						this.inventory[i-1] = this.inventory[i];
					}
				       	this.inventory[i] = null;
				}
			return;
			}
		}
	}
	public void printInventory(){
		int i;
		int size = this.getSpace();
		int len = this.getLen();
		double weight = this.getWeight();
		for(i=0;this.inventory[i] != null;i++){
			//if(this.inventory[i] != null){
				size += this.inventory[i].space;
				weight += this.inventory[i].weight;
				len += 1;
			//}
		}
		System.out.printf("\n\nInventário do Jogador\n Peso | ID | Nome\n");
		for(i=0;i<this.inventory.length;i++){
			if(this.inventory[i] != null){
				System.out.printf("%.2fkg| %d| %s\n", this.inventory[i].weight, this.inventory[i].id, this.inventory[i].name);
			}
		}
		System.out.printf("\n");
	}
}
