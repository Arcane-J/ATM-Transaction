#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
//--------------------Global Variables----------------------------------------------
int den[3]={0,0,0}, no[3]={0,0,0}, val[3]={0,0,0};
int f1 = 0, f2 = 0, f3 = 0;
int acct_no[5] = {101,102,103,104,105};
std::string acct_h[5] = {"Suresh","Ganesh","Magesh","Naresh","Harish"};
int acct_bal[5] = {25234,34123,26100,80000,103400};
int pin[5] = {2343,5432,7854,2345,1907};

using namespace std;

//Class atm for methods done on atm machine.................................................
class atm
{
public:
	
	void view();
	void insert();
	int update(int w);
	int update1(int w);
	void atm_bal(int a1,int b,int c);
}a;
//To insert Cash into the ATM
void atm:: insert()
{
	int d, n, v=0;
	cout << "\n--------------Load Cash-----------";
	t:
	cout << "\nEnter denomination: ";
	cin >> d;
	if (d != 2000 && d != 500 && d != 100)
	{
		cout << "\nOnly enter valid denominations! ";
		goto t;
	}
	cout << "\nEnter number of notes: ";
	cin >> n;
	v += d * n;
	for (int i = 0; i < 3; i++)
	{
		if (den[i] == d)
		{
			no[i] += n;
			val[i] += v;
			break;
		}
		else if (den[i] == 0)
		{
			den[i] = d;
			no[i] = n;
			val[i] = v;
			break;
		}
	}
	cout << "\n\nAmount Loaded!!";
	view();
}
//To vies the amount of denominations, number of notes and total cash present in the ATM ....
void atm::view()
{
	int total=0,size;
	size = sizeof(den)/sizeof(den[0]);
	cout << "\n\n-----------------------ATM-------------------------";
	cout << fixed << showpoint;
	cout << "\nDenomination" << setw(10) << "\tNumber" << setw(10) << "\tValue";
	for (int j = 0; j < size ; j++)
	{
		cout << "\n" << den[j] << setw(10) << "\t" << no[j] << setw(10) << "\t" << val[j];
		total += val[j];
	}
	cout << "\nTotal Amount in the ATM: " << total;
}
//To update the ATM Table when Withdrawal <= Rs5000..........
int atm::update(int w)
{
	int check;
	f1 = 0, f2=0, f3=0;
	
	int d[3], n[3];
	for (int j = 0; j < 3; j++)
	{
		d[j] = den[j];
		n[j] = no[j];

	}
	do
	{
		check = 0;

		if (w <= 5000)
		{
			if (w > 3000)
			{
				for (int i = 0; i < 3; i++)

				{
					if (d[i] == 2000 && n[i] >= 1)
					{

						do
						{
							n[i] -= 1;
							f1 += 1;
							w = w - 2000;
							
						} while (n[i] > 0 && w > 3000);

						

					
					}

					else if (d[i] == 2000 && n[i] < 2)
					{
						check = 1;
					}
				}


			}


			else if (w > 1000 && w <= 3000)
			{
				for (int i = 0; i < 3; i++)

				{
					if (d[i] == 500 && n[i] >= 1)
					{
						do
						{
							n[i] -= 1;
							f2 += 1;
							
							w = w - 500;

						} while (n[i] > 0 && w > 1500);
						
					}
					else if (d[i] == 500 && n[i] < 2)
					{
						check = 1;
					}


				}
			}
			else if (w <= 1500)
			{
				for (int i = 0; i < 3; i++)

				{
					if (d[i] == 100 && n[i] >= 10)
					{
						do
						{
							n[i] -= 1;
							f3 += 1;
							
							w = w - 100;

						} while (n[i] > 0 && w > 0);
						

					


					}
					else if (d[i] == 100 && n[i] < 10)
					{
						check = 1;
					}
				}
				break;
			}

		}

		}while (w > 0);
return check;
}
//To update the ATM Table when Withdrawal > Rs5000..........
int atm::update1(int w)
{
	int check;
	f1 = 0, f2 = 0, f3 = 0;

	int d[3], n[3];
	for (int j = 0; j < 3; j++)
	{
		d[j] = den[j];
		n[j] = no[j];

	}
	do
	{
		check = 0;

		if (w > 5000)
			{
				for (int i = 0; i < 3; i++)

				{
					if (d[i] == 2000 && n[i] >= 2)
					{

						do
						{
							n[i] -= 1;
							f1 += 1;
							w = w - 2000;
							
						} while (n[i] > 0 && w > 3000);

						


					}
					else if (d[i] == 2000 && n[i] < 1)
					{
						check = 1;
					}
				}
			}
			else if (w >= 1000 && w <= 5000)
			{
				for (int i = 0; i < 3; i++)

				{
					if (d[i] == 500 && n[i] >= 2)
					{
						do
						{
							n[i] -= 1;
							f2 += 1;
							
							w = w - 500;

						} while (n[i] > 0 && w > 1000);
						
					}
					else if (d[i] == 500 && n[i] < 1)
					{
						check = 1;
					}


				}
			}
			else if (w <= 1000)
			{
				for (int i = 0; i < 3; i++)

				{
					if (d[i] == 100 && n[i] >= 1)
					{
						do
						{
							n[i] -= 1;
							f3 += 1;
							
							w = w - 100;

						} while (n[i] > 0 && w > 0);
						

					}
					else if (d[i] == 100 && n[i] < 1)
					{
						check = 1;
					}
				}
				break;
			}

		
	} while (w > 0);
	return check;
}
//To Alter the Account Balance after Withdrawal..........
void atm::atm_bal(int a1,int b,int c)
{
	for (int i = 0; i < 3; i++)
	{
		if (den[i] == 2000)
		{
			no[i] -= a1;
			val[i] -= (a1 * 2000);
		}
		else if (den[i] == 500)
		{
			no[i] -= b;
			val[i] -= (b *500);
		}
		else if (den[i] == 100)
		{
			no[i] -= c;
			val[i] -= (c * 100);
		}
	}
}

//Class to house functions on User Accounts..........
class acct: public atm
{
public:
	
	int search();
	void opps();
	void display();
}h;
//To display the User Account Details..........
void acct::display()
{
	cout << fixed << showpoint;
	cout << "\nAcct No"<<setw(20)<<"\tAccount Holder"<<setw(20)<<"\tPin Number"<<setw(20)<<"\tAccount Balance";

	for (int i = 0; i < 5; i++)
	{
		cout << "\n" << acct_no[i] << left <<setw(12)<< "\t" << acct_h[i]<< setw(12) << "\t"  << pin[i] << setw(12)<< "\t"  << acct_bal[i];
	}
}
//To search for a Particular account using acct_no..........
int acct::search()
{
	int n, p,f=0;
x:
	cout << "\n\nEnter Account Number: ";
	cin >> n;
	cout << "\nEnter pin: ";
	cin >> p;
	for (int i = 0; i < 5; i++)
	{
		if (acct_no[i] == n && pin[i] == p)
		{
			return i;
			f = 1;
		}
	}
	if (f == 0)
	{
		cout << "\nEnter valid credentials!!";
		goto x;
	}

}
//Function for operations available in the ATM..........
void acct::opps()
{
	
			int c,w,i,flag=0,p,valid=1,acct_n,amt,check;
			i = search();
			do
			{
				cout << "\n\nATM OPERATIONS\n\n";
				cout << "\n\n1.Check Balance\n2.Withdraw Money\n3.Transfer Money\n4.Check ATM Balance\n5.Back to Main Menu";
				cout << "\nEnter your choice: ";
				cin >> c;
				
				switch (c)
				{
				case 1:
					//To display the account Balance..........
					cout << "\nYour Account Balance is: " << acct_bal[i];
					break;
				case 2: 
					//To Withdraw money from an Account	..........
				{	
					if (flag != 0)
					{
						v:
						cout << "\nRe-Enter Pin: ";									/*Re-enter pin for subsequent transactions*/
						cin >> p;
						if (pin[i] == p)
						{
							valid = 1;
						}
						else
						{
							cout << "\nEnter correct pin!";
							goto v;
						}
					}
					if (valid == 1)
					{
					y:
						cout << "\nEnter Amount to be Withdrawn(in multiples of 100): ";
						cin >> w;
						//To check whether the entered withdrawal amount is an excepted one.........
						if (w > 10000 || w < 100|| w%100!=0)
						{
							cout << "\n\nWithdrawal range is between Rs 100 and Rs 10,000 and a multiple of 100!";
							goto y;
						}
						else
						{
							//Check if Account has enough balance..........
							if (acct_bal[i] > w)
							{
								//Update function according to the withdrawal amount entered..........
								if (w > 5000)
								{
									check = update1(w);
									}
								else
								{
									check = update(w);
								}
								if (check==0)
								{
										acct_bal[i] -= w;
										atm_bal(f1, f2, f3);
										cout << "\nCollect your cash!" << endl;
										flag += 1;
								}
								else
								{
									cout << "\nInsufficient Balance in the ATM\nCome back later!" << endl;
								}
								break;
							}
							else
							{
								cout << "\n\nInsufficient Balance!!" << endl;
								break;
							}
						}
						valid = 0;
					}
					break;
				}
					
				case 3: 
					//Transfer money to another User in the User file..........
				{
					cout << "\n----------TRANSFER MONEY-----------";
					cout << "\nEnter Account no: ";
					cin >> acct_n;
					for (int j = 0; j < 5; j++)
					{
						if (acct_n == acct_no[j])
						{
							amtenter:
							cout << "\nEnter Amount: ";
							cin >> amt;
							if (amt > 10000 || amt < 1000)
							{
								cout << "\nThe amount should be between Rs 1000 and Rs 10,000";
								goto amtenter;
							}
							else
							{
								acct_bal[j] += amt;
								acct_bal[i] -= amt;
								cout << "\n\nAmount transferred successfully";
							}
						}
					}
					break;
				}
				case 4:
					//To view the ATM Balance..........
					view();
					break;
				case 5: break;
				default: cout << "\nEnter a valid option!!";
					break;
				}
			} while (c != 5);
}
//To Update userfile..........
void update_userfile()
{
	fstream users;
	users.open("userdetails.txt", ios::out |ios::binary);
	users << "Account No,Account Holder,Pin,Account Balance\n";
	for (int i = 0; i < 5; i++)
	{
		users << acct_no[i] << "," << acct_h[i] << "," << pin[i] << "," << acct_bal[i]<<"\n";
	}
	
	if (!users)
	{
		fstream temp;
		temp.open("temp.txt", ios::out);
		temp << "Account No,Account Holder,Pin,Account Balance\n";
		for (int i = 0; i < 5; i++)
		{
			temp << acct_no[i] << "," << acct_h[i] << "," << pin[i] << "," << acct_bal[i] << "\n";
		}
		remove("userdetails.txt");
		rename("temp.txt","userdetails.txt");
		
		temp.close();
	}
	
users.close();
	}
//To Update atmfile..........
void update_atmfile()
{
	fstream atmachine;
	atmachine.open("atm.txt", ios::out | ios::binary);
	atmachine << "Denomination,Number,Value\n";
	for (int i = 0; i < 3; i++)
	{
		atmachine << den[i] << "," << no[i] << "," << val[i] << "\n";
	}
	if (!atmachine)
	{
		fstream temp1;
		temp1.open("temp1.txt", ios::out);
		temp1 << "Denomination,Number,Value\n";
		for (int i = 0; i < 3; i++)
		{
			temp1 <<den[i] <<","<< no[i] <<"," << val[i] << "\n";
		}
		remove("atm.txt");
		rename("temp1.txt", "atm.txt");

		temp1.close();
	}

	atmachine.close();
}

int main()
{
	int choice;
	acct h;
	atm a;
	
	cout << "\n----------------------------------------------------------------\n                           WELCOME                             \n----------------------------------------------------------------";
	do
	{
		cout << "\n\n\nMAIN MENU\n1.Load Cash into ATM\n2.Customer Details\n3.ATM Operations\n4.Exit";
		cout << "\n\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1: a.insert();
			break;
		case 2: h.display();
			break;
		case 3: h.opps();
			break;
		
		case 4: update_userfile(); update_atmfile(); exit(0);
			break;

		default: cout << "\nEnter valid choice!!";
				break;
		}
	} while (choice != 5);
}
