using System.IO;

DateTime start = DateTime.Now;

string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

List<string> ar = new List<string>();

Random rnd = new Random();
for(int i = 0; i < 10000; i++) {
	ar.Add("" + letters[rnd.Next(0, letters.Count())]
		+ letters[rnd.Next(0, letters.Count())]
		+ letters[rnd.Next(0, letters.Count())]
		+ letters[rnd.Next(0, letters.Count())]);
}

ar.Sort();

using(StreamWriter writer = new StreamWriter("roberto_output.txt")) {
	writer.Write(string.Join("\n", ar.ToArray()));
}

Console.WriteLine("Elapsed time: " + (DateTime.Now - start).TotalMilliseconds + "ms");

