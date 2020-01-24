class Person {
    private String name;

    Person(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }
}

public class ArrayOfObjects {
    public static void main(String[] args) {
        Person[] persons = new Person[10];
        for (int i = 0; i < 10; i++) {
            persons[i] = new Person(Integer.toString(i + 1));
        }
        for (Person person : persons) {
            System.out.println(person.getName());
        }
    }
}