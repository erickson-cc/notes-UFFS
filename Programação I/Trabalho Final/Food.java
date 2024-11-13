public class Food extends Item implements Consumable{
	private float stamina;
	// Constructor
	Food(int id, String name, int space, float weight, boolean stackable, float stamina){
		super(id, name, space, weight, stackable);
		this.stamina = stamina;
	}
	// Setters 
	public void setStamina(float stamina){
		this.stamina = stamina;
	}
	@Override
	public void setId(int id){
		this.id = id;
	}
	@Override
	public void setName(String name){
		this.name = name;
	}
	@Override
	public void setSpace(int space){
		this.space = space;
	}
	@Override
	public void setWeight(float weight){
		this.weight = weight;
	}
	@Override
	public void setStackable(boolean stackable){
		this.stackable = stackable;
	}
	// Getters
	public float getStamina(){
		return this.stamina;
	}
	@Override
	public int getId(){
		return this.id;
	}
	@Override
	public String getName(){
		return this.name;
	}
	@Override
	public int getSpace(){
		return this.space;
	}
	@Override
	public float getWeight(){
		return this.weight;
	}
	@Override
	public boolean getStackable(){
		return this.stackable;
	}
	@Override
	public void consume(){
		System.out.println("000");
	}	
}
