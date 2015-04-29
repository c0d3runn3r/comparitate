// Goal: Create a file containing 10,000 random 4-letter strings, sorted alphabetically.
// 
// Don't make the most efficient program possible, just write something natural that 
// thinks about the generic case.  

import java.util.Random;
import java.io.*;
import java.util.Arrays;



class Joseph {

	private final Random random = new Random();
	private static final String alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	private static long start_time, end_time;


	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {

		// Save time
		start_time=System.currentTimeMillis();


		String[] a = new String[10000];

		// Create random strings
		for(int n=0; n< a.length; n++) {
	
			a[n]= Joseph.getNewString(4);
		}

		// Sort
		Arrays.sort(a);


		// Write to file
		PrintWriter w = new PrintWriter("joseph_output.txt", "UTF-8");
		for(int n=0; n< a.length; n++) {

			w.println(a[n]);
		}
		w.close();

		// Calculate elapsed time
		end_time=System.currentTimeMillis();

		System.out.println("Elapsed time: "+(end_time-start_time)+ " ms\n");
	}


	/**
	*  Create random strings
	*
	* @return a random n letter string
	*/
	public static String getNewString(int n) {

		Random r = new Random();
		String s = new String();

		while(s.length() < n) {

			s+=alphabet.charAt(r.nextInt(alphabet.length()));
		}

		return s;
	}


}