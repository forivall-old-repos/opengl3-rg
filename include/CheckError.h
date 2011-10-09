//////////////////////////////////////////////////////////////////////////////
//
//  --- CheckError.h ---
//
//////////////////////////////////////////////////////////////////////////////

#ifndef __CHECKERROR_H__
#define __CHECKERROR_H__

#  include <GL/glew.h>

//----------------------------------------------------------------------------

//static const char*
//ErrorString( GLenum error )
//{
//    const char*  msg;
//    switch( error ) {
//#define errcase( Token )  case Token: msg = #Token; break;
//	errcase( GL_NO_ERROR )
//	errcase( GL_INVALID_VALUE )
//	errcase( GL_INVALID_ENUM )
//	errcase( GL_INVALID_OPERATION )
//	errcase( GL_STACK_OVERFLOW )
//	errcase( GL_STACK_UNDERFLOW )
//	errcase( GL_OUT_OF_MEMORY )
//#undef errcase
//    }
//
//    return msg;
//}

//----------------------------------------------------------------------------

//static void
//_CheckError( const char* file, int line )
//{
//    GLenum  error = glGetError();
//
//    do {
//	fprintf( stderr, "[%s:%d] %s\n", file, line, ErrorString(error) );
//    } while ((error = glGetError()) != GL_NO_ERROR );
//
//}

//----------------------------------------------------------------------------

#define CheckError()  _CheckError( __FILE__, __LINE__ )

//----------------------------------------------------------------------------

#endif // !__CHECKERROR_H__
