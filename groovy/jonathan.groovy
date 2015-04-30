def start = new Date().getTime()
def letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
def file = new File("jonathan_output.txt")
def words = []
(1..10000).each{
	def word = ""
	(1..4).each{
		word += letters[new Random().nextInt(26)]
	}
	words << word
}
words.sort{it}
words.each{file << it + "\n"}
println "Finished after " + (new Date().getTime() - start) + "ms"