public class GameClass
{
    public static void main(String[] args) 
    {
        class integer
        {
            int num;
            public boolean isPositive()
            {
                if(num>0)
                    return true;
                return false;
            }
        }
        integer number = new integer();
        number.num = 5;
        System.out.println(number.isPositive());
        number.num = -5;
        System.out.println(number.isPositive());
    }
}