f = open('input.txt')
data = []
for line in f:
    data.append(line)

array = data[0].split(' ')
array = [int(item) for item in array]
b = array[0] + (array[1])*(array[1])
f = open('output.txt', 'w')
f.write(str(b))