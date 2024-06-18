@echo off

set MAIN="test_structures.cpp"
set STRUCTURES="map/simple_map.cpp"
set TEST_PROG="test.exe"

g++ "%MAIN%" "%STRUCTURES%" -o "%TEST_PROG%"

test.exe