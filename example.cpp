/* 
 *  Song Manager: example.cpp
 *  Author: Manuel Rojas
 *
 */

#include <iostream>
#include "Songs.h"
#include <list>
#include <string>
#include <fstream>
#include "SongsContainer.h"
#include "example.h"
using namespace std;


void Example::Run () 
		{
			list < TSong > SongList;
		
			list < TSong >::iterator mLocation;
		
			int selection = 0;
		
			string filename;
		
			char answer, modify;
		
			ifstream infile;
		
			ofstream outfile;
		
			string mp3, s1, s2, s3;
		

			// Since we need to load the songlist every time the program
			// is executed, we open the file "sl.txt" and load the songlist
				
			filename = "sl.txt";
		
			cin.tie (&cout);
		
			infile.open (filename.c_str ());
		
			infile >> SongList;
		
			infile.close ();
		


			while (selection != 10)
					{
						

			cout << endl;
						
			cout << "Selections:" << endl << endl;
						
			//textcolor(2);
			cout << "	/////,^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;				
			cout << "	o^ %xxxx333333oo33oo3o33333333333oo  /" << endl;
			cout << "	u  M                              M  /" << endl;						
			cout << "	u  M 1 - Add a Song               M  /" << endl;						
			cout << "	u  M 2 - Delete a Song            N  ," << endl;						
			cout << "	u  M 3 - Modify a Song            H  ," << endl;						
			cout << "	u^ M 4 - Search by Title          H  ," << endl;					
			cout << "	u^ M 5 - Search by Composer       H  ," << endl;					
			cout << "	u^ M 6 - Search by Performer      H  ," << endl;						
			cout << "	u^ M 7 - Search by Genre          H  ," << endl;						
			cout << "	u^^M 8 - Search by Length         H  ," << endl;					
			cout << "	u^^M 9 - List Songs               H  ^" << endl;					
			cout << "	u^^M                              H  ^" << endl;						
			cout << "	X^^Nyyyyyyyyyyyyyyyy88888888888888M  ^" << endl;						
			cout << "	X,,,^^^^^^^^^                        ^" << endl;					
			cout << "	X,,,,,^^^^^^^^                       ^" << endl;						
			cout << "	X,,,,,^^^^^^^^   ^^^^                ^" << endl;				
			cout << "	X,,,,,,^^^^^^,///,//////,            ^" << endl;				
			cout << "	X,,,,,,,^^,///(<<<<<<<<</(/^         ^" << endl;						
			cout << "	X,,,,,,,,/<<(<<<<<<<<<<<<(<</        ^" << endl;						
			cout << "	X,/,,,,,(&<<<<<&&////<&&<<<&&/       ^" << endl;						
			cout << "	X///,,,/&&&&%%&/      /&&<<&&&^      ^" << endl;						
			cout << "	X//////<(//%%%%        <%%%////      ^" << endl;						
			cout << "	X//////<%ooooo3^       %ooooo%/      ," << endl;						
			cout << "	X///////o3333333<,^^^/o333oo33,      ," << endl;						
			cout << "	8///////<33333333333333333333/^^     ," << endl;						
			cout << "	8/////////%333xxxxxxxxxx333%/^^^^^   ," << endl;						
			cout << "	8/<<(///////&3xxx%%o%xx3o&/,^^^^^^^  ," << endl;						
			cout << "	y(<<<</////////(<&&&<<//,,,^^^^^^^^^ /" << endl;						
			cout << "	y<<<<<<//////////////,,,,,,,,^^^^^^^^/" << endl;					
			cout << "	 8(<<<<<(//////////////,,,,,,,,^^^^^^^<" << endl;		
			cout << " 	 uu3o%%%&&<<<<<<(/////////////////CJ<^" << endl;
			cout << " 	 ^,,////////////////////////////,,^^" << endl;
						
			cin >> selection;
						

			cout << endl;
						

			switch (selection)
				{
			
						// Add a song - We call the input subroutine which will
						// ask the user to enter the song "components". Once the 
						// types them in, the we will push it to the back of the list
						// and set the location to the end of the list as well.
				case 1:
								{	
									TSong tsong;
					
									tsong.input ();
					
									SongList.push_back (tsong);
					
									mLocation = SongList.end ();
					
									break;
								}
			

						// Delete a song - We need to ask the user the name of the
						// song to be deleted so we use the iterator to find the song
						// that matches the title. Once the song is found, we ask the user
						// to confirm the deletion    
				
				case 2:
								{
					
									cout << "Please type the song's ";
					
									char cTitle[240];
					
									cout << "Title: ";
					
									cin >> ws;
					
									cin.getline (cTitle, 240);
					
									string sTitle (cTitle);
					

									for (list < TSong >::iterator location = SongList.begin ();
												 location != SongList.end (); location++)
							
											if (sTitle == (*location).GetTitle ())
												{
				
													(*location).display ();	
													cout << "Are you sure you want to delete this song? y/n" << endl;
				
													cin >> answer;
				

													switch (answer)
																	{
																		case 'Y':
						
																		case 'y':
																							SongList.erase (location);
								
																		cout << "The song has been deleted" << endl;
								
																		break;
						
																		case 'N':
						
																		case 'n':
																							break;
						
																		default:
																							cout << "Sorry, that is not a correct option" << endl;
																	}
													break;
											}	
			
							}
			
							break;
			
						// Modify a song - In order to modify a song, we need to ask the user what
						// component will be modified. We use the iterator to look through the list
						// and find the component that matches the user's request. Once is found. We 
						// prompt the user to type the new component, and store it in the character array 
				case 3:
								{
									char cTitle[240];
					
									char cComposer[240];
					
									char cPerformer[240];
					
									char cLength[240];
					
									char cGenre[240];
					

									cout << "Please type song's ";
					
									cout << "Title: ";
					
									cin >> ws;
					
									cin.getline (cTitle, 240);
					
									string sTitle (cTitle);
					

									for (list < TSong >::iterator location = SongList.begin ();
													 location != SongList.end (); location++)
							
											if (sTitle == (*location).GetTitle ())
												{
				
													(*location).display ();
				

													cout << "What would you like to change?" << endl;
				
													cout << "1). Title" << endl;
				
													cout << "2). Composer" << endl;
				
													cout << "3). Performer" << endl;
				
													cout << "4). Genre" << endl;
				
													cout << "5). Length" << endl;
				
													cin >> modify;
				

													switch (modify)
																{
																	case '1':
																						{
																							cout << "Please type a new Title: ";
			
																							cin >> ws;
			
																							cin.getline (cTitle, 240);
			
																							string sTitle (cTitle);
			
																							(*location).SetTitle (sTitle);
								
																						}
								
																	break;

																	case '2':
																						{
																							cout << "Please type a new Composer: ";
			
																							cin >> ws;
			
																							cin.getline (cComposer, 240);
			
																							string sComposer (cComposer);
			
																							(*location).SetComposer (sComposer);
								
																						}
								
																	break;
						

																	case '3':
																						{
																							cout << "Please type a new Performer: ";
			
																							cin >> ws;
			
																							cin.getline (cPerformer, 240);
			
																							string sPerformer (cPerformer);
			
																							(*location).SetPerformer (sPerformer);
								
																						}
								
																	break;
						


																	case '4':
																						{
																							cout << "Please type a new Genre: ";
			
																							cin >> ws;
			
																							cin.getline (cGenre, 240);
			
																							string sGenre (cGenre);
			
																							(*location).SetGenre (sGenre);
								
																						}
								
																	break;
						


																	case '5':
																						{
																							cout << "Please type a new Length: ";
			
																							cin >> ws;
			
																							cin.getline (cLength, 240);
			
																							string sLength (cLength);
			
																							(*location).SetLength (sLength);
								
																						}
								
																	break;
						
																}
		
												}
			
								}
			
				break;
			

						// Search by Title - We prompt the user to type the song title he wants
						// to search for. Then we use the iterator to find the match for that 
						// title and we finally display it on the screen. The same process is 
						// donde to look by Composer, Performer, Genre and Length
				case 4:
								{		
								char cTitle[240];
					
								cout << "Title: ";
					
								cin >> ws;
					
								cin.getline (cTitle, 240);
					
								string sTitle (cTitle);
					

								for (list < TSong >::iterator location = SongList.begin ();
											 location != SongList.end (); location++)
							
										if (sTitle == (*location).GetTitle ())
											{
												(*location).display ();
												//break;
												cout << "Woul you like to play this song?";
				
												cin >> answer;
				
												switch (answer)
															{
																case 'Y':
						
																case 'y':
																					cout << "yes" << endl;
								
																					s1 = "mplayer";
								
																					s2 = sTitle + ".mp3";
								
																					s3 = s1 + " " + s2;
								
																					system (s3.c_str ());

																break;
						
																case 'N':
						
																case 'n':
																					cout << "no " << endl;		
																break;
						
															}
		
											}
			
							}
			
			break;
	

			case 5:
							{			
								char cComposer[240];
					
								cout << "Composer: ";
					
								cin >> ws;
					
								cin.getline (cComposer, 240);
					
								string sComposer (cComposer);
					
								for (list < TSong >::iterator location = SongList.begin ();
											 location != SongList.end (); location++)
							
										if (sComposer == (*location).GetComposer ())
											{
												(*location).display ();
												break;
		
											}
			
							}
			
			break;
	

			case 6:
							{			
								char cPerformer[240];
					
								cout << "Performer: ";
					
								cin >> ws;
					
								cin.getline (cPerformer, 240);
					
								string sPerformer (cPerformer);
					
								for (list < TSong >::iterator location = SongList.begin ();
											 location != SongList.end (); location++)
							
										if (sPerformer == (*location).GetPerformer ())
												{
				
													(*location).display ();
													break;
		
												}
			
							}
			
			break;
	

			case 7:
							{
								char cGenre[240];
					
								cout << "Genre: ";
					
								cin >> ws;
					
								cin.getline (cGenre, 240);
					
								string sGenre (cGenre);
					

								for (list < TSong >::iterator location = SongList.begin ();
											 location != SongList.end (); location++)
							
										if (sGenre == (*location).GetGenre ())
												{
													(*location).display ();
				
													break;
												}
							}
			
			break;
	

			case 8:
							{
								char cLength[240];
					
								cout << "Length: ";
					
								cin >> ws;
					
								cin.getline (cLength, 240);
					
								string sLength (cLength);
					

								for (list < TSong >::iterator location = SongList.begin ();
											 location != SongList.end (); location++)
							
								if (sLength == (*location).GetLength ())
										{
											(*location).display ();
											break;
		
										}
			
							}
			
			break;
			

						// List songs - We use the iterator to get every song and 
						// display it on the screen     
			case 9:
							for (list < TSong >::iterator location = SongList.begin ();
							 location != SongList.end (); location++)
									
									cout << (*location) << endl;
			
			break;
	
			}
						
			cout << endl << "Press Enter to continue" << endl;
						
			cin.get ();
				
		}
		

		// Before we quit the program we open the song's file and append the list to it. 
		outfile.open (filename.c_str ());
		
		outfile << SongList;
		
		outfile.close ();

}
