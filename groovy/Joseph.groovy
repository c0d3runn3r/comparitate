// Goal: Create a file containing 10,000 random 4-letter strings, sorted alphabetically.
// 
// Don't make the most efficient program possible, just write something natural that 
// thinks about the generic case.  

//import java.util.Random;
//import java.io.*;
//import java.util.Arrays;


class Joseph {
	public static def random = new Random();
	
	static def main(args) {

		def start_time=Calendar.instance.time.time;


		// Create array
		def a = new String[10000];

		// Fill, sort, write
		new File("joseph_output.txt").withWriter{ out ->

			a.collect { getRandomString(4) }.sort().each() { line ->

				out.writeLine(line);			
			}
		}

		// Print elapsed time
		def end_time=Calendar.instance.time.time;
		println("Completed in "+(end_time-start_time)+" ms");

	}	




	public static def getRandomString(def n){

		def alphabet= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";	 // This should be a static global object!!!! (Groovy throws for some reason)

		def s = new String();
		while(s.length()<4) {

			s+=alphabet.charAt(random.nextInt(alphabet.length()));
		}

		return s;
	}

}