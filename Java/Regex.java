import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.*;
public class Regex {
    public static void main(String args[])
    {
        // String river = "MississippiMississippiMississippiMississippiMississippi";
        // Pattern p =Pattern.compile("Mi(.*?)pi"); // Matches anything which has Mi and after that pi
        // Matcher m = p.matcher(river);
        // while(m.find())
        // {
        //     System.out.println(m.group(1));
        // }

        // String html = "img data-sizes=\"auto\" itemprop=\"image\" src=\"https://imgix.ranker.com/user_node_img/42/821428/original/david-beckham-photo-u134?w=125&h=125&fit=crop&crop=faces&q=60&fm=pjpg\" class=\"listItem__image\" alt=\"David Beckham is listed (or ranked) 2 on the list List of Famous Footballers\"/></figure> <div class=\"listItem__data\"> <!--googleoff: all--> <span class=\"listItem__info block\"> </span><!--googleon: all--> <meta itemprop=\"name\" content=\"David Beckham\"/> <a class=\"listItem__title listItem__title--link black\" rel=\"follow\" itemprop=\"url\" href=\"//www.ranker.com/review/david-beckham/821428?ref=node_name&pos=2&a=0&ltype=n&l=101022&g=0\">David Beckham</a><span class=\"listItem__props block\"> <div class=\"listItem__blather grey default\" itemprop=\"description\">";
        // Pattern imagePattern = Pattern.compile("src=\"(.*?)\"");
        // Pattern playerName = Pattern.compile("content=\"(.*?)\"");
        // Matcher img = imagePattern.matcher(html);
        // while(img.find())
        // {
        //     System.out.println(img.group(1));
        // }
        // Matcher playername = playerName.matcher(html);
        // while(playername.find())
        // {
        //     System.out.println(playername.group(1));
        // }

        String html = "height=\"209\"src=\"https://m.media-amazon.com/images/M/MV5BYzY3YWUzYjMtOTlkMC00ZDQ4LWFmZmEtMjZlOGY0N2RkNWE2XkEyXkFqcGdeQXVyMjUyNDk2ODc@._V1_UY209_CR97,0,140,209_AL_.jpg\"width=\"140\" />";
        Pattern p =Pattern.compile("src=\"(.*?)\"width");
        Matcher m = p.matcher(html);
        while(m.find())
            System.out.println(m.group(1));
    }
}   