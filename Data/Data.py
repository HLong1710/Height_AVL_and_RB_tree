import numpy as np
import json

# Tạo mảng ngẫu nhiên với 1 triệu phần tử
data = np.random.random_integers(0, 1000000000, 1000000)

# Sắp xếp mảng theo thứ tự tăng dần
#data = np.sort(data)
#data = data[::-1]

print(data[:])

for i in range(1, 11):
    with open(f'Data_Input_Array_{i}.txt', 'w') as filehandle:
        json.dump(data.tolist(), filehandle)