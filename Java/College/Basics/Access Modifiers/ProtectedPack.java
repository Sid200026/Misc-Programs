import Protected.*;

public class ProtectedPack {
    public static void main(String[] args) {
        new DiffPackageSubClass();
        new DiffPackageNonSubClass();
    }
}

// Different Package SubClass
// Allowed
class DiffPackageSubClass extends ProtectedModifier {
    DiffPackageSubClass() {
        System.out.println(a);
    }
}

// Different Package Non-SubClass
// Not Allowed
class DiffPackageNonSubClass {
    DiffPackageNonSubClass() {
        ProtectedModifier pb = new ProtectedModifier();
        // System.out.println(pb.a);
    }
}