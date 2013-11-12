/* 
 *	Song Manager: Songs.h
 *	Author: Manuel Rojas
 *
 */

#ifndef Songs_H
#define Songs_H

#include <iostream>
#include <string>
using namespace std;

class TSong 
		{
			private:
			string Title;
			string Composer;
			string Performer;
			string Date;
			string Length;
			string Genre;

			public: 
			TSong(){};
			~TSong(){};

			void SetTitle(string pTitle);
			void SetComposer (string pComposer);
			void SetPerformer(string pPerformer);
			void SetDate(string pDate);
			void SetLength(string pLength);
			void SetGenre(string pGenre);

			string GetTitle();
			string GetComposer();
			string GetPerformer();
			string GetDate();
			string GetLength();
			string GetGenre();

			void display();
			void input();

			friend istream& operator >>(istream &is, TSong &pSong);
			friend ostream& operator <<(ostream &os, TSong &pSong);
		};

istream& operator >>(istream &is, TSong &pSong);
ostream& operator <<(ostream &os, TSong &pSong);

#endif
