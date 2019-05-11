#pragma once
namespace itertools{

	template<typename T1, typename T2> class zip {
		private:
			T1 first;
			T2 second;
	
		public:
			zip<T1,T2>(const T1 t1, const T2 t2) : first(t1) , second(t2) {}
			
				class iterator {

				};
		iterator begin() {
			return NULL;
		}
			
		iterator end() {
			return NULL;
		}
	};
}