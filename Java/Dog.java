public class Dog
{
    String name;
    String breed;
    int age;
    
    public Dog(String name, String breed, int age)
    {
        this.name = name;
        this.breed = breed;
        this.age = age;
    }

    public String getName()
    {
        return this.name;
    }

    public String getBreed()
    {
        return this.breed;
    }

    public int getAge()
    {
        return this.age;
    }

    @Override
    public String toString()
    {
        return "Dog Name: "+this.name+" Age: "+this.age+" Breed: "+this.breed;
    }

    public static void main(String[] args) {
        Dog doggie = new Dog("Siddharth", "Lab", 19);
        System.out.println(doggie.getName());
        System.out.println(doggie.getBreed());
        System.out.println(doggie.getAge());
        System.out.println(doggie.toString());
    }
}