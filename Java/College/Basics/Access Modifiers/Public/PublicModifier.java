package Public;

// ACCESS-MODIFIER : Public

public class PublicModifier {
    public int a = 5;

    // Same Class Access
    // Allowed
    public int getA() {
        return a;
    }
}

// Sub Class Access
// Allowed
class SubClassPublicModifier extends PublicModifier {
    SubClassPublicModifier() {
        System.out.println(a);
    }
}

// Non-Sub Class Access
// Allowed
class NonSubClassPublicModifier {
    NonSubClassPublicModifier() {
        PublicModifier pm = new PublicModifier();
        System.out.println(pm.a);
    }
}