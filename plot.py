import matplotlib.pyplot as plt
import pandas as pd
import os

df = pd.read_csv("time_analysis.csv")
os.system("g++ sorting_analysis.cpp;./a.out")
# print(df)
# df.plot(x = "Array Size", kind = "scatter", y = "MergeSort (µs)",subplots = True)
# df.plot(x = "Array Size", kind = "scatter", y = "QuickSort (µs)", subplots = True)
# plt.scatter(x = df["Array Size"],y = df["MergeSort (µs)"], c='b')
# plt.scatter(x = "Array Size",y = "MergeSort (µs)", c='r')
ax = df.plot(kind='scatter', x = "Array Size", y = "MergeSort (µs)",
                color='DarkBlue', label='MergeSort')

df.plot(kind='scatter', x = "Array Size", y = "QuickSort (µs)",
        color='DarkGreen', label='QuickSort', ax=ax)

plt.ylabel("Time in microsecond")        
plt.legend(loc='upper left')
plt.show()