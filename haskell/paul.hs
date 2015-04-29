import System.Random.MWC
import Control.Monad.Parallel as P
import Control.Monad as C
import Control.Monad.Primitive
import System.IO
import Data.ByteString as B
import Data.Word (Word8)
import Data.ByteString.Char8 as CB
import System.Environment (getArgs)
import Data.List as L (sort) 

c2w8 :: Char -> Word8
c2w8 = fromIntegral . fromEnum

rangeStart :: Word8
rangeStart = c2w8 'A'

rangeEnd :: Word8
rangeEnd = c2w8 'Z'

genString :: Int -> Gen (PrimState IO) -> IO B.ByteString
genString len g = do
	str <- C.replicateM len $ uniformR (rangeStart, rangeEnd) g
	return $ B.pack str

makeStrings :: Int -> Int -> IO [B.ByteString] 
makeStrings len nStrs = do
	withSystemRandom $ \gen ->
		C.replicateM nStrs $ do
			text <- genString len gen :: IO B.ByteString
			return text

main :: IO ()
main = do
	sortedStrs <- liftM L.sort $
		makeStrings 4 10000 
	withFile "strings.txt" WriteMode $ \f ->
		C.sequence_ $ Prelude.map (CB.hPutStrLn f) sortedStrs
