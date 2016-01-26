import sys

if __name__ == '__main__':
    numbers = sys.stdin.readlines()
    sum = 0
    for n in numbers:
        sum += int(n)
        
    print(sum)
