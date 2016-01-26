import sys, random

def print_numbers(n, min_number, max_number):
    for i in range(n):
        num = random.randint(min_number, max_number)
        print(num)

    
if __name__ == '__main__':
    (program_name, n, min_number, max_number) = sys.argv
    print_numbers(int(n), int(min_number), int(max_number))

