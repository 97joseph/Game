BELOW IS THE PROGRAM
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class Student{
public:
bool seen;
string fname;
string lname;
Student(string fn, string ln){
seen = false;
fname = fn;
lname = ln;
}
};
class Cell{
public:
Student* stu;
Cell* nextCell;
};
class CList{
Cell first;
int cellCount = 0;
public:
void banner(){
std::ifstream infile("late.txt");
std::string line;
Cell prevCell;
while (std::getline(infile, line))
( g ( , ))
{
string fname, lname;
std::istringstream iss(line);
if (!(iss >> fname >> lname))
{
break;
} // error
cellCount = cellCount+1;
Student stu(fname,lname);
Cell c;
c.stu = &stu;
if(prevCell.stu == NULL){
prevCell = c;
first = c;
}
else
prevCell.nextCell = &c;
prevCell = c;
}
if(cellCount>0){
prevCell.nextCell = &first;
}
infile.close();
}
public:
void findLooser(){
if(cellCount==0){
cout << "Congratulations no one is late";
}
else if(cellCount == 1){
cout << "Looser: " + first.stu->fname +" "+first.stu->lname;
}
else{
Cell current = first;
int lnameLength = 0;
while(1){
lnameLength = current.stu->lname.length();
current = giveNCell(current,lnameLength);
if(current.stu->seen == true)
{
cout << "Looser: "+ current.stu->fname +" "+current.stu->lname;
break;
}
else{
current.stu->seen = true;
}
}
}
}
Cell giveNCell(Cell startCell, int n){
Cell* pointer;
for(int i=0;i<n;i++){
pointer = startCell.nextCell;
}
return *pointer;
}
}
};
int main()
{
CList cl;
cl.banner();
cl.findLooser();
return 0;
}
