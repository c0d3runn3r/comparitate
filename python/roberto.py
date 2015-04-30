import datetime
import random

start = datetime.datetime.now()
letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

ar = []

for i in range(0,10000):
    ar.append(letters[random.randint(0,len(letters) - 1)] + letters[random.randint(0,len(letters)-1)] + letters[random.randint(0,len(letters)-1)] + letters[random.randint(0,len(letters)-1)])

ar.sort();

output = ''

for i in range(0,10000):
    output += ar[i] + '\n'

f = open('roberto_output.txt', 'w')
f.write(output)
f.close()

end = datetime.datetime.now() - start

print 'Elapsed time: ' + str(end.days*86400000 + end.seconds*1000 + end.microseconds/1000) + 'ms\n'
