#include "ShapeTwoD.h"
#include "Circle.h"
#include "Cross.h"
#include "Rectangle.h"
#include "Square.h"

vector<ShapeTwoD*> shape;
vector<ShapeTwoD*> shapecalculated;
int mainmenu() //print main menu
{
    int choice;
    cout << endl << "Student ID: 7083609" << endl;
    cout << "Student Name: Yong Jia Liang" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Welcome to Assn2 program!" << endl << endl;
    cout << "1)	Input sensor data" << endl;
    cout << "2)	Compute area(for all records)" << endl;
    cout << "3)	Print shapes report" << endl;
    cout << "4)	Sort shapes data" << endl;
    cout << "5)	Delete shapes (computed only)" << endl;
    cout << "9)	Exit" << endl << endl;
    cout << "Please enter your choice: ";
    cin >> choice;
    return choice;
}
void option1() // user select option 1 to input sensor data
{
    cout << endl << "[Input Sensor Data]" << endl;
    bool check = false;
    string name, type, tempname;
    while (check == false) //while loop make sure user enters correct name
    {
		cout << "Please enter name of shape: ";
		cin >> name;
        tempname = name;
        for_each(tempname.begin(), tempname.end(), [](char & c)
        {
            c = ::tolower(c);
        });
		//name = tolower(name);
		if(tempname == "cross" || tempname == "rectangle" || tempname == "square" || tempname == "circle")
		   	check = true;
		else
			cout << "Please enter shape." << endl;
	}
    check = false;
    while (check == false) //while loop make sure user enters correct type
    {
        cout << "Please enter special type: ";
        cin >> type;
        for_each(type.begin(), type.end(), [](char & c)
        {
            c = ::tolower(c);
        });
		//type = tolower(type);
		if(type == "ws" || type == "ns")
			check = true;
		else
			cout << "Please enter special type." << endl;
    }
    cout << endl;
    bool containsWarpSpace;
    if(type == "ws") //assign type as bool to variable containsWarpSpace
		containsWarpSpace = true;
	else
		containsWarpSpace = false;

    if (tempname == "circle") //if name is circle, user input x y and radius
    {
        int midx, midy, radius;
        shape.push_back(new Circle(name, containsWarpSpace));
        //Circle c (name, containsWarpSpace);
        cout << "Please enter x-oridinate of center: ";
		cin >> midx;
		cout << "Please enter y-oridinate of center: ";
		cin >> midy;
        cout << "Please enter radius(units): ";
		cin >> radius;
        //c.setData(midx, midy, radius);
        shape[(shape.size()-1)]-> setData2(midx, midy, radius);
        //shape.push_back(c);
    }
    else if (tempname == "square") //if name is square, user input vertices of 4 corners
    {
        int x[4];
        int y[4];
        shape.push_back(new Square(name, containsWarpSpace));
        for (int i = 0; i < 4; i++)
        {
            //while (check == true)
            //{
            //      check = true;
            cout << "Please enter x-ordinate of pt." << i+1 << ": ";
            cin >> x[i];
            cout << "Please enter y-ordinate of pt." << i+1 << ": ";
            cin >> y[i];
            /*
                for (int j = 0; j <= i; j++)
                {
                    if (i != j)
                    {
                        if (x[i] == x[j] && y[i] == y[j])
                        {
                            cout << "This co-ordinate has been repeated. Please enter another co-ordinate." << endl;
                            check = false;
                        }
                    }
                }
            }*/
        }
        shape[(shape.size()-1)]-> setData(x, y);
    }
    else if (tempname == "rectangle") //if name is rectangle, user input vertices of 4 corners
    {
        int x[4];
        int y[4];
        shape.push_back(new Rectangle(name, containsWarpSpace));
        for (int i = 0; i < 4; i++)
        {
            //while (check == true)
            //{
            //    check = true;
            cout << "Please enter x-ordinate of pt." << i+1 << ": ";
            cin >> x[i];
            cout << "Please enter y-ordinate of pt." << i+1 << ": ";
            cin >> y[i];
            /*    
                for (int j = 0; j <= i; j++)
                {
                    if (i != j)
                    {
                        if (x[i] == x[j] && y[i] == y[j])
                        {
                            cout << "This co-ordinate has been repeated. Please enter another co-ordinate." << endl;
                            check = false;
                        }
                    }
                }
            }*/
        }
        shape[(shape.size()-1)]-> setData(x, y);
    }
    else if (tempname == "cross") //if name is square, user input vertices of 12 corners
    {
        int x[12];
        int y[12];
        shape.push_back(new Cross(name, containsWarpSpace));
        for (int i = 0; i < 12; i++)
        {
            //while (check == true)
            //{
            //    check = true;
            cout << "Please enter x-ordinate of pt." << i+1 << ": ";
            cin >> x[i];
            cout << "Please enter y-ordinate of pt." << i+1 << ": ";
            cin >> y[i];
            /*
                for (int j = 0; j <= i; j++)
                {
                    if (i != j)
                    {
                        if (x[i] == x[j] && y[i] == y[j])
                        {
                            cout << "This co-ordinate has been repeated. Please enter another co-ordinate." << endl;
                            check = false;
                        }
                    }
                }
            }*/
        }
        shape[(shape.size()-1)]-> setData(x, y);
    }
    cout << endl << "Record successfully stored, Going back to main menu ..." << endl;
}
void option2() //user selects option 2
{
    if (shape.size() == 0) //if no un computed shapes
        cout << "You have not entered a shape." << endl;
    else
    {
        for (int i = 0; i < shape.size(); i++)
        {
            shapecalculated.push_back(shape[i]); //add to computed shape vector
            shapecalculated.back()->computeArea(); //computes the shape
        }
        cout << "Computation completed! (" << shape.size() << " records were updated)" << endl;
        shape.clear(); //after all shapes go to computed vector, clear un computed vector
    }
}
void option3() //user selects option 3
{
    if (shapecalculated.size() == 0) //if no computed shapes
        cout << "You have not entered a shape." << endl;
    else
    {
        cout << "Total no. of records available = " << shapecalculated.size() << endl << endl;
        for(int i = 0; i < shapecalculated.size(); i++)
        {
            cout << "Shape [" << i << "]" << endl;
			cout << shapecalculated[i]->toString() << endl; //print report for each shape
        }
    }
}
bool compareasc(ShapeTwoD *a, ShapeTwoD *b) //function to sort in ascending order
{
    return (a->getArea() < b->getArea());
}
bool comparedesc(ShapeTwoD *a, ShapeTwoD *b) //function to sort in descending order
{
    return (a->getArea() > b->getArea());
}
bool comparetype(ShapeTwoD *a, ShapeTwoD *b) //function to sort by type then descending order
{
    if(a->getType() != b->getType())
		return a->getType() == true;
	else
		return a->getArea() > b->getArea();
}
void option4() //user selects option 4
{
    string userinput;
    bool check = false;
	static int i = 0;
	if(shapecalculated.size() == 0) //if no computed shapes
		cout << "You have not input data" << endl;
	else
    {
        while (userinput != "q") //check if user inputs appropriate character
        {
        	cout << "\ta)\tSort by area (ascending)" << endl;
    		cout << "\tb)\tSort by area (descending)" << endl;
    		cout << "\tc)\tSort by special type and area" << endl << endl;
    		cout << "Please select sort option ('q' to go main menu): ";
    		cin >> userinput;
    		for_each(userinput.begin(), userinput.end(), [](char & c)
    		{
    		    c = ::tolower(c);
    		});

            if (userinput == "q") //do nothing to return to main menu
            {}
            else if (userinput == "a") //sort ascending order
            {
                cout << "Sort by area (smallest to largest)" << endl << endl;
                sort(shapecalculated.begin(), shapecalculated.end(), compareasc);
				for(int i = 0; i < shapecalculated.size(); i++)
				{
				    cout << "Shape [" << i << "]" << endl;
					cout << shapecalculated[i]->toString() << endl; //print shapes report
				}
                userinput = "q";
            }
            else if (userinput == "b") //sort descending order
            {
                cout << "Sort by area (largest to smallest)" << endl << endl;
                sort(shapecalculated.begin(), shapecalculated.end(), comparedesc);
				for(int i = 0; i < shapecalculated.size(); i++)
				{
				    cout << "Shape [" << i << "]" << endl;
					cout << shapecalculated[i]->toString() << endl; //print shapes report
				}
                userinput = "q";
            }
            else if (userinput == "c") //sort by type then descending order
            {
                cout << "Sort by special type (WS to NS) then area (largest to smallest)" << endl << endl;
                //sort(shapecalculated.begin(), shapecalculated.end(), comparedesc);
                sort(shapecalculated.begin(), shapecalculated.end(), comparetype);
				for(int i = 0; i < shapecalculated.size(); i++)
				{
				    cout << "Shape [" << i << "]" << endl;
					cout << shapecalculated[i]->toString() << endl; //print shapes report
				}
                userinput = "q";
            }
            else
            {
                cout << "Please select an option." << endl << endl; 
            }
		}
	}
}
void option5() //user selects option 5
{
    if(shapecalculated.size() == 0) //if no computed shapes
		cout << "You have not input data" << endl;
	else
    {
        int userinput;
        cout << "Enter shape number you wish to delete (computed shapes only): ";
        cin >> userinput;
        cout << endl;
        if (userinput > shapecalculated.size()) //if number greater than computed shapes
        {
            cout << "Shape number entered does not exist." << endl;
        }
        else
        {
            shapecalculated.erase(shapecalculated.begin() + userinput); //erase shape of user input
            cout << "Deleted shape [" << userinput << "]." << endl;
        }
    }
}
void safelydeallocatememory() //clears the 2 vectors when program exits
{
    shape.clear();
    shapecalculated.clear();
}
int main()
{
    bool exit = false;
	while (exit == false)
    {
        int option = mainmenu();
        switch (option)
        {
            case 1:
                option1();
                break;
            case 2:
                option2();
                break;
            case 3:
                option3();
                break;
            case 4:
                option4();
                break;
            case 5:
                option5();
                break;
            case 9:
                safelydeallocatememory();
                exit = true;
                break;
            default:
                cout << endl << "Please select an option. " << endl << endl;
                break;
        }
    }
    return 0;
}
