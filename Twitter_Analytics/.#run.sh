#!/usr/bin/env bash

# This shell script will run python code to analyze tweet feeds
# Python is call at the command promt passing three variables
# first the python code to the be run, second the text file to
# analyze and lastly the name of the output file to write the
# results in. 

cd src
python words_tweeted.py tweets.txt ft1.txt
python median_unique.py tweets.txt ft2.txt

