print ("enter a no.")
a=int(input())
for i in range(2,(a)):
	if (a % i )==0:
		print ("{} is not a prime no.".format(a))
		print ("{} times {} is {}".format(i,(a//i),a))
		break
else:
	print ("{} is a prime no.".format(a))
				
