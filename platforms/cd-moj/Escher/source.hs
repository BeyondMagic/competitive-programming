import Text.Printf
import Data.List
import Data.Ord
import Data.Bits

list2int :: String -> [Int]
list2int = map (\x -> read x :: Int) . words

form :: Bool -> Char
form k
    | k         = 'S'
    | otherwise = 'N'

solve n xs = all (==n) ls where
    ls = zipWith (+) xs $ reverse xs
    n = head ls

main :: IO ()
main = do
    l1 <- getLine
    l2 <- getLine

    let n = read l1 :: Int
    let xs = list2int l2

    printf "%c\n" (form $ solve n xs)
