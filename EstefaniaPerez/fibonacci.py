def Fibonacci(n):
    if n<= 0:
        print("Incorrect input")
    # First Fibonacci number is 0
    elif n == 1:
        return 0
    # Second Fibonacci number is 1
    elif n == 2:
        return 1
    else:
        return Fibonacci(n-1)+Fibonacci(n-2)

def is_prime(num):
    if num < 1:
        return False
    elif num == 2:
        return True
    else:
        for i in range(2, num):
            if num % i == 0:
                return False
        return True
    
def list_fibonacci_prime(n):
    fibonacci_primes_list = []
    for i in range(1, n+1):
        fib_num = Fibonacci(i)
        if is_prime(fib_num):
            fibonacci_primes_list.append(fib_num)
    return fibonacci_primes_list


if __name__ == '__main__':
    max_fib_number = max(list_fibonacci_prime(100))
    sum = 0
    for digit in str(max_fib_number):
        sum += int(digit)
    print(sum)

