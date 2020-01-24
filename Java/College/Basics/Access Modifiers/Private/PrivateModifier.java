package Private;

// ACCESS-MODIFIER : Private

public class PrivateModifier{
    private int a = 5;

    // Same Class Access
    // Allowed
    public int getA() {
        return a;
    }
}

// Sub Class Access
// Not allowed
class SubClassPrivateModifier extends PrivateModifier{
    SubClassPrivateModifier() {
        // System.out.println(a);
    }
}

// Non-Sub Class Access
// Not allowed
class NonSubClassPrivateModifier{
    NonSubClassPrivateModifier() {
        PrivateModifier pm = new PrivateModifier();
        // System.out.println(pm.a);
    }
}