/**
 * Written By Evan Scales
 */

import java.util.*;
import java.io.*;
public class PackageSorter {
    private static Scanner keyboard = new Scanner(System.in);
    private static PackageSorterManager manager = new PackageSorterManager();
    public static void main(String[] args) {
        boolean quit = false;
        System.out.println("Welcome to package sorter 1.0");
       
        while(!quit) {
            printChoices();
            int choice = keyboard.nextInt();
            keyboard.nextLine();
            switch(choice) {
                case 1:
                    scanPackage();
                    break;
                case 0:
                    quit = true;
                    System.out.println("Peace out bitch");
                    break;
                    default:
                        System.out.println("Invalid input dumb bitch");
            }
        }




        keyboard.close();
    }
    public static void printChoices() {
        System.out.println("Enter 1 to scan packages");
        System.out.println("Enter 2 to change airport");
        System.out.println("Enter 0 to quit");
    }
    public static void scanPackage() {
        String DELIM = ",";
        int FIELD_AMT = 4;
        boolean scan = true;
        System.out.println("Enter O(or o) to stop");
        while (scan) {
            System.out.println("Scan package ID,ZIPCODE,WEIGHT,HAZMAT");
            String input = keyboard.nextLine();
            if (input.equalsIgnoreCase("o")) {
                scan = false;
                break;
            }
            String [] splStrings = input.split(DELIM);
            if (splStrings.length == FIELD_AMT) {
                int id = Integer.parseInt(splStrings[0]);
                int zipcode = Integer.parseInt(splStrings[1]);
                int weight = Integer.parseInt(splStrings[2]);
                int hazmat = Integer.parseInt(splStrings[3]);
                Package p = new Package(id, zipcode, weight, hazmat);
                // System.out.println(p);
                
            }  
        }
    }
}