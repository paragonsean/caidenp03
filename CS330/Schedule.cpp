#include <utility>
#include "Schedule.h"

using namespace std::rel_ops;

Schedule::Node::Node(Course c)
    :data(c),
     next(nullptr)
{
}

//------------------------------------------------------------------------------
Schedule::Schedule()
    :head(nullptr),
     tail(nullptr),
     totalCredits(0)
{
}

/**
 * @todo implement this function (it is simliar to Review 01)
 */
Schedule::Schedule(const Schedule& src){

    this->head = nullptr;
    this->tail = nullptr;
    this->totalCredits = 0;

    //make new node outside for loop
    Node *it = src.head;

    while(it != nullptr){
        appendNoCheck(it->data);
        it = it->next;
    }

    // Copy the src Linked List **data**
}

/**
 * @todo implement this function (it is similar to Review 01)
 */
Schedule::~Schedule()
{
    Node *this_iterator = nullptr;
    Node *to_delete = nullptr;

    this_iterator = this->head;

    while( this_iterator != nullptr ){
        to_delete = this_iterator;

        this_iterator = this_iterator->next;

        delete to_delete;
        to_delete = nullptr;
    }
}

/**
 * @todo implement this function (it is similar to Review 01)
 */
void Schedule::appendNoCheck(Course course)
{
    Node *new_node = new Node(course);

    if(this->head == nullptr){
        this->head = new_node;
        this->tail = new_node;
    }
    else{
        (this->tail)->next = new_node;
        this->tail = new_node;
    }
    totalCredits+=course.getCredits();
}

/**
 * @todo implement this function
 */
bool Schedule::wouldViolateCreditLimit(Course course) const
{
    // The following line is a placeholder (i.e., enough for the code to
    // compile). Remove it when you start implementing this function.
    

    return (course.getCredits() + totalCredits) > CREDIT_LIMIT;

    ///return true;
}

/**
 * @todo implement this function
 */
bool Schedule::alreadyInSchedule(Course course) const
{
    // Check if the student is registered
    // for a different section of the same course
    Node* it = this->head;
    while (it != nullptr){
            if(it->data.getNumber() == course.getNumber()){
                return true;
        }
        it = it->next;
    }
    return false;
}
    // The following line is a placeholder (i.e., enough for the code to
    // compile). Remove it when you start implementing this function.
   /// return true;
    

//------------------------------------------------------------------------------
void Schedule::display(std::ostream& outs) const
{
    Node* it = head;

    outs << "  (" << totalCredits << " Total Credits)" << "\n";

    while (it != nullptr) {
        outs << "  - " << (it->data) << "\n";

        it = it->next;
    }
}

//------------------------------------------------------------------------------
Schedule& Schedule::operator=(Schedule rhs)
{
    swap(*this, rhs);

    return *this;
}
