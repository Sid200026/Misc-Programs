public class FilmMain 
{
    String name;
    String language;
    String lead_actor;
    String category;
    int duration; 

public void show()
{
System.out.println("THE ENTERED DETAILS:");
    System.out.println("NAME:"+" "+name);
    System.out.println("LANGUAGE:"+" "+language);
    System.out.println("LEAD_ACTOR:"+" "+lead_actor);
    System.out.println("CATEGORY:"+" "+category);
    System.out.println("DURATION:"+" "+duration);
}

//default constructor
public FilmMain()
{
    name="movie";
    language="language";
    duration=0;
    lead_actor="xyz";
    category="xyz";
}

public FilmMain(String name,String language,String lead_actor,String category,int duration)
{
    this.name=name;
    this.language=language;
    this.lead_actor=lead_actor;
    this.category=category;
    this.duration=duration;
}

public static void main(String args[])
{

FilmMain fm =new FilmMain();
fm.show();
System.out.println();
FilmMain film= new FilmMain("Siddharth","Bengali","Leo","Action",15);
film.show();
}
}