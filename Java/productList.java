import java.util.*;
public class ProductList 
{
    int tshirt, jacket, shoes, jeans;
    public ProductList() 
    {
        tshirt = 999;
        jacket = 1000;
        shoes = 2500;
        jeans = 1100;
    }

    public int tshirtAmt(int qty)
    {
        return qty*tshirt;
    }

    public int jacketAmt(int qty) 
    {
        return qty * jacket;
    }

    public int shoesAmt(int qty)
    {
        return qty * shoes;
    }

    public int jeansAmt(int qty)
    {
        return qty * jeans;
    }

    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);
        int amount = 0;
        ProductList stock = new ProductList();
        System.out.println("Welcome to MyStore");
        System.out.println("Product Codes");
        System.out.println("Tshirt : 1");
        System.out.println("Jacket : 2");
        System.out.println("Shoes : 3");
        System.out.println("Jeans : 4");
        System.out.println("Exit : 0");
        Boolean flag = true;
        while(flag)
        {
            System.out.println("Enter the product code");
            char code = input.next().charAt(0);
            if(code=='0')
                break;
            System.out.println("Enter the quantity");
            int stck = input.nextInt();
            switch(code)
            {
                case('1'):
                    amount += stock.tshirtAmt(stck);
                    break;
                case('2'):
                    amount += stock.jacketAmt(stck);
                    break;
                case('3'):
                    amount += stock.shoesAmt(stck);
                    break;
                case('4'):
                    amount += stock.jeansAmt(stck);
                    break;
                case('0'):
                    flag = false;
                    break;
                default:
                    System.out.println("Wrong choice");
            }
        }
        System.out.println("Amount is : "+amount);
    }
}