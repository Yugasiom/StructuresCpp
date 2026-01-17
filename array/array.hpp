#ifndef  ARRAY_HPP_INCLUDED

#define  ARRAY_HPP_INCLUDED


#include <cstdint>
#include <iostream>


class Array
{
    private:
        int64_t *data;
        uint64_t current_size, capacity;

    public:
        Array              (uint64_t = 0);

        void     print     (       ) const;
        void     resize    (uint64_t);
        uint64_t find_index(int64_t) const;
        void     prepend   (int64_t);
        void     append    (int64_t );
        void     insert    (uint64_t, int64_t);
        void     remove    (int64_t);

        ~Array      ();
};


#endif   /// ARRAY_HPP_INCLUDED
