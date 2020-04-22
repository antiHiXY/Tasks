#The task:

Calculate the accumulated moving average and standard deviation for a numerical series from a .tsv file.

Example: let a number series be given 1, 2, 3:

Moving Average:

SMA [1] = 1 = 1
SMA [2] = (1 + 2) / 2 = 1.5
SMA [3] = (1 + 2 + 3) / 3 = 2

Standard deviation:

STD_DEV [1] = 0
STD_DEV [2] = sqrt (((1 - 1.5) ^ 2 + (2 - 1.5) ^ 2) / (2 - 1)) = 0.7071068
STD_DEV [3] = sqrt (((1 - 2) ^ 2 + (2 - 2) ^ 2 + (3 - 2) ^ 2) / (3 - 1)) = 1
Provide a numerical answer for lines with numbers: 1, 100, 1000000, 500000000