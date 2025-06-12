
# to print exceedly long intager:
import sys
sys.set_int_max_str_digits(0)

#import math.factorial as factorial
import math
def factorial(n): return math.factorial(n)

#try:
#    import fibo_cache as c
#    fibo_dict = c.dict
#catch: # this line is invalid python3
#    fibo_dict = {0: 0}
fibo_dict = {0: 0}
def fibonacci(n):
    # this will create the dictionary up to n - 300
    # max. resurse depth is 1000, and this creates 2 of each every time
    # if not: blows up at 502
    if n < 1: result = 0
    if n == 1: result = 1
    else:
        try: result = fibo_dict[n]
        except:
            result = fibonacci(n - 1) + fibonacci(n - 2)
            fibo_dict[n] = result
    return result

def superperm_max(n):
    if n < 1: raise ValueError('superperm_max() not defined for negative values')
    if n == 1: return 1
    if n == 2: return 3
    if n == 3: return 9
    return factorial(n) + factorial(n - 1) + factorial(n - 2) + factorial(n - 3) + n - 3

def superperm_min(n):
    if n < 1: raise ValueError('superperm_min() not defined for negative values')
    if n == 1: return 1
    if n == 2: return 3
    return factorial(n) + factorial(n - 1) + factorial(n - 2) + n - 3

def superperm_new(n):
    if n < 1: raise ValueError('superperm_new() not defined for negative values')
    if n == 1: return 1
    if n == 2: return 3
    # This return is heavily mathmatically optimized
    # to ignore bigint -> decimal translation happens
    # (div returns decimal, mul with decimal is decimal)
    # so the result keeps being precise
    return factorial(n - 2) * n * n + fibonacci(2 * (n - 3))

def copyright():
    print('''The new approach to get length of superpermutation is provided by
@ImLuni5 (video: https://youtu.be/lcRHHIjAdMI)

Source code created by Hoto Ras (hotoras03@gmail.com)''')

if __name__ == '__main__':
    reach = int(input('input the length of set to get superpermutation\'s length: '))
    print('preloading... ')#, reach > 30000 ? 'this should take time' : '')
    # This will preload the required amount of fibonacci
    # not to stack top out runtime exception.
    for i in range(100, 2 * reach + 1, 100):
        print(i, end='\r')
        fibonacci(i)
    print('fibonacci preload finished')
    validateonly = input('just validate? (yes, _no_): ')
    
    if validateonly != 'yes':
        print('min: ', superperm_min(reach))
        print('max: ', superperm_max(reach))
        print('new: ', superperm_new(reach))
        print()
    else:
        if superperm_min(reach) < superperm_new(reach): print('function valid for input ', reach)
        else:
            print('function invalid for input ', reach)
            print('''    expected to be larger than minimum formula
    but got smaller than one
''')
    copyright()

