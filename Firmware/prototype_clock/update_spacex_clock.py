#!/usr/bin/python

import requests
from bs4 import BeautifulSoup
import time
import calendar
from spyrk import SparkCloud

ACCESS_TOKEN = '' # access token redacted for security reasons
time_good = 0

response = requests.get('http://spacexstats.com')
soup = BeautifulSoup(response.text)
countdown_text = soup.find('time').string
# example of countdown_text is "10 Feb 2015 23:04:46 UTC"
print "Countdown Text: " + countdown_text

try: 
	countdown_time = time.strptime(countdown_text, "%d %b %Y %H:%M:%S %Z")
	time_good = 1
except ValueError:
	print "Error decoding the date and time"

if (time_good == 0):
	try:
		countdown_time = time.strptime(countdown_text, "%d %b %Y %Z")
		time_good = 2
	except ValueError:
		print "Error decoding just the date."
		
if (time_good != 0):
	countdown_time_unix = calendar.timegm(countdown_time)
	spark = SparkCloud(ACCESS_TOKEN)
	spark.TimeKeeper.setTZero(str(countdown_time_unix))
