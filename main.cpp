// PF ASSIGNMENT 01
// SUBMITTED TO: PROF. HINA TAHIR
// SUBMITTED BY: AQSA ISMAIL
// Roll Number: L1F25BSCS0055
// Section: B2
// Department: Computer Science

#include<iostream> 
#include<fstream>   
using namespace std;

// global variables 
// saved during login, used in calculate result
int gSerial = 0;        // serial number of logged in student
char gReg[50] = { '\0' }; // reg number of logged in student

int main()
{
    int choice; // store user menu choice

    while (1) // infinite loop program keeps running
    {
        // display main menu
        cout << "******************************" << endl;
        cout << "*     STUDENT PORTAL         *" << endl;
        cout << "******************************" << endl;
        cout << "* 1. Register                *" << endl;
        cout << "* 2. Log In                  *" << endl;
        cout << "* 3. Calculate Result        *" << endl;
        cout << "* 4. Print Result            *" << endl;
        cout << "* 5. Print All               *" << endl;
        cout << "******************************" << endl;
        cout << "Enter Choice: ";
        cin >> choice; // take choice from user
        cout << "******************************" << endl;

        //====================//
        //      REGISTER      //
        //====================//
        if (choice == 1)
        {
            cout << "******************************" << endl;
            cout << "*        REGISTER            *" << endl;
            cout << "******************************" << endl;

            char regnumber[50] = { '\0' }; // store student id entered by user
            char password[50] = { '\0' };  // store password entered by user
            char temp[100] = { '\0' };     // temporarily store each line from file
            int serial = 0;              // count total registrations for serial number

           
            ifstream countFile;
            countFile.open("reg.txt");

            // check if the file opened successfully
            if (!countFile.is_open())
            {
                // file does not exist - first time registration
                serial = 0;
            }
            else
            {
                // file exists - count total lines to get last serial number
                while (!countFile.eof()) // read until end of file
                {
                    countFile.getline(temp, 100); // read one line at a time
                    if (temp[0] != '\0') // ignore empty lines
                        serial++; // increment for each valid record
                }
                countFile.close(); // close file after reading
            }

            serial++; // assign new serial number to new student

           
            cout << "Enter Student ID: "; //take reg from user 
            cin >> regnumber;

           
            cout << "Enter Password: "; //take pass from user
            cin >> password;

            // open reg.txt in append mode to save student id
            ofstream regfile;
            regfile.open("reg.txt", ios::app); // ios::app add to end dont delete existing data

            // check if file opened successfully
            if (!regfile.is_open())
                cout << "* ERROR: File Not Found!     *" << endl;
            else
            {
                // save serial number and student id in reg.txt
            
                regfile << serial << " " << regnumber << endl;
                regfile.close(); 
            }

            // open pass.txt in append mode to save password
            ofstream passfile;
            passfile.open("pass.txt", ios::app);

            // check if file opened successfully
            if (!passfile.is_open())
                cout << "* ERROR: File Not Found!     *" << endl;
            else
            {
                // save serial number and password in pass.txt
                
                passfile << serial << " " << password << endl;
                passfile.close(); 
            }

            // display success message
            cout << "******************************" << endl;
            cout << "* Registration Successful!   *" << endl;
            cout << "******************************" << endl;
        }

                              //====================//
                             //       LOGIN        //
                            //====================//
        else if (choice == 2)
        {
            cout << "******************************" << endl;
            cout << "*         LOG IN             *" << endl;
            cout << "******************************" << endl;

            char loginID[50] = { '\0' };    // store student id entered by user
            char loginPass[50] = { '\0' };  // store password entered by user
            char fileID[50] = { '\0' };     // store student id read from reg.txt
            char filePass[50] = { '\0' };   // store password read from pass.txt
            char fileSerial[10] = { '\0' }; // store serial number from reg.txt
            char passSerial[10] = { '\0' }; // store serial number from pass.txt

            bool loggedin = false; // false = not logged in yet

            // keep asking until login successful or access denied
            while (!loggedin)
            {
                
                cout << "Enter Student ID: ";
                cin >> loginID;

                
                ifstream regfile;
                regfile.open("reg.txt");

                // check if file opened successfully
                if (!regfile.is_open())
                {
                    cout << "* ERROR: File Not Found!     *" << endl;
                }
                else
                {
                    bool idFound = false; // false = student id not found yet

                    
                    while (regfile.getline(fileSerial, 10, ' ') &&
                        regfile.getline(fileID, 50))
                    {
                        if (regfile.eof())
                           break; // stop at end of file

                        bool idMatch = true; // assume id matches

                        // compare entered id with file id char by char
                        int i = 0;
                        while (loginID[i] != '\0' && fileID[i] != '\0')
                        {
                            if (loginID[i] != fileID[i])
                            {
                                idMatch = false; // char does not match
                                break;
                            }
                            i++; // move to next char
                        }

                        // check if both char arrays ended at same position
                        if (idMatch && loginID[i] == '\0' && fileID[i] == '\0')
                        {
                            // student id matched!
                            cout << "* Student ID Found!          *" << endl;
                            idFound = true; // mark id as found

                            // convert serial from char array to integer
                            int s = 0;
                            int j = 0;
                            while (fileSerial[j] != '\0')
                            {
                                // build number digit by digit
                                // example: '1' - '0' = 1
                                s = s * 10 + (fileSerial[j] - '0');
                                j++; // move to next char
                            }
                            gSerial = s; // save serial globally for result

                            // save reg number globally for result
                            int k = 0;
                            while (loginID[k] != '\0')
                            {
                                gReg[k] = loginID[k]; // copy char by char
                                k++;
                            }
                            gReg[k] = '\0'; // end the char array
                            break; // stop reading file
                        }
                    }
                    regfile.close(); // close reg.txt

                    // if student id not found in file
                    if (!idFound)
                    {
                        cout << "******************************" << endl;
                        cout << "* ERROR: Student ID Wrong!   *" << endl;
                        cout << "* Try Again!                 *" << endl;
                        cout << "******************************" << endl;
                    }
                    else
                    {
                        int attempts = 0; // count wrong password attempts

                        // take password from user
                        cout << "Enter Password: ";
                        cin >> loginPass;

                        // allow maximum 3 password attempts
                        while (attempts < 3)
                        {
                            // open pass.txt to verify password
                            ifstream passfile;
                            passfile.open("pass.txt");

                            // check if file opened successfully
                            if (!passfile.is_open())
                            {
                                cout << "* ERROR: File Not Found!     *" << endl;
                                break;
                            }

                            bool passFound = false; // false = password not found yet

                            // read pass.txt line by line
                            while (passfile.getline(passSerial, 10, ' ') &&
                                passfile.getline(filePass, 50))
                            {
                                if (passfile.eof())
                                    break; // stop at end of file

                                bool serialMatch = true; // assume serial matches

                                // compare reg serial with pass serial
                                // to find password of same student
                                int k = 0;
                                while (fileSerial[k] != '\0' && passSerial[k] != '\0')
                                {
                                    if (fileSerial[k] != passSerial[k])
                                    {
                                        serialMatch = false; // serial does not match
                                        break;
                                    }
                                    k++;
                                }

                                // skip this record if serial does not match
                                if (!serialMatch)
                                    continue;

                                bool passMatch = true; // assume password matches

                                // compare entered password with file password
                                int i = 0;
                                while (loginPass[i] != '\0' && filePass[i] != '\0')
                                {
                                    if (loginPass[i] != filePass[i])
                                    {
                                        passMatch = false; // char does not match
                                        break;
                                    }
                                    i++;
                                }

                                // check if both char arrays ended at same position
                                if (passMatch && loginPass[i] == '\0' && filePass[i] == '\0')
                                {
                                    passFound = true; // password matched!
                                    break;
                                }
                            }
                            passfile.close(); // close pass.txt

                            // if password matched
                            if (passFound)
                            {
                                // display login successful message
                                cout << "******************************" << endl;
                                cout << "* LOGIN SUCCESSFUL!          *" << endl;
                                cout << "* Welcome " << loginID << endl;
                                cout << "******************************" << endl;
                                loggedin = true; // login done - exit while loop
                                break;
                            }
                            else
                            {
                                attempts++; // increment wrong attempt count

                                // if 3 attempts used - access denied
                                if (attempts == 3)
                                {
                                    cout << "******************************" << endl;
                                    cout << "* ACCESS DENIED!             *" << endl;
                                    cout << "* 3 Attempts Used!           *" << endl;
                                    cout << "******************************" << endl;
                                    loggedin = true; // exit while loop
                                }
                                else
                                {
                                    // show remaining attempts
                                    cout << "* Wrong Password!            *" << endl;
                                    cout << "* Attempts left: " << 3 - attempts << "           *" << endl;
                                    cout << "Enter Password: ";
                                    cin >> loginPass; // ask password again
                                }
                            }
                        }
                    }
                }
            }
        }

        //====================//
        //  CALCULATE RESULT  //
        //====================//
        else if (choice == 3)
        {
            // check if student is logged in
            // gSerial == 0 means no student logged in yet
            if (gSerial == 0)
            {
                // student not logged in - show error
                cout << "******************************" << endl;
                cout << "* Please Login First!        *" << endl;
                cout << "* Go to Option 2 - Log In    *" << endl;
                cout << "******************************" << endl;
            }
            else
            {
                // student is logged in - proceed to calculate result
                cout << "******************************" << endl;
                cout << "*    CALCULATE RESULT        *" << endl;
                cout << "******************************" << endl;

                float marks[5] = { 0 }; // store marks of 5 subjects
                float total = 0;      // store total of all marks
                float percentage = 0; // store final percentage

                // take marks of each subject from user
                cout << "Enter Marks of Subject 1 (out of 100): ";
                cin >> marks[0]; // store subject 1 marks
                cout << "Enter Marks of Subject 2 (out of 100): ";
                cin >> marks[1]; // store subject 2 marks
                cout << "Enter Marks of Subject 3 (out of 100): ";
                cin >> marks[2]; // store subject 3 marks
                cout << "Enter Marks of Subject 4 (out of 100): ";
                cin >> marks[3]; // store subject 4 marks
                cout << "Enter Marks of Subject 5 (out of 100): ";
                cin >> marks[4]; // store subject 5 marks

                // calculate total marks of all subjects
                for (int i = 0; i < 5; i++)
                    total = total + marks[i]; // add each subject marks to total

                // calculate percentage
                // formula: (total marks / maximum marks) * 100
                // maximum marks = 5 subjects * 100 = 500
                percentage = (total / 500.0) * 100;

                // open result.txt in append mode
                ofstream resultfile;
                resultfile.open("result.txt", ios::app);

                // check if file opened successfully
                if (!resultfile.is_open())
                    cout << "* ERROR: File Not Found!     *" << endl;
                else
                {
                    // save result in result.txt
                    // format: serial regNumber percentage
                    // example: 1 L1F25BSCS0055 79%
                    resultfile << gSerial << " " << gReg << " " << percentage << "%" << endl;
                    resultfile.close(); 
                }

                // display result on screen
                cout << "******************************" << endl;
                cout << "* Total Marks: " << total << "        *" << endl;
                cout << "* Percentage: " << percentage << "%      *" << endl;
                cout << "* Result Saved Successfully! *" << endl;
                cout << "******************************" << endl;
            }
        }

        //====================//
        //    PRINT RESULT    //
        //====================//
        else if (choice == 4)
        {
            // check if student is logged in
            if (gSerial == 0)
            {
                // student not logged in show error
                cout << "******************************" << endl;
                cout << "* Please Login First!        *" << endl;
                cout << "* Go to Option 2 - Log In    *" << endl;
                cout << "******************************" << endl;
            }
            else
            {
                cout << "******************************" << endl;
                cout << "*      PRINT RESULT          *" << endl;
                cout << "******************************" << endl;

                char resultSerial[10] = { '\0' };  // serial from result.txt
                char resultReg[50] = { '\0' };     // reg from result.txt
                char resultPercent[20] = { '\0' }; // percentage from result.txt

                // open result.txt for reading
                ifstream resultfile;
                resultfile.open("result.txt");

                // check if file opened successfully
                if (!resultfile.is_open())
                {
                    cout << "* ERROR: File Not Found!     *" << endl;
                }
                else
                {
                    bool found = false; // false = result not found yet

                    // read result.txt line by line
                    while (resultfile.getline(resultSerial, 10, ' ') &&
                        resultfile.getline(resultReg, 50, ' ') &&
                        resultfile.getline(resultPercent, 20))
                    {
                        if (resultfile.eof()) 
                            break; 

                        // convert serial number to int
                        int s = 0;
                        int j = 0;
                        while (resultSerial[j] != '\0')
                        {
                            // build number digit by digit
                            s = s * 10 + (resultSerial[j] - '0');
                            j++;
                        }

                        // match serial with logged in serial
                        if (s == gSerial)
                        {
                            found = true; // result found!

                            // display result
                            cout << "******************************" << endl;
                            cout << "* Serial: " << resultSerial << "              *" << endl;
                            cout << "* Reg No: " << resultReg << endl;
                            cout << "* Percentage: " << resultPercent << "       *" << endl;
                            cout << "******************************" << endl;
                            break; // stop reading file
                        }
                    }
                    resultfile.close(); // close file after reading

                    // if result not found
                    if (!found)
                    {
                        cout << "******************************" << endl;
                        cout << "* No Result Found!           *" << endl;
                        cout << "* Please Calculate Result    *" << endl;
                        cout << "* Go to Option 3             *" << endl;
                        cout << "******************************" << endl;
                    }
                }
            }
        }

        //====================//
        //     PRINT ALL      //
        //====================//
        else if (choice == 5)
        {
            cout << "******************************" << endl;
            cout << "*       PRINT ALL            *" << endl;
            cout << "******************************" << endl;

            char resultLine[100] = { '\0' }; // store each line from result.txt
            int counter = 1; // line counter for odd serial check

            // open result.txt for reading
            ifstream resultfile;
            resultfile.open("result.txt");

            // check if file opened successfully
            if (!resultfile.is_open())
            {
                cout << "* ERROR: File Not Found!     *" << endl;
            }
            else
            {
                // read file line by line
                while (!resultfile.eof())
                {
                    resultfile.getline(resultLine, 100);
                    if (resultLine[0] != '\0') // ignore empty lines
                    {
                        // print only odd serial records
                        // counter % 2 != 0 means odd number
                        if (counter % 2 != 0)
                        {
                            cout << "* " << resultLine << endl;
                        }
                        counter++; // increment counter
                    }
                }
                resultfile.close(); // close file after reading
            }
            cout << "******************************" << endl;
        }
    }

    return 0; // end of program
}