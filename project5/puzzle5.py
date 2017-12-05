#!/usr/local/bin/python

wordList = [] 		#store words for the program to find
rowList = [] 		#stores the rows of the puzzle
columnList = []		#stores the columns of the puzzle
foundWordList = []	#will store all found words and the row/column number they were found at
notFoundList = [] 	#will eventually be populated by words not found

#this function finds words
def findWord(rowOrCol, inRow, number) :
	#conversion of rows and columns to strings
	rowColString = ""
	rowColString = "".join(rowOrCol)
	
	#iterate through words in wordList
	for word in wordList :
		if (word in rowColString) :
			if (inRow == True) :
				#appends the word and row number if the word is found in a row
				foundWordList.append(word + " row " + str(number))
			else : 
				#appends the word and row number if the word is found in a column
				foundWordList.append(word + " column " + str(number))
			#if a word is found, remove it from notFoundList, which initially contains all words
			notFoundList.remove(word)	
	



#puzzleFile reads the contents of puzzle.txt
#wordFile reads the contents of wordList.txt
puzzleFile = open('puzzle.txt','r')
wordFile = open('wordList.txt','r')

#words read from wordFile are stored in the wordList and notFoundList arrays.
for line in wordFile :
	wordString = line.split()  
	wordList.append(wordString[0])
	notFoundList.append(wordString[0])         

#lines from puzzle.txt appended to rowList
for line in puzzleFile :
	rowList.append(line.split())

#the size of the column is determined by the number of rows
columnSize = len(rowList[0])
#columnList is then populated.
for i in range(columnSize) :
	columnList.append( [ row[i] for row in rowList] )

#findWord searches for words in the rows
for index,row in enumerate(rowList) : 
	findWord(row,True,index)

#findWord searches for words in the columns
for count, column in enumerate(columnList) :
	findWord(column,False,count)


#Output
print("Words found : ")
for foundWord in foundWordList :
 	print(foundWord)
	
print("Not found list : ") 
for notFoundWord in notFoundList :
	print(notFoundWord)







