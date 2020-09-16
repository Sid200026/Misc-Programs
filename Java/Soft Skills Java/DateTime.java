import java.time.LocalDate;
import java.time.LocalTime;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

class DateTime {
    public static void main(String[] args) {
        LocalDate date1 = LocalDate.of(2020, 1,21);
        System.out.println(date1);
        System.out.println(date1.isLeapYear());
        LocalTime time1 = LocalTime.of(14, 45,43);
        System.out.println(time1);
        LocalTime time2 = time1.minusHours(3);
        System.out.println(time2);
        LocalDate date2 = date1.plusYears(1);
        System.out.println(date2);
        LocalDateTime ldt = LocalDateTime.of(2020,1,20,14,41,32);
        DateTimeFormatter format = DateTimeFormatter.ofPattern("dd-MM-yyyy hh:mm:ss, E, M, a");
        String formatDateTime = ldt.format(format);
        System.out.println(formatDateTime);
        /*

        How to convert a String to a Date object?
            a)  SimpleDateFormat sdf = new SimpleDateFormat("yyyy-mm-dd");
                sdf.parse(new Date());

        How to convert Date object to String?
            b)  SimpleDateFormat sdf = new SimpleDateFormat("yyyy-mm-dd"); 
                sdf.format(new Date());

        */
    }
}