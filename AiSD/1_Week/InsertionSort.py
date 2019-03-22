f = open('input.txt')
data = []
for line in f:
    data.append(line)

n = int(data[0])
array = data[1].split(' ')
array = [int(item) for item in array]
change_array = [1,]

for j in range(2, n + 1):
    i = j - 1
    array[i - 1]
    while i > 0 and array[i] < array[i - 1]:
        c = array[i - 1]
        array[i - 1] = array[i]
        array[i] = c
        i = i - 1
    change_array.append(i + 1)

str1 = ' '.join(str(e) for e in change_array)
str2 = ' '.join(str(e) for e in array)
f = open('output.txt', 'w')
f.write(str1)
f.write('\n')
f.write(str2)