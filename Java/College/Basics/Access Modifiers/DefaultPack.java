import Default.*;

public class DefaultPack {
    public static void main(String[] args) {
        new DiffPackageSubClass();
        new DiffPackageNonSubClass();
    }
}

// Different Package SubClass
// Not Allowed
class DiffPackageSubClass extends DefaultModifier {
    DiffPackageSubClass() {
        // System.out.println(a);
    }
}

// Different Package Non-SubClass
// Not Allowed
class DiffPackageNonSubClass {
    DiffPackageNonSubClass() {
        DefaultModifier pb = new DefaultModifier();
        // System.out.println(pb.a);
    }
}