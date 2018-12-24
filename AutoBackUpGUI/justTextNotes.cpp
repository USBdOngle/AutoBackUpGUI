//This file is just for logging results when testing performance of program and any other things I may want to take note of

//Dec 22, 2018
/*
-Backend code hasn't been improved since GUI has been worked on, 
 I want to determine lost time when using program versus just manually copying files in windows

 -TEST 1 
 + 4.23GB folder containing 1,303 files, 64 folders
 + Source and destination on local 1TB 7200rpm HDD
 + Running from visual studio in Release mode
 + RESULTS: 
		Program:	Windows CtrlC/V:
	T1	1m18s		1m12s
	T2  1m17s		1m13s
	T3  1m18s		1m16s
	
   AVG  1m17.7s     1m13.7s -> 5.28% slower

-TEST 2
+ same conditions as TEST 1
+ source and destination now on local 240GB Sata SSD
+ RESULTS:
		Program:	Windows CtrlC/V:
	T1  55s			1m47s			 ***unexpcted result will restart system and see if time is consistent***
	T2	46s			16s				 ***restarting increased speeds, will ignore first test***
	T3  19s			11s
	T4	20s			33s

   AVG  28.3s       20s -> 34.4% slower

-TEST 3
+ same conditions as TEST 1 and TEST 2
+ source 240gb Sata SSD, destination 1TB 7200RPM HDD
+ RESULTS:
		Program:	Windows CtrlC/V:
	T1  33s			26s
	T2	25s			24s
	T3  25s			24s

   AVG 27.7s        24.7s -> 11.4% slower

 -Conclusion
 + For Test 1 the transfer speeds were very consistent and copy + paste manually was faster as expected
 + Efficiency of program vs manual copy was much better than expected, 5.28% is not a big loss in time

 + For Test 2 transfer speeds were extremely inconsistent making it hard to conclude much
 + Program was 34.4% slower on average but with the limiting testing (due to wanting to preserve my SSD)
   I cannot confidently say what the performance is in the long run
 + Since the performance was unpredicatble for manual copy as well I can only assume the majority of speed variations is
   due to the SSD and not the program
 
 + Test 3 provided consistent results again which further implies that an internal SSD transfer is being affected by something other than the program
 + Performance is about twice as slow as TEST 1 at 11.4% more time than manual copy but still an acceptable result but T1 of Test 3 is a bit of an outlier so further 
   testing may yield a smaller discrepancy but due to hardware limitations I don't want to test more

-TODO
+ Although I am happy with performance I want to try and bring the programs performance closer to the systems manual performance
+ For my first set of optimizations I am going to focus on fileToCopyDetector as the storage class for holding data could be optimized as well as some
  other local functions.
*/

//Dec 23, 2018
/*
-Changed the QMultiMap class that was used to store the directories being watched and files to determine which files were added to 
 a directory to a QHash with key=directory and element=QHash where the keys were the files in each directory.
-QMultiMap is based on red-black trees and provides logarithmic lookups for the directories and possible linear time lookups for the files contained in each directory.
 My QHash implementation should provide closer to constant time lookups.
-I will be repeating test 1 and test 3 from past entry including the manual transfer incase anything has happened on the system since the last test that could affect performance
 outside of the programs control

-TEST 1
 + 4.23GB folder containing 1,303 files, 64 folders
 + Source and destination on local 1TB 7200rpm HDD
 + Running from visual studio in Release mode
 + RESULTS:
		Program:	Windows CtrlC/V:
	T1	1m18s		1m18s
	T2  1m17s		1m16s
	T3  1m16s		1m14s

   AVG  1m17s		1m16s -> 1.31% slower

-TEST 3
+ same conditions as TEST 1
+ source 240gb Sata SSD, destination 1TB 7200RPM HDD
+ RESULTS:
		Program:	Windows CtrlC/V:
	T1  34s			26s
	T2	28s			24s
	T3  25s			24s

   AVG 27.7s        24.7s -> 11.4% slower
*/