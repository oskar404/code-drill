-- Write a function that combines two lists by alternatingly taking elements.
-- For example: given the two lists [a, b, c] and [1, 2, 3], the function should
-- return [a, 1, b, 2, c, 3].

l1 :: [String]
l1 = ["a", "b", "c"]

l2 :: [Int]
l2 = [1, 2, 3]

concatenate :: [String] -> [Int] -> [String]
concatenate [] [] = []
concatenate (a:as) (i:is) = [a] ++ [(show i)] ++ concatenate as is

main = do
    print (concatenate l1 l2)

