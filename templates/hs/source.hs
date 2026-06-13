import Text.Printf
import Data.List
import Data.Ord
import Data.Bits

main :: IO ()
main = do
    l1 <- getLine
    l2 <- getLine

    let x = read l1 :: Double
    let y = read l2 :: Double

    printf "%.3f km/l\n" (x / y)
