/*
    FDCT3D (Fast 3d Curvelet Transform)
	Written by Lexing Ying

	Updated by: Mafijul Bhuiyan (2014)
				University of Alberta
	   	   	   	Upgraded from FFTW 2.1.5 to FFTW 3.3.3
	   	   	    Solved the memory leaking problem in FFTW 3.3.3
	   	   	    Plugged in with FISTA Algorithm
*/

#ifndef _NUMTNS_HPP_
#define _NUMTNS_HPP_

#include "commoninc.hpp"

template <class F>
class NumTns {
public:
  int _m, _n, _p;
  F* _data;
public:
  NumTns(int m=0, int n=0, int p=0): _m(m), _n(n), _p(p) {
	if(_m>0 && _n>0 && _p>0)
	{
		_data = new F[_m*_n*_p];
		assert( _data!=NULL );
		memset(_data, 0, _m*_n*_p*sizeof(F));
	} else
		_data = NULL;
  }
  NumTns(const NumTns& C): _m(C._m), _n(C._n), _p(C._p) {
	if(_m>0 && _n>0 && _p>0) {		_data = new F[_m*_n*_p]; assert( _data!=NULL );	 memset(_data, 0, _m*_n*_p*sizeof(F));	 } else 		_data = NULL;
	if(_m>0 && _n>0 && _p>0) {		memcpy( _data, C._data, _m*_n*_p*sizeof(F) );	 }
  }
  ~NumTns() {
	if(_m>0 && _n>0 && _p>0) {		delete[] _data; _data = NULL; }
  }
  NumTns& operator=(const NumTns& C) {
	 if(_m>0 && _n>0 && _p>0) {		delete[] _data; _data = NULL; }
	 _m = C._m; _n=C._n; _p=C._p;
	 if(_m>0 && _n>0 && _p>0) {
		 _data = new F[_m*_n*_p];
		 assert( _data!=NULL );
		 memset(_data, 0, _m*_n*_p*sizeof(F));
	 }
	 else
		 _data = NULL;
	 if(_m>0 && _n>0 && _p>0) {
		 memcpy( _data, C._data, _m*_n*_p*sizeof(F) );
	 }
	 return *this;
  }
  void resize(int m, int n, int p) {
	 if(_m!=m || _n!=n || _p!=p) {
		if(_m>0 && _n>0 && _p>0) {		delete[] _data; _data = NULL;		}
		_m = m; _n = n; _p=p;
		if(_m>0 && _n>0 && _p>0) {		_data = new F[_m*_n*_p]; assert( _data!=NULL );		memset(_data, 0, _m*_n*_p*sizeof(F));		} else		  _data = NULL;
	 }
  }
  const F& operator()(int i, int j, int k) const {	 //assert( i>=0 && i<_m && j>=0 && j<_n && k>=0 && k<_p );
	 return _data[i + j*_m + k*_m*_n];
  }
  F& operator()(int i, int j, int k) {	 //assert( i>=0 && i<_m && j>=0 && j<_n && k>=0 && k<_p );
	 return _data[i + j*_m + k*_m*_n];
  }
  int m() const { return _m; }
  int n() const { return _n; }
  int p() const { return _p; }
  F* data() const { return _data; }
};

template <class F> inline void setvalue(NumTns<F>& T, F val)
{
  for(int i=0; i<T.m(); i++)
	 for(int j=0; j<T.n(); j++)
		for(int k=0; k<T.p(); k++)
		  T(i,j,k) = val;
}
template <class F> inline void clear(NumTns<F>& T)
{
  memset(T.data(), 0, T.m()*T.n()*T.p()*sizeof(F));
}

typedef NumTns<int>    IntNumTns;
typedef NumTns<float> DblNumTns;
typedef NumTns<cpx>    CpxNumTns;

//template <class F> inline istream& operator>>(istream& is, NumTns<F>& tns);
inline ostream& operator<<(ostream& os, const CpxNumTns& T)
{  //os<<T.m()<<" "<<T.n()<<" "<<T.p()<<endl;
  for(int k=0; k<T.p(); k++)
	 for(int j=0; j<T.n(); j++)
		for(int i=0; i<T.m(); i++)
		  os<<" "<<real(T(i,j,k))<<" "<<imag(T(i,j,k))<<endl;
  return os;
}

#endif
