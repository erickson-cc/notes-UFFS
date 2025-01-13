abstract class Item{
	/* Classe abstrata que tratará dos itens que serão armazenados nos inventários ou na loja
	 */
	protected int id;
	protected String name;
	protected int space;
	protected double weight;
	protected boolean stackable;
	// Constructor
	Item(int id, String name, int space, double weight, boolean stackable){
		this.id = id;
		this.name = name;
		this.space = space;
		this.weight = weight;
		this.stackable = stackable;
	}
	// Setters
	abstract void setId(int id);
	abstract void setName(String name);
	abstract void setSpace(int space);
	abstract void setWeight(double weight);
	abstract void setStackable(boolean stackable);
	// Getters
	abstract int getId();
	abstract String getName();
	abstract int getSpace();
	abstract double getWeight();
	abstract boolean getStackable();
}

