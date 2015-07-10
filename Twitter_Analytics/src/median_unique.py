# Processing Data Files
# kksante
# 05JULY2015

# This program opens tweet.txt, reads it contents, determines the
# median of unique words used and writes the median results to ft2.txt

import sys # Used to handle inputs from command prompt
import os # Used to manipulate files and directories

# Variables to hold input and output filename passed from the prompt
in_file_name = sys.argv[1]
out_file_name = sys.argv[2]

# Input and output File Paths
inPath = os.path.join(os.pardir, "tweet_input")
outPath = os.path.join(os.pardir, "tweet_output")

# full path of each file
fpath = os.path.join(inPath, in_file_name)

# open each file for reading, read content
inFile = open(fpath, "r")

# create output file for writing
outFilePath = os.path.join(outPath, out_file_name)
outFile = open(outFilePath, "w")

# Function to determine median words in tweet.txt


def median(alist):
    copylist = alist[:] # use slice operator to make copy of list
    copylist.sort()
    if len(copylist) % 2 == 0: # even length
        rightmid = len(copylist) // 2
        leftmid = rightmid - 1
        median = (copylist[leftmid] + copylist[rightmid]) / 2
    else:
        mid = len(copylist) // 2
        median = copylist[mid]
    return median

num_uniqueWords = [] # track number of unique words in each tweet


for aline in inFile:
    values = aline.split()
    uniqueWords = [] # track unique words in each tweet
    for item in values:
        if item not in uniqueWords:
            uniqueWords.append(item)
    num_uniqueWords.append(len(uniqueWords))
    print >> outFile, "%5.4s" % (median(num_uniqueWords))

# close files
inFile.close()
outFile.close()
