import scala.io.Source

object ScalaTutorial {
  def main(args: Array[String]){
   
   
   val wordsFromFile = Source.fromFile("input.txt", "UTF-8")
   
   //toArray or mkString turns it into an array of characters.. getLines are lines
   val wordIterator = wordsFromFile.mkString.split("[ .-]").toSeq.map(_.toLowerCase.trim)
   val wordCount = wordIterator.groupBy(identity).mapValues(_.size)
   
   println("These are the words from the file: ")
   for(word <- wordIterator)
	print(word + " ")
   
   println("\nThese are the frequencies of each word: ")
   for ((word, count) <- wordCount) 
	println("%s \t%d".format(word,count))

   wordsFromFile.close()
    
  }
  
}