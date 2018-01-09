#include <iostream>
#include <cstddef>
//using namespace std;

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <class _Tp, class _Distance> struct input_iterator {
		  typedef input_iterator_tag iterator_category;
		    typedef _Tp                value_type;
			  typedef _Distance          difference_type;
			    typedef _Tp*               pointer;
				  typedef _Tp&               reference;
};

struct output_iterator {
		  typedef output_iterator_tag iterator_category;
		    typedef void                value_type;
			  typedef void                difference_type;
			    typedef void                pointer;
				  typedef void                reference;
};

template <class _Tp, class _Distance> struct forward_iterator {
		  typedef forward_iterator_tag iterator_category;
		    typedef _Tp                  value_type;
			  typedef _Distance            difference_type;
			    typedef _Tp*                 pointer;
				  typedef _Tp&                 reference;
};


template <class _Tp, class _Distance> struct bidirectional_iterator {
		  typedef bidirectional_iterator_tag iterator_category;
		    typedef _Tp                        value_type;
			  typedef _Distance                  difference_type;
			    typedef _Tp*                       pointer;
				  typedef _Tp&                       reference;
};

template <class _Tp, class _Distance> struct random_access_iterator {
		  typedef random_access_iterator_tag iterator_category;
		    typedef _Tp                        value_type;
			  typedef _Distance                  difference_type;
			    typedef _Tp*                       pointer;
				  typedef _Tp&                       reference;
};

//定义iterator
template <class _Category, class _Tp, class _Distance = ptrdiff_t,
		           class _Pointer = _Tp*, class _Reference = _Tp&>
				   struct iterator {
						     typedef _Category  iterator_category;
							   typedef _Tp        value_type;
							     typedef _Distance  difference_type;
								   typedef _Pointer   pointer;
								     typedef _Reference reference;
				   };

//定义iterator_traits
template <class _Iterator>
struct iterator_traits {
		  typedef typename _Iterator::iterator_category iterator_category;
		    typedef typename _Iterator::value_type        value_type;
			  typedef typename _Iterator::difference_type   difference_type;
			    typedef typename _Iterator::pointer           pointer;
				  typedef typename _Iterator::reference         reference;
};

template <class _Tp>
struct iterator_traits<_Tp*> {
		  typedef random_access_iterator_tag iterator_category;
		    typedef _Tp                         value_type;
			  typedef ptrdiff_t                   difference_type;
			    typedef _Tp*                        pointer;
				  typedef _Tp&                        reference;
};

template <class _Tp>
struct iterator_traits<const _Tp*> {
		  typedef random_access_iterator_tag iterator_category;
		    typedef _Tp                         value_type;
			  typedef ptrdiff_t                   difference_type;
			    typedef const _Tp*                  pointer;
				  typedef const _Tp&                  reference;
};

//偏特化
template <class _Iter>
inline typename iterator_traits<_Iter>::iterator_category
iterator_category(const _Iter&) { 
		typedef typename iterator_traits<_Iter>::iterator_category _Category ; 
		std::cout<<"use template"<<std::endl;
		return _Category() ; 
}

//无偏特化
template <class _Tp, class _Distance> 
inline input_iterator_tag 
iterator_category(const input_iterator<_Tp, _Distance>&)
		  {
				  std::cout<<"use no template"<<std::endl;
				  return input_iterator_tag();
		  }

		  inline output_iterator_tag iterator_category(const output_iterator&)
		  { return output_iterator_tag(); }

		  template <class _Tp, class _Distance> 
		  inline forward_iterator_tag
		  iterator_category(const forward_iterator<_Tp, _Distance>&)
		  { return forward_iterator_tag(); }

		  template <class _Tp, class _Distance> 
		  inline bidirectional_iterator_tag
		  iterator_category(const bidirectional_iterator<_Tp, _Distance>&)
		  { return bidirectional_iterator_tag(); }

		  template <class _Tp, class _Distance> 
		  inline random_access_iterator_tag
		  iterator_category(const random_access_iterator<_Tp, _Distance>&)
		  { return random_access_iterator_tag(); }

//自创
template <class _Iter, class _Distance>
inline typename iterator_traits<_Iter>::iterator_category
iterator_category(const _Iter&) { 
		typedef typename iterator_traits<_Iter>::iterator_category _Category ; 
		std::cout<<"use mine"<<std::endl;
		return _Category() ; 
}


int main(){
	class myIter{
		
	
	};
	const	iterator<input_iterator_tag(),myIter>  it_test;
	input_iterator_tag result=iterator_category(it_test);
	return 0;

}
