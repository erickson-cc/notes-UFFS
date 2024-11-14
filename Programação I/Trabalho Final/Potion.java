public class Potion extends Item implements Consumable{
	private float health;
	private float strenght;
	private float speed;
	// Constructor
	Potion(int id, String name, int space, float weight, boolean stackable, float health, float strenght, float speed){
		super(id, name, space, weight, stackable);
		this.health = health;
		this.strenght = strenght;
		this.speed = speed;
	}
	// Setters
	public void setHealth(float health){
		this.health = health;
	}
	public void setStrenght(float strenght){
		this.strenght = strenght;
	}
	public void setSpeed(float speed){
		this.speed = speed;
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
	public float getHealth(){
		return this.health;
	}
	public float getStrenght(){
		return this.strenght;
	}
	public float getSpeed(){
		return this.speed;
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
