public class Player{
	private Item[] inventory;
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
	private int getLen(){
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
		System.out.printf(" Peso | ID | Nome\n");
		for(i=0;i<this.inventory.length;i++){
			if(this.inventory[i] != null){
				System.out.printf("%.2fkg| %d| %s\n", this.inventory[i].weight, this.inventory[i].id, this.inventory[i].name);
			}
		}
	}
}
