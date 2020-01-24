package Default;

// ACCESS-MODIFIER : Default

public class DefaultModifier {
    int a = 5;

    // Same Class Access
    // Allowed
    public int getA() {
        return a;
    }
}

// Sub Class Access
// Allowed
class SubClassDefaultModifier extends DefaultModifier {
    SubClassDefaultModifier() {
        System.out.println(a);
    }
}

// Non-Sub Class Access
// Allowed
class NonSubClassDefaultModifier {
    NonSubClassDefaultModifier() {
        DefaultModifier pm = new DefaultModifier();
        System.out.println(pm.a);
    }
}