import java.util.*;

class Employee implements Comparable<Employee> {
    String name;
    String designation;
    int salary;
    int id;

    Employee(String name, String designation, int salary, int id) {
        this.name = name;
        this.designation = designation;
        this.salary = salary;
        this.id = id;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Employee employee = (Employee) obj;
        return id == employee.id;
    }
    
    public int hashCode() {
        return Objects.hash(id);
    }

    public int compareTo(Employee employee) {
        return this.getId() - employee.getId();
    }

    public String toString() {
        return name + " " + id;
    }
}

public class HashSetEmployee {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashSet<Employee> emp = new HashSet<Employee>();
        System.out.println("Inserting an employee");
        System.out.println("Enter the name");
        String name = sc.next();
        System.out.println("Enter the designation");
        String designation = sc.next();
        System.out.println("Enter the salary");
        int salary = sc.nextInt();
        Employee e = new Employee(name, designation, salary, 0);
        emp.add(e);
        System.out.println();
        System.out.println("Inserting another employee");
        System.out.println("Enter the name");
        name = sc.next();
        System.out.println("Enter the designation");
        designation = sc.next();
        System.out.println("Enter the salary");
        salary = sc.nextInt();
        emp.add(new Employee(name, designation, salary, 1));
        System.out.println();
        System.out.println("Inserting another employee");
        System.out.println("Enter the name");
        name = sc.next();
        System.out.println("Enter the designation");
        designation = sc.next();
        System.out.println("Enter the salary");
        salary = sc.nextInt();
        emp.add(new Employee(name, designation, salary, 2));
        System.out.println();
        System.out.println("Inserting another employee");
        System.out.println("Enter the name");
        name = sc.next();
        System.out.println("Enter the designation");
        designation = sc.next();
        System.out.println("Enter the salary");
        salary = sc.nextInt();
        Employee e1 = new Employee(name, designation, salary, 3);
        emp.add(e1);
        System.out.println(emp);
        System.out.println();
        System.out.println("Removing employee with id 0");
        emp.remove(e);
        System.out.println(emp);
        System.out.println();
        if(emp.contains(e1)) {
            System.out.println("Found");
        } else {
            System.out.println("Not found");
        }
    }
}