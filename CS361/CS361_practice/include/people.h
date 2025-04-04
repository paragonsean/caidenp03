#ifndef PEOPLE_H
#define PEOPLE_H


class people
{
    public:
        people();
        virtual ~people();

        int GetGetid() { return Getid; }
        void SetGetid(int val) { Getid = val; }
        int GetSetid() { return Setid; }
        void SetSetid(int val) { Setid = val; }

    protected:

    private:
        int Getid;
        int Setid;
};

#endif // PEOPLE_H
