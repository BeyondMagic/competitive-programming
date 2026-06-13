import Text.Printf
import Data.List
import Data.Ord
import Data.Bits

str2int = map (\x -> read x :: Int) . lines

count x = length . filter (==x)

clean n xs = map (`count` xs) [1..n]

solve xs = sum $ zipWith min t (clean n b) where
-- solve xs = (t, clean n b) where
    n = head xs
    t = take n (tail xs)
    b = drop (2 + n) xs

main :: IO ()
main = do
    c <- getContents

    let r = str2int c
    print (solve r)
