import Text.Printf
import Data.Bits

listToInt = map (\x -> read x :: Int) . words

solve :: [Int] -> (Int, Int) -> (Int, Int)
solve xs (a, b)
    | null xs = (a, b)
    | x == 1  = solve t (a `xor` 1, b)
    | x == 2  = solve t (a `xor` 1, b `xor` 1)
    where
        x = head xs
        t = tail xs

main :: IO ()
main = do
    l1 <- getLine
    l2 <- getLine

    let n = read l1 :: Int
    let xs = listToInt l2

    let (ans1, ans2) = solve xs (0, 0)

    printf "%d\n%d\n" ans1 ans2
