#!/usr/bin/env python
# -*- coding: utf-8 

import time

#pidDict = {}

def log_statistic(logFile= 'media_search1.log'):

	timeStart = 0.0
	timeEnd = 0.0

	newCount = 0
	dataCount = 0.0
	flowCount = 0

	isVideo = True
	isFirstLine = True

	with open(logFile) as f:

		for line in f.readlines():
			#new flow count
			if('NEW Flow' in line):
				newCount = newCount+1
				if(isFirstLine):
					#print(line[0:19])
					timeStart = time.mktime(time.strptime(line[0:19], '%Y-%m-%d %H:%M:%S'))
					isFirstLine = False
				timeEnd = time.mktime(time.strptime(line[0:19], '%Y-%m-%d %H:%M:%S'))
				continue
			#pcm data count
			if('PCM data size' in line):
				isVideo = False
				flowCount = flowCount+1
				tokens = line.split()
				#print(tokens[-5][0:-1])
				dataCount += int(tokens[-5][0:-1])
				timeEnd = time.mktime(time.strptime(line[0:19], '%Y-%m-%d %H:%M:%S'))
				continue
			#frame count
			if('count' in line):
				flowCount = flowCount+1
				tokens = line.split()
				#print(tokens[-5][0:-1])
				dataCount += int(tokens[-5][0:-1])
				timeEnd = time.mktime(time.strptime(line[0:19], '%Y-%m-%d %H:%M:%S'))
				continue

	print("duration: %f"% (timeEnd - timeStart))
	print("new flow per minute: %f" % (newCount / (timeEnd - timeStart)))

	if(isVideo):
		print("VIDEO new flow: %d, flowCount: %d, frameCount: %d, framePerFlow: %f"%(newCount,flowCount,dataCount,dataCount/flowCount))
	else:
		print("AUDIO new flow: %d, flowCount: %d, dataCount: %d (%f)M, dataPerFlow: %f (%f)M"%(newCount,flowCount,dataCount,
			dataCount/1024/1024,dataCount/flowCount,dataCount/flowCount/1024/1024))
			#time.mktime(time.strptime('2018-08-21 11:29:58', '%Y-%m-%d %H:%M:%S'))

if __name__ == "__main__":

	try:
		log_statistic()
	except IOError:
		print("IO ERROR")

