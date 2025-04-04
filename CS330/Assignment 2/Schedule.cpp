#include <utility>
#include <algorithm>
#include <numeric>

#include "Schedule.h"

using namespace std::rel_ops;

//------------------------------------------------------------------------------
/**
 * @todo sanity check - is this function complete?
 */
Schedule::Schedule()
{
}

//------------------------------------------------------------------------------
/**
 * @todo implement this method.
 */
int Schedule::getCredits() const
{
    // Replace this stub return.
    const_iterator itr_begin = begin();
    const_iterator itr_end = end();
    const_iterator i = begin();

    int totalCredits = 0;

    for(i = itr_begin; i < itr_end; i++)
    {
        totalCredits+=i -> getCredits();
    }
    return totalCredits;
}

//------------------------------------------------------------------------------
/**
 * @todo implement this function
 */
void Schedule::appendNoCheck(Course course)
{
    allCourses.push_back(course);
}

//------------------------------------------------------------------------------
/**
 * @todo implement this function
 */
bool Schedule::wouldViolateCreditLimit(Course course) const
{
    // replace return true with the actual logic
    return (this->getCredits() + course.getCredits()) >CREDIT_LIMIT;
}

//------------------------------------------------------------------------------
/**
 * @todo implement this function
 */
bool Schedule::alreadyInSchedule(Course course) const
{
    // replace return false with the actual logic
    const_iterator itr_begin = begin();
    const_iterator itr_end = end();
    const_iterator i = begin();

    for(i = itr_begin; i < itr_end; i++)
    {
        if(i->getNumber()==course.getNumber())
        {
            return true;
        }
    }
    return false;
}

//------------------------------------------------------------------------------
/**
 * @todo implement this function
 */
void Schedule::display(std::ostream& outs) const
{
    // Write your output loop before this line
    const_iterator i = begin();
    while(i!=allCourses.end())
    {
        outs << " -";
        i -> display(outs);
        outs << "\n";
        i++;
    } 
       outs << "  (" << getCredits() << " Total Credits)" << "\n";

}
