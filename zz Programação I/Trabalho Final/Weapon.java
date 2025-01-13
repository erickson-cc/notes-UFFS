public class Weapon extends Item{
	private int damage;
	private boolean onehanded;
	// Construtor
	Weapon(int id, String name, int space, double weight, boolean stackable, int damage, boolean onehanded){
		super(id,name,space,weight,stackable);
		this.damage = damage;
		this.onehanded = onehanded;
	}
	// Setters
	public void setDamage(int damage){
		this.damage = damage;
	}
	public void setHand(boolean onehanded){
		this.onehanded = onehanded;
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
	public int getDamage(){
		return this.damage;
	}
	public boolean getHand(){
		return this.onehanded;
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
}
