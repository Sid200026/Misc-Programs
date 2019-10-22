public class Rectangle
{
    int l,b;
    public Rectangle(int length, int breadth)
    {
        this.l = length;
        this.b = breadth;
    }

    public int getArea()
    {
        return this.l*this.b;
    }

    @Override
    public String toString()
    {
        return "I am a rectangle";
    }
}

public class Square extends Rectangle
{
    int s;
    public Square(int side)
    {
        super(side,side);
        this.s = side;
    }

    @Override
    public String toString()
    {
        return (super.toString()+" and also a square");
    }
    public static void main(String args[]) 
    {
        Square s = new Square(1);
        System.out.println(s.getArea());
        System.out.println(s.toString());
    }
}