#pragma once
#import "range.hpp"

namespace itertools{
	
	template<typename T1, typename T2>
	class chain{

	private:
		T1 first;
		T2 second;
		
	public:
		chain<T1,T2>(const T1 iter1, const T2 iter2)
			: first(iter1),
			second(iter2) {}

		class iterator {

			private:
				typename T1::iterator it1Begin;
				typename T1::iterator it1End;
				typename T2::iterator it2Begin;

			public: 
				 iterator(typename T1::iterator iter1Begin, typename T1::iterator iter1End, typename T2::iterator iter2Begin):
					it1Begin(iter1Begin), it1End(iter1End),
					it2Begin(iter2Begin) { }

				auto operator*() const {
					if (it1Begin != it1End)
						return *it1Begin;
					else return *it2Begin;
				}

				iterator& operator++(){
					if(it1Begin != it1End)
						++it1Begin;
					else
						++it2Begin;
					return *this;	
				}

				const iterator operator++(int){
					iterator tmpIt(*this);
					operator++();
					return tmpIt;
				}

				bool operator==(const iterator& other) const {
					if(it1Begin == other.it1Begin) 
						if(it2Begin == other.it2Begin)
							return true;
					return false;
				}

				bool operator!=(const iterator& other) const {
					if(*this==other)
						return false;
					return true;
				}

		};
		
		typename chain<T1,T2>::iterator begin() {
			return chain<T1,T2>::iterator(first.begin(), first.end(), second.begin());
		}
			
		typename chain<T1,T2>::iterator end() {
			return chain<T1,T2>::iterator(first.end(), first.end(), second.end());
		}

	};

}