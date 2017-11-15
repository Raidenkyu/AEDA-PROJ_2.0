#ifndef EXTRAS_H_
#define EXTRAS_H_
#include <vector>


                      /////                                          /////
                     /////               EXTRAS . H                 /////
                    /////                                          /////

// Class: Time

class Time{
public:
	Time(unsigned int h = 0, unsigned int m = 0, unsigned int s = 0);
	void printTime(std::ostream & os);
	Time operator+(const Time& t);

private:
    unsigned int timeArrange();
	unsigned int hours, minutes, seconds;
};




/**
 * @brief      implementation of a Quick Sort Algorithm
 *
 * @param[in]  arr    The arr
 * @param[in]  left   The left
 * @param[in]  right  The right
 *
 * @tparam     T      elements of the vector arr
 */
template<class T>
void quickSort(std::vector<T> arr, int left, int right) {
      int i = left, j = right;
      T tmp;
      std::string pivot = arr[(left + right) / 2]->getNome();

      /* partition */
      while (i <= j) {
            while (arr[i]->getNome() < pivot)
                  i++;
            while (arr[j]->getNome() > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}


/**
 * @brief      implementation of a Binary Search Algorithm
 *
 * @param[in]  v     the vector
 * @param[in]  x     the element
 *
 * @tparam     T     type of the elements of the vector
 *
 * @return     the index of the element if found, otherwise -1
 */
template <class T,class P>
int BinarySearch(const std::vector<T> &v, P x){
	int left = 0, right = v.size() - 1;
	while (left <= right){
		int middle = (left + right) / 2;
		if (v[middle]->getNome() < x){
			left = middle + 1;
		}else if (x < v[middle]->getNome()){
			right = middle - 1;
		}else{
			return middle; // encontrou
		}
	return -1; // n�o encontrou
	}
}




#endif /* SRC_EXTRAS_H_ */
