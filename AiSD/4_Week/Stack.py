f = open('input.txt')
data = []
for line in f:
    data.append(line)

n = int(data[0])
mean = int(n / 2)
value_array = data[1].split(' ')
value_array = [float(item) for item in value_array]
index_array = [i for i in range(1, n + 1)]

for j in range(2, n + 1):
    i = j - 1
    value_array[i - 1]
    while i > 0 and value_array[i] < value_array[i - 1]:
        #insertion sort
        c = value_array[i - 1]
        value_array[i - 1] = value_array[i]
        value_array[i] = c
        #index change
        c = index_array[i - 1]
        index_array[i - 1] = index_array[i]
        index_array[i] = c
        i = i - 1

answer = [index_array[0], index_array[mean], index_array[n - 1]]
str1 = ' '.join(str(e) for e in answer)
f = open('output.txt', 'w')
f.write(str1)