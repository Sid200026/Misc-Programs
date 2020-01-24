import Public.*;

public class PublicPack{
    public static void main(String[] args) {
        new DiffPackageSubClass();
        new DiffPackageNonSubClass();
    }
}

// Different Package SubClass
// Allowed
class DiffPackageSubClass extends PublicModifier{
    DiffPackageSubClass() {
        System.out.println(a);
    }
}

// Different Package Non-SubClass
// Allowed
class DiffPackageNonSubClass{
    DiffPackageNonSubClass() {
        PublicModifier pb = new PublicModifier();
        System.out.println(pb.a);
    }
}