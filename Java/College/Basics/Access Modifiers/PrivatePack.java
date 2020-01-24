import Private.*;

public class PrivatePack {
    public static void main(String[] args) {
        new DiffPackageSubClass();
        new DiffPackageNonSubClass();
    }
}

// Different Package SubClass
// Not Allowed
class DiffPackageSubClass extends PrivateModifier {
    DiffPackageSubClass() {
        // System.out.println(a);
    }
}

// Different Package Non-SubClass
// Not Allowed
class DiffPackageNonSubClass {
    DiffPackageNonSubClass() {
        PrivateModifier pb = new PrivateModifier();
        // System.out.println(pb.a);
    }
}