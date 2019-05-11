#pragma once
namespace itertools
{

	template<typename T> class range 
	{
		private:
			T first;
			T last;
	
		public:
			range<T>(const T start, const T end) : first(start) , last(end) {}
			
			range<T> (const range& otherOne) : first(otherOne.first), last(otherOne.last) {}
				
				class iterator {
					private:
						T iteration;
						
					public:
						iterator(T member): iteration(member){}
						
						T operator*() const {
							return iteration;
						}
						
						T* operator->() const {
							return &iteration;
						}
						
						iterator& operator++() {
							++iteration;
							return *this;
						}
						
						const iterator operator++(int) {
							iterator tmpIt(*this);
							operator++();
							return tmpIt;
						}

						bool operator==(const iterator& otherIt) const {
							if(iteration == otherIt.iteration)
								return true;
							return false;
							}

						bool operator!=(const iterator& otherIt) const {
							if(iteration != otherIt.iteration)
								return true;
							return false;
							}

				};
		iterator begin() {
			return range<T>::iterator(first);
		}
			
		iterator end() {
			return range<T>::iterator(last);
		}
	};

}