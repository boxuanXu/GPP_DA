/*
 * $Id$
 */
#ifndef XG_MATH_VECTOR_H
#  define XG_MATH_VECTOR_H

#include <cmath>
#include <vector>
#include <numeric> 
#include <iterator>
#include <cassert>
#include <boost/random.hpp>
#include "xg_debug.h"
using namespace std;

template<typename T>
    size_t whichmin(const vector<T>& a){
        size_t ans = 0;
        for(size_t i = 1; i < a.size(); ++i)
            if(a[i] < a[ans]) ans = i;
        return ans;
    }

template<typename T>
    size_t whichmax(const vector<T>& a){
        size_t ans = 0;
        for(size_t i = 1; i < a.size(); ++i)
            if(a[i] > a[ans]) ans = i;
        return ans;
    }

template<typename T>
    T max(const vector<T>& a){
        return *max_element(a.begin(), a.end());
    }
template<typename T>
    T min(const vector<T>& a){
        return *min_element(a.begin(), a.end());
    }

template<typename T>
    T sum(const vector<T>& a){
        return accumulate(a.begin(), a.end(), T(0));
    }

template<typename T>
    T mean(const vector<T>& a){
        return accumulate(a.begin(), a.end(), T(0)) / a.size();
    }

template<typename T>
    T norm2(const vector<T>& a){
        return sum(a*a);
    }

template<typename T>
    vector<T> diff(const vector<T>& a){
        vector<T> ans(a.size() - 1);
        for(size_t t = 1; t < a.size(); ++t)
            ans[t - 1] = a[t] - a[t - 1];
        return ans;
    }

template<typename T>
    vector<T> abs(const vector<T>& a){
        vector<T> ans(a.size());
        transform(a.begin(), a.end(), ans.begin(), (T(*)(T))abs);
        return ans;
    }

template<typename T>
    vector<T> cos(const vector<T>& a){
        vector<T> ans(a.size());
        transform(a.begin(), a.end(), ans.begin(), (T(*)(T))cos);
        return ans;
    }

template<typename T>
    vector<T> sin(const vector<T>& a){
        vector<T> ans(a.size());
        transform(a.begin(), a.end(), ans.begin(),  (T(*)(T))sin);
        return ans;
    }


template<typename T>
    vector<T> sqrt(vector<T> a){
        vector<T> ans(a.size());
        transform(a.begin(), a.end(), ans.begin(), (T(*)(T))sqrt);
        return ans;
    }

template<typename T1, typename T2>
    vector<T1> operator+(const T2& a, const vector<T1>& b){
        vector<T1> ans(b.size());
#if __cplusplus >= 201103L
        transform(b.begin(), b.end(), ans.begin(), [a](T1 x){return x + a;});
#else
        for(size_t i = 0; i < b.size(); ++i){
            ans[i] = a + b[i];
        }
#endif
        return ans;
    }

template<typename T1, typename T2>
    vector<T1> operator-(const T2& a, const vector<T1>& b){
        vector<T1> ans(b.size());
#if __cplusplus >= 201103L
        transform(b.begin(), b.end(), ans.begin(), [a](T1 x){return a - x;});
#else
        for(size_t i = 0; i < b.size(); ++i){
            ans[i] = a - b[i];
        }
#endif
        return ans;
    }

template<typename T1, typename T2>
    vector<T1> operator*(const T2& a, const vector<T1>& b){
        vector<T1> ans(b.size());
#if __cplusplus >= 201103L
        transform(b.begin(), b.end(), ans.begin(), [a](T1 x){return x * a;});
#else
        for(size_t i = 0; i < b.size(); ++i){
            ans[i] = a * b[i];
        }
#endif
        return ans;
    }

template<typename T1, typename T2>
    vector<T1> operator/(const T2& a, const vector<T1>& b){
        vector<T1> ans(b.size());
#if __cplusplus >= 201103L
        transform(b.begin(), b.end(), ans.begin(), [a](T1 x){return a / x;});
#else
        for(size_t i = 0; i < b.size(); ++i){
            ans[i] = a / b[i];
        }
#endif
        return ans;
    }

template<typename T1, typename T2>
    vector<T1> operator+(const vector<T1>& a, const T2& b){
        vector<T1> ans(a.size());
#if __cplusplus >= 201103L
        transform(a.begin(), a.end(), ans.begin(), [b](T1 x){return x + b;});
#else
        for(size_t i = 0; i < a.size(); ++i){
            ans[i] = a[i] + b;
        }
#endif
        return ans;
    }

template<typename T1, typename T2>
    vector<T1> operator-(const vector<T1>& a, const T2& b){
        vector<T1> ans(a.size());
#if __cplusplus >= 201103L
        transform(a.begin(), a.end(), ans.begin(), [b](T1 x){return x - b;});
#else
        for(size_t i = 0; i < a.size(); ++i){
            ans[i] = a[i] - b;
        }
#endif
        return ans;
    }

template<typename T1, typename T2>
    vector<T1> operator*(const vector<T1>& a, const T2& b){
        vector<T1> ans(a.size());
#if __cplusplus >= 201103L
        transform(a.begin(), a.end(), ans.begin(), [b](T1 x){return x * b;});
#else
        for(size_t i = 0; i < a.size(); ++i){
            ans[i] = a[i] * b;
        }
#endif
        return ans;
    }

template<typename T1, typename T2>
    vector<T1> operator/(const vector<T1>& a, const T2& b){
        vector<T1> ans(a.size());
#if __cplusplus >= 201103L
        transform(a.begin(), a.end(), ans.begin(), [b](T1 x){return x / b;});
#else
        for(size_t i = 0; i < a.size(); ++i){
            ans[i] = a[i] / b;
        }
#endif
        return ans;
    }

template<typename T1, typename T2>
    vector<T1> operator>(const vector<T1>& a, const T2& b){
        vector<T1> ans(a.size());
#if __cplusplus >= 201103L
        transform(a.begin(), a.end(), ans.begin(), [b](T1 x){return x > b;});
#else
        for(size_t i = 0; i < a.size(); ++i){
            ans[i] = a[i] > b;
        }
#endif
        return ans;
    }

template<typename T1, typename T2>
    vector<T1> operator+(const vector<T1>& a, const vector<T2>& b){
        assert(a.size() == b.size());
        vector<T1> ans(a.size());
#if __cplusplus >= 201103L
        transform(a.begin(), a.end(), b.begin(), ans.begin(), [](T1 x, T2 y){return x + y;});
#else
        for(size_t i = 0; i < a.size(); ++i){
            ans[i] = a[i] + b[i];
        }
#endif
        return ans;
    }
    
template<typename T1, typename T2>
    vector<T1> operator-(const vector<T1>& a, const vector<T2>& b){
        assert(a.size() == b.size());
        vector<T1> ans(a.size());
#if __cplusplus >= 201103L
        transform(a.begin(), a.end(), b.begin(), ans.begin(), [](T1 x, T2 y){return x - y;});
#else
        for(size_t i = 0; i < b.size(); ++i){
            ans[i] = a[i] - b[i];
        }
#endif
        return ans;
    }

template<typename T1, typename T2>
    vector<T1> operator*(const vector<T1>& a, const vector<T2>& b){
        assert(a.size() == b.size());
        vector<T1> ans(a.size());
#if __cplusplus >= 201103L
        transform(a.begin(), a.end(), b.begin(), ans.begin(), [](T1 x, T2 y){return x * y;});
#else
        for(size_t i = 0; i < b.size(); ++i){
            ans[i] = a[i] * b[i];
        }
#endif
        return ans;
    }

template<typename T1, typename T2>
    vector<T1> operator/(const vector<T1>& a, const vector<T2>& b){
        assert(a.size() == b.size());
        vector<T1> ans(a.size());
#if __cplusplus >= 201103L
        transform(a.begin(), a.end(), b.begin(), ans.begin(), [](T1 x, T2 y){return x / y;});
#else
        for(size_t i = 0; i < b.size(); ++i){
            ans[i] = a[i] / b[i];
        }
#endif
        return ans;
    }

template<typename T>
    ostream& operator<<(ostream& o, const vector<T>& v){
        o<<"vector("<<v.size()<<")";
        copy (v.begin(), v.end(), ostream_iterator<T> (o<<"[", ","));
        return o<<"]";
    }


template<typename T>
    vector<T> sub(const vector<T> & a, size_t from , size_t to){
        return vector<T>(a.begin() + from, a.begin() + to);
    }

template<typename T>
    vector<T> subright(const vector<T> & a, size_t from){
        return vector<T>(a.begin() + from, a.end());
    }

template<typename T>
    vector<T>& push_back(vector<T> & a, const vector<T> & b){
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
template<typename T1, typename T2>
    bool cmp_1st(const pair<T1, T2>& a, const pair<T1, T2>& b){
        return a.first < b.first;
    }
/*    vector<double> vector_randn(const int k){
	if ( k <= 0)
	    exit 0;
	static int rand_t = 0;
	srand(time(NULL) + rand_t);
	if(++rand_t > 10000)
	 rand_t=0;
	
	vector<double> data(k);
	generate(data.begin(),data.end(),rand);
	for(size_t i = 0; i < k; i++)
	{
		printf("%d\t",data[i] % 0.1);
	}
	return data;
    }
*/

	/*vector<double> vector_randn( int M, double E, double V)
	{
		vector<double> rand_vector;
		for(size_t i=0;i<M;++i)
		{
			static double V1,V2,S;
			static int phase = 0;
			double X;
			if(phase ==0 ){
				do{
					double U1=(double)rand() / RAND_MAX;
					double U2=(double)rand() / RAND_MAX;
					V1=2 * U1-1;
					V2=2 * U2-1;
					S=V1 * V1 + V2 * V2;
			
				}while(S >= 1|| S==0);
				X=V1 *sqrt(-2 * log(S)/S);
			}else
				X=V2 *sqrt(-2 * log(S)/S);
			phase = 1- phase;
			rand_vector.push_back(X * V + E);
		}
		return rand_vector;
	}*/

double AverageRandom(double min, double max)
{
         int nbRand = rand() % 10001;
         return (min + nbRand*(max - min) / 10000);
}

double Normal(double x, double miu, double sigma)
{
         return 1.0 / sqrt(2 * 3.1415926*sigma) * exp(-1 * (x - miu)*(x - miu) / (2 * sigma*sigma));
}

double NormalRandom(double miu, double sigma, double min, double max)
{
         double x;
         double dScope;
         double y;
         do
         {
             x = AverageRandom(min, max);
             y = Normal(x, miu, sigma);
             dScope = AverageRandom(0, Normal(miu, miu, sigma));
         } while (dScope > y);
         return x;
}

typedef boost::normal_distribution<> NormalDis;
boost::mt19937 rng(time(0));
typedef boost::variate_generator<boost::mt19937&, boost::normal_distribution<double> > GenType;

void vector_randn_boost(vector<double>& rand,int M,double E,double V,double min,double max)
{
	NormalDis dis(E,V);
	GenType gen(rng,dis);
	vector<double> rand_re(M,0);
	while(M>0)
	{
		
		double temp = gen();
		//if(min <= temp && temp <= max)
		if((temp <= max) || ( min <= temp))
		{
			rand_re[M-1] = temp;
			--M;
		}
	}
	rand = rand_re;
	vector<double>().swap(rand_re);
	
}

vector<double> vector_randn(int M,double E,double V,double min,double max)
{
	vector<double> rand_re(M,0);
	srand((unsigned)(time(NULL)));
	
	for (int i = 0; i < M; i++)
        {
             double temp = NormalRandom(E, V, min, max);
             
             rand_re[i]=Normal(temp, E, V);
	}
	return rand_re;
}

double vector_randn(double E,double V,double min,double max)
{
	double rand_re;
	//srand((unsigned)(time(NULL)));
             double temp = NormalRandom(E, V, min, max);
             
             rand_re=Normal(temp, E, V);
	return rand_re;
}


template<typename T>
    vector<double> get_rank(const vector<T> & a){
        vector< pair<T, int> > tmp;
        vector<double> r(a.size());
        for(size_t i = 0; i < a.size(); ++i){
            tmp.push_back(pair<T,int>(a[i], i));
        }
        sort(tmp.begin(), tmp.end(), cmp_1st<T, int>);
        size_t tied = 0;
        for(size_t i = 0; i < tmp.size(); ++i){
            r[tmp[i].second] = i + 1;
            if(i > 0 && tmp[i].first != tmp[i - 1].first){
                if(tied != 0){
                    double nv = (i * 2 - tied) / 2.0;
                    for(size_t j = i - tied - 1; j < i; ++j){
                        r[tmp[j].second] = nv;
                    }
                    tied = 0;
                }
            }
            else if(i > 0 && tmp[i].first == tmp[i - 1].first){
                tied += 1;
            }
        }
        if(tied > 0){
            double nv = (tmp.size() * 2 - tied) / 2.0;
            for(size_t j = tmp.size() - 1 - tied; j < tmp.size(); ++j){
                r[tmp[j].second] = nv;
            }
        }
        return r;
    }


#endif /* ifndef XG_MATH_VECTOR_H */

