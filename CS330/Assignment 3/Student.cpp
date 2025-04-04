#include <utility>
#include "Student.h"

// Allow the compiler to define the remaining
// comparison operators
using namespace std::rel_ops;

//------------------------------------------------------------------------------
Student::Student()
    :Student("ERROR")
{
}

//------------------------------------------------------------------------------
Student::Student(std::string n)
    :name(n)
{
    schedule = new Schedule;
        // @todo create a new empty schedule
}

//------------------------------------------------------------------------------
// @todo implement this function
Student::Student(const Student& src)
{
    // @todo copy the name
    name = src.name;
    // @todo create a deep copy of src.schedule

    schedule = new Schedule(*src.schedule);
}

//------------------------------------------------------------------------------
// @todo implement this function
Student::~Student()
{
    delete this->schedule;
    // @todo make sure that the schedule attribute (data member) is deallocated
}

//------------------------------------------------------------------------------
void swap(Student& lhs, Student& rhs)
{
    // @todo swap the lhs name and rhs name
    using std::swap;

    swap(lhs.name, rhs.name);
    swap(lhs.schedule, rhs.schedule);
    // @todo swap the lhs schedule and rhs schedule
}

//------------------------------------------------------------------------------
void Student::display(std::ostream &outs) const
{
    outs << " " << name << "\n";
    outs << *schedule;

    // @todo Add the line to output the schedule.
}

//------------------------------------------------------------------------------
bool Student::enrollIn(const Course &toAdd)
{
    return schedule->add(toAdd);
}


