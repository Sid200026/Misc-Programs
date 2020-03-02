import java.io.*;
class FileExtension {

    private static String getFileExtension(File file) {
        String fileName = file.getName();
        // If it -1 then extension is not specified in the name
        // If it is 0 then it is a hidden file like .gitignore etc
        if(fileName.lastIndexOf(".") != -1 && fileName.lastIndexOf(".") != 0)
        return fileName.substring(fileName.lastIndexOf(".")+1);
        else return "";
    }
    public static void main(String[] args) {
        File folder = new File("."); // Get the current directory
        File[] listOfFiles = folder.listFiles();

        for (int i = 0; i < listOfFiles.length; i++) {
            if (listOfFiles[i].isFile()) {
                if("pdf".equals(getFileExtension(listOfFiles[i])) || "doc".equals(getFileExtension(listOfFiles[i]))) {
                    System.out.println("Name : " + (listOfFiles[i]).getName());
                    System.out.println("Executable: " + listOfFiles[i].canExecute()); 
                    System.out.println("Readable: " + listOfFiles[i].canRead()); 
                    System.out.println("Writable: "+ listOfFiles[i].canWrite()); 
                    System.out.println();
                }
            }
        }
    }
}
