g++ -c main.cpp -o main.o -ILibrary/include
g++ -c button.cpp -o button.o -ILibrary/include
g++ main.o button.o -o main -LLibrary/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system 
Remove-Item main.o, button.o -Force
.\main.exe









