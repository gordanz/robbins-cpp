#include "llist.h"

LList::LList(double *in_x, sint in_max, sint in_size)
{
    max_size = in_max;
    x = in_x;
    size = in_size;
    first = (ptr) 0;
    next = NULL;
    next = new ptr[in_max];

    rranks = NULL;
    rranks = new sint[in_max];
    rranks[0] = 1;

    for (sint i=0; i<in_size; i++){
        next[i] = i+1;
    };

    next[in_size-1] = OVER;
}

LList::~LList()
{
    // delete[] next;
    delete[] rranks;
}

string LList::str_list()
{
    stringstream stream;
    stream << "[ ";
    for (ptr now = first; now != OVER; now = next[now]){
        stream << fixed << setprecision(2) << x[now];
        if (next[now] != OVER)
            stream << ", ";
        else
            stream << " ]";
    }
    return(stream.str());
}

string LList::str_raw()
{
    stringstream stream;
    stream << "[ ";
    for (sint i=0; i<max_size; i++){
        stream << fixed << setprecision(2) << x[i];
        if (i+1 < max_size)
            stream << ", ";
        else
            stream << " ]";
    }
    return(stream.str());
}

string LList::str_next()
{
    stringstream stream;

    stream << fixed << setprecision(2) << first;
    stream << ", [ ";
    for (sint i=0; i<size; i++){
        stream << fixed << setprecision(2) << next[i];
        if (i+1 < size)
            stream << ", ";
        else
            stream << " ]";
    }
    return(stream.str());
}


string LList::str_rranks()
{
    stringstream stream;

    stream << "[ ";
    for (sint i=0; i<size; i++){
        stream << fixed << setprecision(2) << rranks[i];
        if (i+1 < size)
            stream << ", ";
        else
            stream << " ]";
    }
    return(stream.str());
}


void LList::insert_next_after(ptr i)
{
    if (size == max_size ){
        cerr << endl << ">>>>>>> Problem in insert_next_after" << endl;
        cerr << ">>>>>>> Max size must be > size" << endl << endl;
        exit (EXIT_FAILURE);
    };

    if (i > size-1 && i != OVER){
        cerr << endl << ">>>>>>> Problem in insert_next_after" << endl;
        cerr << ">>>>>>> Insert only at i < size - 1" << endl << endl;
        exit (EXIT_FAILURE);
    };

    ptr aux;
    if (i == OVER){
        aux = first;
        first = size;
        next[size] = aux;
    }
    else
    {
       aux = next[i];
       next[i] = size;
       next[size] = aux;
    }

    size++;

}

void LList::print_all(void)
{
    cout << "size = " << size <<", max_size = " << max_size << endl;
    cout << " x: " << str_raw() << endl;
    cout << " l: " << str_list() << endl;
    cout << " p: " << str_next() << endl;
    cout << " r: " << str_rranks() << endl;
}

void rank_position::print_all()
{
    cout << "rank = " << rank <<", pos = " << position << endl;
}

rank_position LList::find_rrank_and_position()
{
    if (size == max_size ){
        cerr << endl << ">>>>>>> Problem in find_rrank_and_position" << endl;
        cerr << ">>>>>>> Max size must be > size" << endl << endl;
        exit (EXIT_FAILURE);
    };

    ptr today = first;
    ptr yesterday = OVER;
    rank_position rout;
    rout.rank=12;
    rout.position=1;
    rout.rank=1;
    double y;
    y = x[size];
    while ((today != OVER) && (x[today] < y)){
            rout.rank++;
            yesterday = today;
            today = next[today];
    }
    rout.position=yesterday;
    return(rout);

}



