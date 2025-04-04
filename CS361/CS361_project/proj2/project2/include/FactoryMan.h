#ifndef FACTORYMAN_H
#define FACTORYMAN_H


class FactoryMan
{
    public:
        /*
        1. Recieves new designs
        designs are a sequence of integers
        for example 3,8,3,5 price point (pp) 25 and cost is 19
        machines are a 2x6 or 1x12 vector that holds 12 spots, 4 of them would be 3,8,3,5
        2. New design comes in 1,2,11,2,1 and we need to check if we have room for it
        we used 4 of 12 spots so we use the next 5 for the new design
        we must check the profit per machine and then get rid of the less profitable machines
        in order to make room for more profitable machines
        3. If a new machine comes in, and there are more machines used, it should
        calculate the overall value being produced and check if it is making more money
        then keep which makes more money
        4. Replace factory machines if profit per machine (ppm) > old
        there is a larger machine usage that fits
        5. machines will look like [1,1,1,1,2,2,2,3,3,3,4,0]
        size is 12 and there are 4 things being made with 1 unused spot
        */
        FactoryMan();
        virtual ~FactoryMan();

    private:


};

#endif // FACTORYMAN_H
