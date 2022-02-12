1. Two people meet each other (Easy) https://www.geeksforgeeks.org/check-if-two-people-starting-from-different-points-ever-meet/

first untill it will be equal use while loop and do couting

M-2  relative speed se
     // If speed of a person at a position before
    // other person is smaller, then return false.
    if (x1 < x2 && v1 <= v2)
    return false;
    if (x1 > x2 && v1 >= v2)
    return false; 

    if (x1 < x2) // Making sure that x1 is greater
    {
    swap(x1, x2);
    swap(v1, v2);

    // checking if relative speed is
    // a factor of relative distance or not
    return ((x1 - x2) % (v1 - v2) == 0);