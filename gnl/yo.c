// LIGNE 1 \\

swap = "abcdefghijklm\0"
ret = 7
buf = "abcdefg\0"
*line = "abcdefg\0"
fd = "test"
nblines = 0

start = 7
len = 7

read = "abcdefg\nhijklm"


// LIGNE 2 \\

swap = "abcdefghijklmnopqr\0"
ret = 7
buf = "n\nopqr\0"
*line = "hijklmno\0"
fd = "test"
nblines = 0

start = 8
len = 8

read = "abcdefg\nhijklmn\nopqr"

// LIGNE 3 \\

swap = "abcdefghijklmnopqr\0"
ret = 0
buf = "\0"
*line = "abcdefghijkl\0"
fd = "test"
nblines = 1;

start = 0
len = 7

read = "abcd\nefg\nhijkl\0"
