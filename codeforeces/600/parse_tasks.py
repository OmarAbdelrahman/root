#!/usr/bin/python

import re
import requests
import sys
import os

number = os.getcwd().split(os.sep)[-1]

def parse_task(index):
	r = requests.get("http://codeforces.com/contest/" + number + "/problem/" +
					 index)
	s = r.text
	a = re.findall("Input</div><pre>.*?</pre>", s)
	b = re.findall("Output</div><pre>.*?</pre>", s)

	if (len(a) == 0):
		print "Something went wrong..."
		sys.exit(0)

	assert(len(a) == len(b))
	for i in xrange(len(a)):
		a[i] = a[i][16:-6].replace('<br />', '\n')
		b[i] = b[i][17:-6].replace('<br />', '\n')

	for i in xrange(len(a)):
		with open(index + "/in" + str(i) + ".in", "w") as f:
			print >> f, a[i]
		with open(index + "/out" + str(i) + ".out", "w") as f:
			print >> f, b[i]

r = requests.get("http://codeforces.com/contest/" + number)
s = r.text
a = re.findall("/contest/" + number + "/problem/.", s)
a = sorted(list(set(a)))
for x in a:
	print x
	parse_task(x[-1])
