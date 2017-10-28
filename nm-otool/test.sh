make

./ft_nm /bin/bash > yo
nm /bin/bash > yo2
./ft_otool /bin/bash > yoyo
otool -t /bin/bash > yoyo2
diff yo yo2
diff yoyo yoyo2

./ft_nm tests/test_facile tests/test_facile_32 tests/test_facile_fat > yo
nm tests/test_facile tests/test_facile_32 tests/test_facile_fat > yo2
./ft_otool tests/test_facile tests/test_facile_32 tests/test_facile_fat > yoyo
otool -t tests/test_facile tests/test_facile_32 tests/test_facile_fat > yoyo2
diff yo yo2
diff yoyo yoyo2

./ft_nm tests/test_moins_facile tests/test_moins_facile_32 tests/test_moins_facile_fat > yo
nm tests/test_moins_facile tests/test_moins_facile_32 tests/test_moins_facile_fat > yo2
./ft_otool tests/test_moins_facile tests/test_moins_facile_32 tests/test_moins_facile_fat > yoyo
otool -t tests/test_moins_facile tests/test_moins_facile_32 tests/test_moins_facile_fat > yoyo2
diff yo yo2
diff yoyo yoyo2