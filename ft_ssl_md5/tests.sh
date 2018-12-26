make

echo "c5e433c1dbd7ba01e3763a9483e74b04" > toto
echo "pickle rick" | ./ft_ssl md5 > toto2
diff toto toto2

echo "Do not pity the dead, Harry.\n2d95365bc44bf0a298e09a3ab7b34d2f" > toto
echo "Do not pity the dead, Harry." | ./ft_ssl md5 -p > toto2
diff toto toto2

echo "e20c3b973f63482a778f3fd1869b7f25" > toto
echo "Pity the living." | ./ft_ssl md5 -q -r > toto2
diff toto toto2

echo "And above all," > file

echo "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a" > toto
./ft_ssl md5 file > toto2
diff toto toto2

echo "53d53ea94217b259c11a5a2d104ec58a file" > toto
./ft_ssl md5 -r file > toto2
diff toto toto2

echo "MD5 (\"pity those that aren't following baerista on spotify.\") = a3c990a1964705d9bf0e602f44572f5f" > toto
./ft_ssl md5 -s "pity those that aren't following baerista on spotify." > toto2
diff toto toto2

echo "be sure to handle edge cases carefully\n3553dc7dc5963b583c056d1b9fa3349c\nMD5 (file) = 53d53ea94217b259c11a5a2d104ec58a" > toto
echo "be sure to handle edge cases carefully" | ./ft_ssl md5 -p file > toto2
diff toto toto2

echo "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a" > toto
 echo "some of this will not make sense at first" | ./ft_ssl md5 file > toto2
diff toto toto2

echo "but eventually you will understand\ndcdd84e0f635694d2a943fa8d3905281\n53d53ea94217b259c11a5a2d104ec58a file" > toto
echo "but eventually you will understand" | ./ft_ssl md5 -p -r file > toto2
diff toto toto2

echo "GL HF let's go\nd1e3cc342b6da09480b27ec57ff243e2\nMD5 (\"foo\") = acbd18db4cc2f85cedef654fccc4a4d8\nMD5 (file) = 53d53ea94217b259c11a5a2d104ec58a" > toto
echo "GL HF let's go" | ./ft_ssl md5 -p -s "foo" file > toto2
diff toto toto2

echo "one more thing\na0bd1876c6f011dd50fae52827f445f5\nacbd18db4cc2f85cedef654fccc4a4d8 \"foo\"\n53d53ea94217b259c11a5a2d104ec58a file\nft_ssl: md5: -s: No such file or directory\nft_ssl: md5: bar: No such file or directory" > toto
echo "one more thing" | ./ft_ssl md5 -r -p -s "foo" file -s "bar" > toto2
diff toto toto2

echo "just to be extra clear\n3ba35f1ea0d170cb3b9a752e3360286c\nacbd18db4cc2f85cedef654fccc4a4d8\n53d53ea94217b259c11a5a2d104ec58a" > toto
echo "just to be extra clear" | ./ft_ssl md5 -r -q -p -s "foo" file > toto2
diff toto toto2

rm file

echo "https://www.youtube.com/watch?v=w-5yAtMtrSM" > big_smoke_order_remix
echo "a8dc621c3dcf18a8a2eddae1845e8e5f6498970a867056ac5f7121ac3d66cfd9" > toto
./ft_ssl sha256 -q big_smoke_order_remix > toto2
diff toto toto2

echo "SHA256 (\"wubba lubba dub dub\") = 23a0944d11b5a54f1970492b5265c732044ae824b7d5656acb193e7f0e51e5fa" > toto
./ft_ssl sha256 -s "wubba lubba dub dub" > toto2
diff toto toto2

rm big_smoke_order_remix
rm toto toto2
