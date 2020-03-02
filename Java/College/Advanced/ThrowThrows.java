class ThrowThrows {

    public static void raiseException() throws Exception {
        throw new Exception("H");
    }
    public static void raise() {
        try{
            throw new Exception("Hi");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        try{
            raiseException();
        } catch (Exception e) {
            e.printStackTrace();
        }
        raise();
        // raiseException();
        System.out.println("Hi");
    }
}