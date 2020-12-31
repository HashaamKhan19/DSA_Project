#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

struct Booking
{
public:
    int SeatNumber;
    bool IsBooked;
    string BookedBy = "Hashaam";

    Booking()
    {
    }

    Booking(int routeId, int seatNumber)
    {
        this->RouteID = routeId;
        this->SeatNumber = seatNumber;
    }

    Booking *next = NULL;

    int RouteID;
};

Booking *head = NULL;

bool isSeatAlreadyTaken(int routeId, int seatNumber)
{
    Booking *current = head;
    while (current != NULL)
    {
        // In fact this should be seatNumber
        if (current->RouteID == routeId && current->RouteID == seatNumber)
        {
            return true;
        }
        current = current->next;
    }
    //
    return false;
}

bool createBooking(int routeId, int seatNumber)
{
    if (isSeatAlreadyTaken(routeId, seatNumber))
    {
        return false;
    }

    Booking *booking = new Booking(routeId, seatNumber);
    booking->next = NULL;
    if (head == NULL)
    {
        head = booking;
    }
    else
    {
        Booking *current = head;
        while (current->next != NULL)
        {
        }
        current->next = booking;
        current = current->next;
    }
    return true;
}

bool cancelBooking(int routeId, int seatNumber)
{
    Booking *previous = NULL;
    Booking *current = head;

    while (current != NULL)
    {
        if (current->RouteID == routeId && current->SeatNumber == seatNumber)
        {
            if (current == head)
            {
                if (current->next == NULL)
                {
                    head = NULL;
                }
                else
                {
                    head = current->next;
                }
            }
            else
            {
                if (current->next == NULL)
                {
                    previous->next = NULL;
                    delete current;
                }
                else
                {
                    previous->next = current->next;
                    delete current;
                }
            }
            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
}

void printBookings()
{
    Booking *current = head;
    if (head == NULL)
    {
        cout << "There are no Seats currently Booked!\n " << endl;
        // runner();
    }
    else
    {
        while (current != NULL)
        {
            cout << "Seat # " << current->SeatNumber << " Booked by " << current->BookedBy << " For Route # " << current->RouteID << endl;
            current = current->next;
        }
    }
}

void runner()
{
    while (true)
    {
        cout << "Enter 1 to Book a Ticket" << endl;
        cout << "Enter 2 to Check current Bookings" << endl;
        cout << "Enter 3 to Cancel Booking" << endl;
        cout << "--> ";
        cout << "";

        int routeId;

        int menu;
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "Currently Available Routes are \n";
            cout << "Islamabad to Karachi." << endl;
            cout << "Karachi to Islamabad." << endl;
            cout << "" << endl;
            cout << "Press 1 to Book Seat for ISB to KHI" << endl;
            cout << "Press 2 to Book Seat for KHI to ISB \n"
                 << endl;
            cout << "--> ";
            cin >> routeId;
            //
            // Hardcoded, replace second parameter with Seat Number
            //
            if (createBooking(routeId, routeId))
            {
                cout << "Your Seat has been booked " << endl
                     << endl;
            }
            else
            {
                cout << "*** Sorry! The seat is already taken" << endl
                     << endl;
            }
            // bool isBooked = createBooking(routeId, routeId);
            // if (isBooked)
            // {
            //     cout << "*** Seat has been booked" << endl
            //          << endl;
            // }
            // else
            // {
            //     cout << "*** Sorry seat is already taken" << endl
            //          << endl;
            // }
            break;

        case 2:
            // cout << "Printing Bookings :" << endl
            //      << endl;
            printBookings();
            break;
        case 3:
            //cout << "Select a Booking :" << endl;
            //printBookings();
            if (head == NULL)
            {
                cout << "There are no Seats currently Booked!\n " << endl;
                // runner();
            }
            else
            {

                int routeId;
                int seatNumber;

                cout << "Enter Route ID : " << endl;
                cin >> routeId;

                cout << "Enter Seat Number : " << endl;
                cin >> seatNumber;

                if (cancelBooking(routeId, seatNumber))
                {
                    cout << "Booking has been cancelled\n"
                         << endl;
                }
                else
                {
                    cout << "No such booking found\n"
                         << endl;
                }
            }
            break;

        default:
            cout << "Invalid Entry, please try again";
            break;
        }
    }
}

int main()
{
    runner();
    return 1;
}
