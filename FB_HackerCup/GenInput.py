def main():
    f= open("input.txt","w+")
    f.write("1\r\n")
    f.write("2000 1001\r\n")

    for i in range(1999):
        if i % 2 == 0:
            f.write("%d %d\r\n" % (0, i+2))
        else :
            f.write("%d %d\r\n" % (i+2, 0))
    f.write("0 0\r\n")
    f.close()   
    #Open the file back and read the contents
    #f=open("guru99.txt", "r")
    #   if f.mode == 'r': 
    #     contents =f.read()
    #     print contents
    #or, readlines reads the individual line into a list
    #fl =f.readlines()
    #for x in fl:
    #print x
if __name__== "__main__":
  main()

