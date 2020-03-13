public class MultipleTryCatch {
    public static void main(String[] args) { // args = {5,30} ; args[1] = "30"; 30; arr[30]
        try {
            int len = args.length;
            int ans = 5/len;
            try{
                int[] arr = new int[20];
                int index = Integer.parseInt(args[1]);
                System.out.println(arr[index]);
            } catch (ArithmeticException e) {
                e.printStackTrace(); }
            catch(Exception e) {
                e.printStackTrace();
            }
            // } catch(IndexOutOfBoundsException e) {
            //     e.printStackTrace();
            // } catch (Exception e) {
            //     e.printStackTrace();
            // }
            ans = 5/(len-2);
        }catch (ArithmeticException e) {
            e.printStackTrace();
        } catch(IndexOutOfBoundsException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}