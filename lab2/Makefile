#compile and link the application
all: clean main run

#run the application
run: main
	cls
# windows
	@main.exe
# linux
# @./main

#link main.o and student.o to executable main
main: main.o student.o domesticstudent.o toeflscore.o internationalstudent.o studentsort.o
# windows
	g++ -g -o main.exe main.o toeflscore.o internationalstudent.o domesticstudent.o student.o studentsort.o
# linux
# g++ -g -o main main.o student.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp
#g++ -g -c testcompare.cpp -o main.o

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c student.cpp

domesticstudent.o: domesticstudent.cpp
	g++ -g -c domesticstudent.cpp

internationalstudent.o: internationalstudent.cpp
	g++ -g -c internationalstudent.cpp

toeflscore.o: toeflscore.cpp
	g++ -g -c toeflscore.cpp

studentsort.o: studentsort.cpp
	g++ -g -c studentsort.cpp

#remove built files
clean:
# windows
	del /Q *.exe *.o
# linux
# rm -rf main main.o student.o *~
