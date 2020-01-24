package Protected;

// ACCESS-MODIFIER : Protected

public class ProtectedModifier{
    protected int a = 5;
    
    // Same Class Access
    // Allowed
    public int getA(){
        return a;
    }
}

// Sub Class Access
// Allowed
class SubClassProtectedModifier extends ProtectedModifier{
    SubClassProtectedModifier() {
        System.out.println(a);
    }
}

// Non-Sub Class Access
// Allowed
class NonSubClassProtectedModifier{
    NonSubClassProtectedModifier() {
        ProtectedModifier pm = new ProtectedModifier();
        System.out.println(pm.a);
    }
}