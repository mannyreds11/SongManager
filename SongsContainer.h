/* 
 *	Song Manager:SongsContainer.h
 *  Author: Manuel Rojas
 *
 */ 
 
#ifndef SONGSCONTAINER_H
#define SONGSCONTAINER_H

#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <typeinfo>
#include <algorithm>


using namespace std;

// To separate objects on a container and the containers themselves.

#define OBJSEP '`'
#define CONTAINERSEP '~'

#define BUFSIZE 4000      



// Deque                                                                      

template <class oType>
void AddToContainer( deque<oType> & pContainer, oType & pTemp ) {
  pContainer.push_back( pTemp );
}




// List                                                                       

template <class oType>
void AddToContainer( list<oType> & pContainer, oType & pTemp ) {
  pContainer.push_back( pTemp );
}




// Queue

template <class oType>
void AddToContainer( queue<oType> & pContainer, oType & pTemp ) {
  pContainer.push( pTemp );
}



// Set

template <class oType>
void AddToContainer( set<oType> & pContainer, oType & pTemp ) {
  pContainer.insert( pTemp );
}



// Stack

template <class oType>
void AddToContainer( stack<oType> & pContainer, oType & pTemp ) {
  pContainer.push( pTemp );
}

// Vector 

template <class oType>
void AddToContainer( vector<oType> & pContainer, oType & pTemp ) {
  pContainer.push_back( pTemp );
}

// Function: LinearIn                                                         
// Generic function to input sets, lists, deques, queues, stacks, and vectors maps.                      

template <class cType, class oType>
void LinearIn( istream & is, cType & pLinear, oType & pTemp ) 
		{
			char EndOfObject = ' ';
			char EndOfContainer = is.get();
			bool AtEndOfContainer = ( EndOfContainer == CONTAINERSEP );

			if ( !AtEndOfContainer )
				is.putback( EndOfContainer );

			while ( !is.eof() && !AtEndOfContainer ) 
						{
							oType Temp;

							// handle string objects as required
							if ( typeid( Temp ) == typeid( string ) ) 
								{
									char buffer[BUFSIZE];
									void *sptr = &Temp;   // required to avoid compile errors with non-strings
									string stemp;

									is.getline( &buffer[0], BUFSIZE - 1, OBJSEP );
									stemp = buffer;
									*(string*)sptr = stemp;
									AtEndOfContainer = ( CONTAINERSEP == (EndOfObject = is.get()) );
								}
							// handle non-string objects 
							else
								is >> Temp >> EndOfObject;

							AddToContainer(pLinear, Temp);
	
							// Remove extra object separators and container terminator
							while ( !is.eof() && (EndOfObject == OBJSEP) ) 
										{
											EndOfObject = is.get();
											AtEndOfContainer = ( CONTAINERSEP == EndOfObject );
										}

							if ( !AtEndOfContainer && !is.eof() )
								is.putback( EndOfObject );
					}  
		}



// Function: LinearOut                                                        
// Generic function to output sets, lists, deques, and vectors maps.  
                     
template <class cType, class iType>
void LinearOut( ostream &os, cType & pContainer, iType & pIterator ) 
		{
  		while ( pIterator != pContainer.end() ) 
    	os << *(pIterator++) << OBJSEP;
  		os << CONTAINERSEP;
		}


// istream operators >> for each type of container.  These are in alphabetical order.                                                    

// >> Deque                                                                   

template <class GType>
istream &operator >> ( istream &is, deque<GType> &pContainer ) 
			{
  			GType Temp;
  			LinearIn( is, pContainer, Temp );
	
  			return is;
			}

// >> List                                                                    

template <class GType>
istream &operator >> ( istream &is, list<GType> &pContainer ) 
			{
  			GType Temp;
				LinearIn( is, pContainer, Temp );

  			return is;
			}

// >> Map                                                                     

template <class kType, class vType>
istream &operator >> ( istream &is, map<kType, vType> &pContainer ) 
			{
				char EndOfObject = ' ';
				char EndOfContainer = is.get();
				bool AtEndOfContainer = ( EndOfContainer == CONTAINERSEP );

				if ( !AtEndOfContainer )
					is.putback( EndOfContainer );

				while ( !is.eof() && !AtEndOfContainer ) 
							{
								// Get the index
									kType kTemp;

								// Handle string object as required 
								if ( typeid( kTemp ) == typeid( string ) ) 
									{
										char buffer[BUFSIZE];
										void *sptr = &kTemp;
										string stemp;

										is.getline( &buffer[0], BUFSIZE - 1, OBJSEP );
										stemp = buffer;
										*(string*)sptr = stemp;
									}
								// Get non-string object
								else
									is >> kTemp >> EndOfObject;

								// Get the value
									vType vTemp;

								// Handle string object as required 
								if ( typeid( vTemp ) == typeid( string ) ) 
									{
										char buffer[BUFSIZE];
										void *sptr = &vTemp;
										string stemp;

										is.getline( &buffer[0], BUFSIZE - 1, OBJSEP );
										stemp = buffer;
										*(string*)sptr = stemp;
										AtEndOfContainer = ( CONTAINERSEP == (EndOfObject = is.get()) );
									}

								// Get the non-string object
								else
										is >> vTemp >> EndOfObject;

								// Add to map
								pContainer.insert( pair<kType, vType>( kTemp, vTemp ) );


								// Remove any extra separators including end of container
								while ( !is.eof() && (EndOfObject == OBJSEP) ) 
											{
												EndOfObject = is.get();
												AtEndOfContainer = ( CONTAINERSEP == EndOfObject );
											}

								if ( !AtEndOfContainer && !is.eof() )
									is.putback( EndOfObject );
				}  

				return is;
}

// >> Queue                                                                   

template <class GType>
istream &operator >> ( istream &is, queue<GType> &pContainer ) 
			{
		  	GType Temp;

  			LinearIn( is, pContainer, Temp );

  			return is;
			}

// >> Set                                                                     

template <class GType>
istream &operator >> ( istream &is, set<GType> &pContainer ) 
			{
				GType Temp;

				LinearIn( is, pContainer, Temp );

				return is;
			}

// >> Stack                                                                   

template <class GType>
istream &operator >> ( istream &is, stack<GType> &pContainer ) 
			{
				GType Temp;

				LinearIn( is, pContainer, Temp );

				return is;
			}

// >> Vector                                                                  

template <class GType>
istream &operator >> ( istream &is, vector<GType> &pContainer ) 
			{
				GType Temp;

				LinearIn( is, pContainer, Temp );

				return is;
			}


// ostream operators << for each type of container.                           
 
// << Deque                                                                   

template <class GType>
ostream &operator << ( ostream &os, deque<GType> &pContainer ) 
			{
				typename deque<GType>::iterator start; // 2.0
	
				start = pContainer.begin(); // 2.0
				LinearOut( os, pContainer, start );  // 2.0

				return os;
			}

// << List                                                                    

template <class GType>
ostream &operator << ( ostream &os, list<GType> &pContainer ) {
  typename list<GType>::iterator start; 
	
  start = pContainer.begin(); 
  LinearOut( os, pContainer, start ); 
  
  return os;
}

// << Map  Special case since two items need to be output.                    

template <class kType, class vType>
ostream &operator << ( ostream &os, map<kType, vType> &pContainer ) 
			{
				typename map<kType, vType>::iterator iter; 

				for (  iter = pContainer.begin(); iter != pContainer.end(); iter++) 
					{
						os << iter->first << OBJSEP;
						os << iter->second << OBJSEP;
					}

				os << CONTAINERSEP;

				return os;
			}

// << Queue   Special case because of destructive read.                       

template <class GType>
ostream &operator << ( ostream &os, queue<GType> &pContainer ) 
			{
				queue<GType> qIn(pContainer);

				while ( !qIn.empty() ) 
							{
								os << qIn.front() << OBJSEP;
								qIn.pop();
							}

				os << CONTAINERSEP;

				return os;
			}

// << Set                                                                     

template <class GType>
ostream &operator << ( ostream &os, set<GType> &pContainer ) 
			{
				typename set<GType>::iterator start;	
	
				start = pContainer.begin();	
				LinearOut( os, pContainer, start );  

				return os;
			}

// << Stack - Special case because of destructive read and preservation of order.                                                         

template <class GType>
ostream &operator << ( ostream &os, stack<GType> &pContainer ) 
			{
				stack<GType> sIn(pContainer), sOut;

				while ( !sIn.empty() ) 
						{
							sOut.push( sIn.top() );
							sIn.pop();
						}

				
				while ( !sOut.empty() ) 
							{
								os << sOut.top() << OBJSEP;
								sOut.pop();
							}

				os << CONTAINERSEP;

				return os;
			}

// << Vector                                                                  

template <class GType>
ostream &operator << ( ostream &os, vector<GType> &pContainer ) {
  typename vector<GType>::iterator start;	
	
  start = pContainer.begin();	
  LinearOut( os, pContainer,  start );

  return os;
}



#endif
