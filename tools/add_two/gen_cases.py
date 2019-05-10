import random

output_filename = './add_two_training.csv'

MIN = 0
MAX = 1000
NUM_CASES = 100

with open(output_filename, 'w') as fp:
    fp.write('input_1,input_2,input_3,output\n')
    for n in range(NUM_CASES):
        a = random.randint(MIN, MAX)
        b = random.randint(MIN, MAX)
        c = random.randint(MIN, MAX)
        fp.write(str(a) + ',' + str(b) + ',' + str(c) + ',' + str(a + b) + '\n')