//
//
////////////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif


#ifndef _LpEuclid_H_
#define _LpEuclid_H_


#include <math.h>


#ifndef TRUE
#define TRUE	1
#endif

#ifndef FALSE
#define FALSE	0
#endif

#define LCX_PI		3.1415926535897932384626433832795f
#define LCXToRadian( degree ) ((degree) * (LCX_PI / 180.0f))
#define LCXToDegree( radian ) ((radian) * (180.0f / LCX_PI))


typedef int						INT;
typedef int						BOOL;
typedef float					FLOAT;
typedef unsigned long			DWORD;


struct LCXVECTOR2
{
	union {	struct { FLOAT x; FLOAT y; };	FLOAT m[2];	};

	LCXVECTOR2();
	LCXVECTOR2(const FLOAT* v);
	LCXVECTOR2(const LCXVECTOR2& v);
	LCXVECTOR2(const LCXVECTOR2* v);
	LCXVECTOR2(FLOAT X, FLOAT Y);

	operator FLOAT*();
	operator const FLOAT*() const;

	FLOAT& operator[](int n);

	// assignment operators
	LCXVECTOR2& operator +=(const LCXVECTOR2& v);
	LCXVECTOR2& operator -=(const LCXVECTOR2& v);
	LCXVECTOR2& operator *=(FLOAT v);
	LCXVECTOR2& operator /=(FLOAT v);

	// unary operators
	LCXVECTOR2 operator +() const;
	LCXVECTOR2 operator -() const;

	// binary operators
	LCXVECTOR2 operator +(const LCXVECTOR2& v) const;
	LCXVECTOR2 operator -(const LCXVECTOR2& v) const;
	LCXVECTOR2 operator *(FLOAT v) const;
	LCXVECTOR2 operator /(FLOAT v) const;

	friend LCXVECTOR2 operator *(FLOAT f, const LCXVECTOR2& v);
	friend LCXVECTOR2 operator /(FLOAT f, const LCXVECTOR2& v);

	BOOL operator ==(const LCXVECTOR2& v) const;
	BOOL operator !=(const LCXVECTOR2& v) const;

	FLOAT operator *(const LCXVECTOR2& v);										// Dot Product
	friend FLOAT operator *(const LCXVECTOR2& v1, const LCXVECTOR2& v2);

	FLOAT operator ^(const LCXVECTOR2& v);										// Cross Product(Z-Value)
	friend FLOAT operator ^(const LCXVECTOR2& v1, const LCXVECTOR2& v2);

	LCXVECTOR2 operator *(const FLOAT* v);										// Transform: vector * Matrix
	friend LCXVECTOR2 operator *(const FLOAT* v1, const LCXVECTOR2& v2);			// Transform: Matrix * vector;

	FLOAT		Length();														// Length
	FLOAT		LengthSq();														// Length Square
	LCXVECTOR2	Normalize();
	LCXVECTOR2	Normalize(const LCXVECTOR2* v);
};


struct LCXVECTOR3
{
	union {	struct { FLOAT x; FLOAT y; FLOAT z; };	FLOAT m[3];	};

	LCXVECTOR3();
	LCXVECTOR3(const FLOAT* v);
	LCXVECTOR3(const LCXVECTOR3& v);
	LCXVECTOR3(const LCXVECTOR3* v);
	LCXVECTOR3(FLOAT X, FLOAT Y, FLOAT Z);

	operator FLOAT*();
	operator const FLOAT*() const;

	FLOAT& operator[](int n);

	// assignment operators
	LCXVECTOR3& operator +=(const LCXVECTOR3& v);
	LCXVECTOR3& operator -=(const LCXVECTOR3& v);
	LCXVECTOR3& operator *=(FLOAT v);
	LCXVECTOR3& operator /=(FLOAT v);

	// unary operators
	LCXVECTOR3 operator +() const;
	LCXVECTOR3 operator -() const;

	// binary operators
	LCXVECTOR3 operator +(const LCXVECTOR3& v) const;
	LCXVECTOR3 operator -(const LCXVECTOR3& v) const;
	LCXVECTOR3 operator *(FLOAT v) const;
	LCXVECTOR3 operator /(FLOAT v) const;

	friend LCXVECTOR3 operator *(FLOAT f, const LCXVECTOR3& v);
	friend LCXVECTOR3 operator /(FLOAT f, const LCXVECTOR3& v);

	BOOL operator ==(const LCXVECTOR3& v) const;
	BOOL operator !=(const LCXVECTOR3& v) const;

	FLOAT operator *(const LCXVECTOR3& v);										// Dot Product
	friend FLOAT operator *(const LCXVECTOR3& v1, const LCXVECTOR3& v2);

	LCXVECTOR3 operator ^(const LCXVECTOR3& v);									// Cross Product
	friend LCXVECTOR3 operator ^(const LCXVECTOR3& v1, const LCXVECTOR3& v2);

	LCXVECTOR3 operator *(const FLOAT* v);										// Transform: vector * Matrix
	friend LCXVECTOR3 operator *(const FLOAT* v1, const LCXVECTOR3& v2);		// Transform: Matrix * vector;

	FLOAT		Length();														// Length
	FLOAT		LengthSq();														// Length Square
	LCXVECTOR3	Normalize();
	LCXVECTOR3	Normalize(const LCXVECTOR3* v);

	LCXVECTOR3	Cross(const LCXVECTOR3* v1, const LCXVECTOR3* v2);
};



struct LCXVECTOR4
{
	union {	struct { FLOAT x; FLOAT y; FLOAT z; FLOAT w; };	FLOAT m[4];	};

	LCXVECTOR4();
	LCXVECTOR4(const FLOAT* v);
	LCXVECTOR4(const LCXVECTOR4& v);
	LCXVECTOR4(const LCXVECTOR4* v);
	LCXVECTOR4(FLOAT X, FLOAT Y, FLOAT Z, FLOAT W);

	operator FLOAT*();
	operator const FLOAT*() const;

	FLOAT& operator[](int n);

	// assignment operators
	LCXVECTOR4& operator +=(const LCXVECTOR4& v);
	LCXVECTOR4& operator -=(const LCXVECTOR4& v);
	LCXVECTOR4& operator *=(FLOAT v);
	LCXVECTOR4& operator /=(FLOAT v);

	// unary operators
	LCXVECTOR4 operator +() const;
	LCXVECTOR4 operator -() const;

	// binary operators
	LCXVECTOR4 operator +(const LCXVECTOR4& v) const;
	LCXVECTOR4 operator -(const LCXVECTOR4& v) const;
	LCXVECTOR4 operator *(FLOAT v) const;
	LCXVECTOR4 operator /(FLOAT v) const;

	friend LCXVECTOR4 operator *(FLOAT f, const LCXVECTOR4& v);
	friend LCXVECTOR4 operator /(FLOAT f, const LCXVECTOR4& v);

	BOOL operator ==(const LCXVECTOR4& v) const;
	BOOL operator !=(const LCXVECTOR4& v) const;

	FLOAT operator *(const LCXVECTOR4& v);										// Dot Product
	friend FLOAT operator *(const LCXVECTOR4& v1, const LCXVECTOR4& v2);

	LCXVECTOR4 operator *(const FLOAT* v);										// Transform: vector * Matrix
	friend LCXVECTOR4 operator *(const FLOAT* v1, const LCXVECTOR4& v2);		// Transform: Matrix * vector;

	FLOAT		Length();														// Length
	FLOAT		LengthSq();														// Length Square
	LCXVECTOR4	Normalize();
	LCXVECTOR4	Normalize(const LCXVECTOR4* v);
};



struct LCXMATRIX
{
	union
	{
		struct
		{
			FLOAT _11, _12, _13, _14;
			FLOAT _21, _22, _23, _24;
			FLOAT _31, _32, _33, _34;
			FLOAT _41, _42, _43, _44;

		};
		FLOAT m[4][4];
	};

	LCXMATRIX();
	LCXMATRIX(const FLOAT* v);
	LCXMATRIX(const LCXMATRIX& v);
	LCXMATRIX(	FLOAT v11, FLOAT v12, FLOAT v13, FLOAT v14,
		FLOAT v21, FLOAT v22, FLOAT v23, FLOAT v24,
		FLOAT v31, FLOAT v32, FLOAT v33, FLOAT v34,
		FLOAT v41, FLOAT v42, FLOAT v43, FLOAT v44 );


	// access grants
	FLOAT& operator () ( int iRow, int iCol );
	FLOAT  operator () ( int iRow, int iCol ) const;

	// casting operators
	operator FLOAT* ();
	operator const FLOAT* () const;

	// assignment operators
	LCXMATRIX& operator *= (const LCXMATRIX& v);
	LCXMATRIX& operator += (const LCXMATRIX& v);
	LCXMATRIX& operator -= (const LCXMATRIX& v);
	LCXMATRIX& operator *= ( FLOAT v);
	LCXMATRIX& operator /= ( FLOAT v);

	LCXMATRIX operator +() const;												// unary operators
	LCXMATRIX operator -() const;

	LCXMATRIX operator * (const LCXMATRIX& v) const;
	LCXMATRIX operator + (const LCXMATRIX& v) const;
	LCXMATRIX operator - (const LCXMATRIX& v) const;
	LCXMATRIX operator * ( FLOAT v) const;
	LCXMATRIX operator / ( FLOAT v) const;


	friend LCXMATRIX operator * (FLOAT f, const LCXMATRIX& v);
	friend LCXMATRIX operator * (const LCXMATRIX& v, FLOAT f);

	BOOL operator == (const LCXMATRIX& v) const;
	BOOL operator != (const LCXMATRIX& v) const;

	LCXMATRIX&	Identity();
	LCXMATRIX&	Transpose();
	LCXMATRIX&	Transpose(const LCXMATRIX* v);
	LCXMATRIX&	Inverse(INT nQuick=TRUE);
	LCXMATRIX&	Inverse(const LCXMATRIX* v, INT nQuick=TRUE);					// nQuick=TRUE is _14 or _24 or _34 is not zero
	FLOAT		Determinant();

	LCXMATRIX&	SetupScaling(FLOAT X, FLOAT Y, FLOAT Z);
	LCXMATRIX&	SetupViewLH(const LCXVECTOR3* vEye, const LCXVECTOR3* vLook, const LCXVECTOR3* vUp );
	LCXMATRIX&	SetupPerspectiveLH(FLOAT fFOV, FLOAT fAspect, FLOAT fNear, FLOAT fFar);
	LCXMATRIX&	SetupRotationX(FLOAT fRad);
	LCXMATRIX&	SetupRotationY(FLOAT fRad);
	LCXMATRIX&	SetupRotationZ(FLOAT fRad);
	LCXMATRIX&	SetupRotationAxis(const LCXVECTOR3* vAxis, FLOAT fRad);
	LCXMATRIX&	SetupTranslation(const LCXVECTOR3* vTrs, BOOL bInit=TRUE);

	void		TransformCoord(LCXVECTOR3* pOut, const LCXVECTOR3* pIn);
};






struct LCXQUATERNION
{
	union {	struct { FLOAT x; FLOAT y; FLOAT z;	 FLOAT w; }; FLOAT m[4]; };

	LCXQUATERNION();
	LCXQUATERNION( const FLOAT * );
	LCXQUATERNION( const LCXQUATERNION& );
	LCXQUATERNION( FLOAT x, FLOAT y, FLOAT z, FLOAT w );

	// casting
	operator FLOAT* ();
	operator const FLOAT* () const;

	// assignment operators
	LCXQUATERNION& operator += ( const LCXQUATERNION& );
	LCXQUATERNION& operator -= ( const LCXQUATERNION& );
	LCXQUATERNION& operator *= ( const LCXQUATERNION& );
	LCXQUATERNION& operator *= ( FLOAT );
	LCXQUATERNION& operator /= ( FLOAT );

	// unary operators
	LCXQUATERNION  operator + () const;
	LCXQUATERNION  operator - () const;

	// binary operators
	LCXQUATERNION operator + ( const LCXQUATERNION& ) const;
	LCXQUATERNION operator - ( const LCXQUATERNION& ) const;
	LCXQUATERNION operator * ( const LCXQUATERNION& ) const;
	LCXQUATERNION operator * ( FLOAT ) const;
	LCXQUATERNION operator / ( FLOAT ) const;

	friend LCXQUATERNION operator * (FLOAT, const LCXQUATERNION& );

	BOOL operator == ( const LCXQUATERNION& ) const;
	BOOL operator != ( const LCXQUATERNION& ) const;

	void SLerp(const LCXQUATERNION* q1, const LCXQUATERNION* q2, FLOAT t);
	void RotationMatrix(LCXMATRIX* pOut, BOOL bDX=TRUE);
};


// Planes
struct LCXPLANE
{
	union {	struct { FLOAT a; FLOAT b; FLOAT c;	 FLOAT d; }; FLOAT m[4]; };

	LCXPLANE();
	LCXPLANE( const FLOAT* );
	LCXPLANE( const LCXPLANE& );
	LCXPLANE( FLOAT a, FLOAT b, FLOAT c, FLOAT d );

	// casting
	operator FLOAT* ();
	operator const FLOAT* () const;

	// unary operators
	LCXPLANE operator + () const;
	LCXPLANE operator - () const;

	// binary operators
	BOOL operator == ( const LCXPLANE& ) const;
	BOOL operator != ( const LCXPLANE& ) const;

	void SetupFromPointNormal(const LCXVECTOR3* point, const LCXVECTOR3* normal);
	void SetupFromPoints(const LCXVECTOR3* p0, const LCXVECTOR3* p1, const LCXVECTOR3* p2);
};



// Colors
struct LCXCOLOR
{
	union {	struct { FLOAT r; FLOAT g; FLOAT b;	 FLOAT a; }; FLOAT m[4]; };

	LCXCOLOR();
	LCXCOLOR( DWORD argb );
	LCXCOLOR( const FLOAT * );
	LCXCOLOR( const LCXCOLOR& );
	LCXCOLOR( FLOAT r, FLOAT g, FLOAT b, FLOAT a );

	// casting
	operator DWORD () const;

	operator FLOAT* ();
	operator const FLOAT* () const;

	// assignment operators
	LCXCOLOR& operator += ( const LCXCOLOR& );
	LCXCOLOR& operator -= ( const LCXCOLOR& );
	LCXCOLOR& operator *= ( FLOAT );
	LCXCOLOR& operator /= ( FLOAT );

	// unary operators
	LCXCOLOR operator + () const;
	LCXCOLOR operator - () const;

	// binary operators
	LCXCOLOR operator + ( const LCXCOLOR& ) const;
	LCXCOLOR operator - ( const LCXCOLOR& ) const;
	LCXCOLOR operator * ( FLOAT ) const;
	LCXCOLOR operator / ( FLOAT ) const;

	friend LCXCOLOR operator * (FLOAT, const LCXCOLOR& );

	BOOL operator == ( const LCXCOLOR& ) const;
	BOOL operator != ( const LCXCOLOR& ) const;
};



FLOAT LCXVec3Dot(const LCXVECTOR3* p1, const LCXVECTOR3* p2);
FLOAT LCXVec3Length(const LCXVECTOR3* v);
FLOAT LCXPlaneDotCoord(const LCXPLANE *pP, const LCXVECTOR3 *pV);

INT LcMath_BoundingBox(const LCXVECTOR3* v		// Input Vertex Buffer
					   , INT Number				// Vertex Number
					   , INT Stride				// Sizeof Vertex
					   , LCXVECTOR3* pOutMin	// Output Min Value
					   , LCXVECTOR3* pOutMax	// Output Max Value
					   );


INT LcMath_IntersectTri(  const LCXVECTOR3* V0	// 삼각형 꼭지점
						, const LCXVECTOR3* V1	// 삼각형 꼭지점
						, const LCXVECTOR3* V2	// 삼각형 꼭지점
						, const LCXVECTOR3* L0	// 직선의 시작 위치
						, const LCXVECTOR3* L	// 직선의 방향 벡터
						, float* u			// α 출력(선택)
						, float* v			// β 출력(선택)
						);

INT LcMath_LineToTriangle(
						    LCXVECTOR3* pOut			// Pick Position
						  ,	FLOAT* fD					// Distance from vcRayPos to pOut
						  ,	LCXVECTOR3* vcRayPos		// Starting Ray Position
						  ,	LCXVECTOR3* vcRayDir		// Ray Direction(It must be Normalization.)
						  ,	LCXVECTOR3* pTri
						  ,	BOOL bUseCull=TRUE);


INT LcMath_LineToTriangle(
						    LCXVECTOR3* vcPck			// Pick Position
						  ,	FLOAT* D					// Distance from vcRayPos to pOut
						  ,	const LCXVECTOR3* vcRayPos	// Starting Ray Position
						  ,	const LCXVECTOR3* vcRayDir	// Starting Ray Position
						  ,	const LCXVECTOR3* p0		// Triangle 0
						  ,	const LCXVECTOR3* p1		// Triangle 1
						  ,	const LCXVECTOR3* p2		// Triangle 2
						  ,	BOOL bUseCull=TRUE);


#endif



