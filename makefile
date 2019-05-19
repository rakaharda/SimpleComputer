all:
	g++ simplecomputer.cpp scmemory.cpp scterminal.cpp scbigChars.cpp scmyreadkey.cpp scsignal.cpp sc.cpp scprintscreen.cpp scrun.cpp -std=c++17 -o simplecomputer
simpleasm:
	g++ scmemory.cpp simpleasm.cpp -std=c++17 -o sat