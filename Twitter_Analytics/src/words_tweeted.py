# Processing Data Files
# kksante
# 05JULY2015

# This program opens tweet.txt, reads it contents, determines the
# frequency of the words used and writes the results to ft1.txt

import sys # Used to handle inputs from command prompt
import os # Used to manipulate files and directories

# Variables to hold input and output filename passed from the prompt
in_file_name = sys.argv[1]
out_file_name = sys.argv[2]

# Input and Output File Paths
inPath = os.path.join(os.pardir, "tweet_input")
outPath = os.path.join(os.pardir, "tweet_output")

# full path of each file
fpath = os.path.join(inPath, in_file_name)

# open each file for reading, read content
inFile = open(fpath, "r")

# create output file for writing
outFilePath = os.path.join(outPath, out_file_name)
outFile = open(outFilePath, "w")

# Procedure to count words in tweet.txt

countdict = {}

for aline in inFile:
    values = aline.split()
    for item in values:
        if item in countdict:
            countdict[item] = countdict[item] + 1
        else:
            countdict[item] = 1
wordList = list(countdict.keys())
wordList.sort()
print >> outFile, "%-30s %10s" % ("WORDS TWEETED", "FREQUENCY")

for item in wordList:
    print >> outFile, "%-30s %5s" % (item, countdict[item])

# close files
inFile.close()
outFile.close()
