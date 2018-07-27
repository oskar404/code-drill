-- Write three functions that compute the sum of the numbers in a given list
-- using a for-loop, a while-loop, and recursion.

l1 :: [Int]
l1 = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]

-- Function using recursion (This is quite native for Haskell)
recursion :: [Int] -> Int
recursion []        = 0
recursion (x:xs)  = x + recursion xs

result1 = recursion l1

-- Function using for-loop and while-loop are not really native to Haskell.
-- For now they will be ignored. But there are other possibilities

result2 = sum l1

main = do
    putStrLn ("recursion: " ++ (show result1))
    putStrLn ("sum: " ++ (show result2))
