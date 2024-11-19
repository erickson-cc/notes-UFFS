public class Store{
	private Item[] inventory;

	public Store(int size){
		this.inventory = new Item[size];
	}
	public void setItem(int index, Item product){
		this.inventory[index] = product;
	}
	public Item getItem(int index){
		return this.inventory[index];
	}
	public int invLen(){
		return this.inventory.length;
	}
	public void printStore(){
		int i;
		System.out.printf(" Peso | ID | Nome\n");
		for(i=0;i<this.inventory.length;i++){
			if(this.inventory[i] != null){
				System.out.printf("%.2fkg| %d| %s\n", this.inventory[i].weight, this.inventory[i].id, this.inventory[i].name);
			}
		}
	}
	public void printFood(){
		int i;
		System.out.printf(" Peso | ID | Nome\n");
		for(i=0;i<this.inventory.length;i++){
			if(this.inventory[i] != null){
				if(this.inventory[i].getClass() == Food.class){
					System.out.printf("%.2fkg| %d| %s\n", this.inventory[i].weight, this.inventory[i].id, this.inventory[i].name);
				}
			}
		}
	}
	public void printWeapon(){
		int i;
		System.out.printf(" Peso | ID | Nome\n");
		for(i=0;i<this.inventory.length;i++){
			if(this.inventory[i] != null){
				if(this.inventory[i].getClass() == Weapon.class){
					System.out.printf("%.2fkg| %d| %s\n", this.inventory[i].weight, this.inventory[i].id, this.inventory[i].name);
				}
			}
		}
	}
	public void printPotion(){
		int i;
		System.out.printf(" Peso | ID | Nome\n");
		for(i=0;i<this.inventory.length;i++){
			if(this.inventory[i] != null){
				if(this.inventory[i].getClass() == Potion.class){
					System.out.printf("%.2fkg| %d| %s\n", this.inventory[i].weight, this.inventory[i].id, this.inventory[i].name);
				}
			}
		}
	}
}
