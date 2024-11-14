public class Store{
	private Item[] inventory;

	public Store(int size){
		this.inventory = new Item[size];
	}
	public void setItem(int index, Item product){
		this.inventory[index] = product;
	}
	public void printStore(){
		int i;
		for(i=0;i<this.inventory.length;i++){
			if(this.inventory[i] != null){
				System.out.printf("%d: %s\n", i, this.inventory[i].name);
			}
		}
	}
}
