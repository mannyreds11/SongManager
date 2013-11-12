/* 
 *	Song Manager: Songs.cpp
 *	Author: Manuel Rojas
 *
 */

#include "Songs.h"
#include "SongsContainer.h"


// Subroutine will display the components of a song as listed

void TSong::display()
		{
			cout	<< endl << "Title: " << Title << endl
		      	<<"Composer: " << Composer << endl
		 				<<"Performer: " << Performer << endl
		 				<<"Date: " << Date << endl
		 				<<"Genre: " << Genre << endl
		 				<<"Length: " << Length << endl << endl;
		}

// Subroutine will use a character array to store all components of a song
	 
void TSong::input()
		{
			const int bufSize = 256;
			char buffer[bufSize];

			cout << endl << "Input Song Info" << endl
						       << "Title: ";
			cin >> ws;
			cin.getline(buffer, bufSize);
			Title = buffer;

			cout << "Composer: ";
			cin.getline(buffer, bufSize);
			Composer = buffer;

			cout << "Performer: ";
			cin.getline(buffer, bufSize);
			Performer = buffer;

			cout << "Date: ";
			cin.getline(buffer, bufSize);
			Date = buffer;

			cout << "Genre: ";
			cin.getline(buffer, bufSize);
			Genre = buffer;

			cout << "Length: ";
			cin.getline(buffer, bufSize);
			Length = buffer;
		}

void TSong::SetTitle (string pTitle){ Title = pTitle; }

void TSong::SetComposer (string pComposer){ Composer = pComposer; }

void TSong::SetPerformer (string pPerformer){ Performer = pPerformer; }

void TSong::SetDate (string pDate){ Date = pDate; }

void TSong::SetLength(string pLength){ Length = pLength; }

void TSong::SetGenre (string pGenre){ Genre = pGenre; }

string TSong::GetTitle(){ return Title; }

string TSong::GetComposer(){ return Composer; }

string TSong::GetPerformer(){ return Performer; }

string TSong::GetDate(){ return Date; }

string TSong::GetLength(){ return Length; }

string TSong::GetGenre(){ return Genre; }

istream& operator >>(istream &is, TSong &pSong)
			{
				const int bufSize = 256;
				char buffer[bufSize];

				is.getline(buffer, bufSize, OBJSEP);
				pSong.Title = buffer;

				is.getline(buffer, bufSize, OBJSEP);
				pSong.Composer = buffer;

				is.getline(buffer, bufSize, OBJSEP);
				pSong.Performer = buffer;

				is.getline(buffer, bufSize, OBJSEP);
				pSong.Date = buffer;

				is.getline(buffer, bufSize, OBJSEP);
				pSong.Length = buffer;

				is.getline(buffer, bufSize, OBJSEP);
				pSong.Genre = buffer;


				return is;
			}

ostream& operator <<(ostream &os, TSong &pSong)
			{
				os << pSong.Title 
					 << OBJSEP << pSong.Composer 
					 << OBJSEP << pSong.Performer
					 << OBJSEP << pSong.Date
					 << OBJSEP << pSong.Genre
					 << OBJSEP << pSong.Length << OBJSEP;
					 
				return os;
			}  
