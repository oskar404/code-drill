-- Write a function that computes the list of the first 100 Fibonacci numbers.
-- By definition, the first two numbers in the Fibonacci sequence are 0 and 1,
-- and each subsequent number is the sum of the previous two. As an example,
-- here are the first 10 Fibonnaci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, and 34.

start :: [Integer]
start = [0, 1]

fibLen :: Int
fibLen = 10

fib :: Int -> Integer
fib n | n == 0 = 0 
      | n == 1 = 1  
      | n >= fibLen = fib (n-1) + fib (n-2)

main = do
    print fib fibLen


