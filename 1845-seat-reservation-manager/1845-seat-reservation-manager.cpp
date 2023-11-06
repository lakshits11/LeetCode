class SeatManager {
    // Marker to point to unreserved seats.
    int marker;

    // Sorted set to store all unreserved seats.
    set<int> availableSeats;

public:
    SeatManager(int n) {
        // Set marker to the first unreserved seat.
        marker = 1;
    }

    int reserve() {
        // If the sorted set has any element in it, then,
        // get the smallest-numbered unreserved seat from it.
        if (!availableSeats.empty()) {
            int seatNumber = *availableSeats.begin();
            availableSeats.erase(availableSeats.begin());
            return seatNumber;
        }

        // Otherwise, the marker points to the smallest-numbered seat.
        int seatNumber = marker;
        marker++;
        return seatNumber;
    }

    void unreserve(int seatNumber) {
        // Push unreserved seat in the sorted set.
        availableSeats.insert(seatNumber);
    }
};