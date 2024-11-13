abstract class Item{
	protected int id;
	protected String name;
	protected int space;
	protected float weight;
	protected boolean stackable;
	// Constructor
	Item(int id, String name, int space, float weight, boolean stackable){
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
	abstract void setWeight(float weight);
	abstract void setStackable(boolean stackable);
	// Getters
	abstract int getId();
	abstract String getName();
	abstract int getSpace();
	abstract float getWeight();
	abstract boolean getStackable();
}
