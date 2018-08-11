import sys, os


for i in range(20):
    for j in range(3):
        for k in range(3):
            for l in range(1,3):
                for m in range(6):
                    print('echo "3 4 %s %s %s %s %s 1 1 1 3 2 1 1 1 "  | ./pr .' %(i, j, k, l, m))
                    os.system('echo "3 4 %s %s %s %s %s 1 1 1 3 5 1 3 1"  | ./pr .' %(i, j, k, l, m))


