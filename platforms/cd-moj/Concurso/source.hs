import Text.Printf
import Data.List (sortOn)
import Data.Ord (Down(..))

list2int :: String -> [Int]
list2int = map (\x -> read x :: Int) . words

solve n k = last . take k . sortOn Down

main :: IO ()
main = do
    l1 <- getLine
    l2 <- getLine

    let (n:k:_) = list2int l1
    let xs = list2int l2

    print (solve n k xs)
