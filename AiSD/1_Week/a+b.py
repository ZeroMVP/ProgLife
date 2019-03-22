f = open('input.txt')
data = []
for line in f:
    data.append(line)

array = data[0].split(' ')
array = [int(item) for item in array]
b = sum(array)
f = open('output.txt', 'w')
f.write(str(b))
