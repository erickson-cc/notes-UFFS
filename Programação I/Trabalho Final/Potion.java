public class Potion extends Item implements Consumable{
	/* Classe poção que irá aumentar os atributos do jogador */
	private double health;
	private double strenght;
	private double speed;
	// Constructor
	Potion(int id, String name, int space, double weight, boolean stackable, double health, double strenght, double speed){
		super(id, name, space, weight, stackable);
		this.health = health;
		this.strenght = strenght;
		this.speed = speed;
	}
	// Setters
	public void setHealth(double health){
		this.health = health;
	}
	public void setStrenght(double strenght){
		this.strenght = strenght;
	}
	public void setSpeed(double speed){
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
	public void setWeight(double weight){
		this.weight = weight;
	}
	@Override
	public void setStackable(boolean stackable){
		this.stackable = stackable;
	}
	// Getters
	public double getHealth(){
		return this.health;
	}
	public double getStrenght(){
		return this.strenght;
	}
	public double getSpeed(){
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
	public double getWeight(){
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
