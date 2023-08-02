#include <stdio.h>
#include <stdlib.h>

struct coordinates
{
    
    int x ;
    int y ;
    int z ;
    
    void (*setX)( struct coordinates * this, int x ) ;
    void (*setY)( struct coordinates * this, int y ) ;
    void (*setZ)( struct coordinates * this, int z ) ;
    
} ;

typedef struct coordinates coordinate ;

void setX( coordinate * this, int a ) 
{
    this -> x = a ;
}

void setY( coordinate * this, int b ) 
{
    this -> y = b ;
}

void setZ( coordinate * this, int c ) 
{
    this -> z = c ;
}

coordinate rectangle ;

int main() 
{
    
    // Assigning function addresses to struct members //
    rectangle.setX = setX ; 
    rectangle.setY = setY ;
    rectangle.setZ = setZ ;
    
    rectangle.x = 1 ;
    rectangle.y = 2 ;
    rectangle.z = 3 ;
    
    printf( "\nX axis before using methods = %d", rectangle.x ) ;
    printf( "\nY axis before using methods = %d", rectangle.y ) ;
    printf( "\nZ axis before using methods = %d", rectangle.z ) ;
    
    rectangle.setX( &rectangle, 10 ) ;
    rectangle.setY( &rectangle, 20 ) ;
    rectangle.setZ( &rectangle, 30 ) ;
    
    printf( "\n/************************************/" ) ;
    
    printf( "\nX axis after using methods = %d", rectangle.x ) ;
    printf( "\nY axis after using methods = %d", rectangle.y ) ;
    printf( "\nZ axis after using methods = %d", rectangle.z ) ;
    
    return 0;

}






