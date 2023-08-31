/**
 * @file quack.cpp
 * Implementation of the Quack class.
 *
 */

template <class T>
Quack<T>::Quack() {
    /**
     * @todo Your code here!
     */
    n1 = 0;  // index of the left side of the contiguous block of data (empty)
    n2 = 0; // index of the right side of the contiguous block of data (empty)
    // data = std::vector<T>();
}

/**
 * Adds the parameter object to the right of the Quack.
 *
 * @param newItem object to be added to the Quack.
 */
template <class T>
void Quack<T>::pushR(T newItem) {
    /**
     * @todo Your code here!
     */

    data.push_back(newItem);

    // if (n2 + 1 == data.size()) { // if there is enough space already in the vector, we can use push_back
    //     data.push_back(newItem); // to add the new item to the right end
    // } else {
    //     data[n2 + 1] = newItem;  // else we add a new item to the current right end
    // }
    n2++;
    // This function has O(1) over n operations since push_back() is implemented in constant time
    // when there is enough space to copy over the items. 
}

/**
 * Removes the object at the left of the Quack, and returns it to the
 * caller.
 *
 * See .h file for implementation notes.
 *
 * @return The item that used to be at the left of the Quack.
 */
template <class T>
T Quack<T>::popL() {
    /**
     * @todo Your code here! You will need to replace the following line.
     */

    if (isEmpty()) {
        return T();
    }

    T leftObject = data[n1];   // assigns the leftmost item to the variable, object
    n1++;                  // increment the left index to remove object from the left side

    int num = n2 - n1; // number of elements

    if (num <= n1) {
        vector<T> nData;

        for (int i = 0; i < num; i++) {
            nData.push_back(data[i + n1]);
        }
        data = nData;
        n1 = 0;
        n2 = num;
    }

    return leftObject;

    // if (n1 > (data.size() / 2)) { // check to see if the leftmost item index is greater than to size/2
    //     // resize the vector
    //     int num = n2 - n1 + 1;    // num is the number of elements 
    //     std::vector<T> nData(num);

    //     for (int i = 0; i < num; i++) {
    //         nData[i] = data[n1 + i];
    //     }
    //     data = nData;
    //     n1 = 0;   // setting the index of leftmost element to be 0
    //     n2 = num - 1;
    // }

    // return leftObject;
    // return T();
}
/**
 * Removes the object at the right of the Quack, and returns it to the
 * caller.
 *
 * @return The item that used to be at the right of the Quack.
 */
template <class T>
T Quack<T>::popR() {
    /**
     * @todo Your code here! You will need to replace the following line.
     */

    if (isEmpty()) {
        return T();
    }

    T rightObject = data[n2 - 1];
    // n2--;   // removes the item from the right end
    data.pop_back();
    n2--;   // removes the item from the right end

    int num = n2 - n1; // number of elements


    if (num <= n1) {
        vector<T> nData;

        for (int i = 0; i < num; i++) {
            nData.push_back(data[i + n1]);
        }
        data = nData;
        n1 = 0;
        n2 = num;
    }

    return rightObject;




    // if (n2 < (data.size() / 4)) {
    //     int num = n2 - n1 + 1;
    //     std::vector<T> nData(num);

    //     for (int i = 0; i < num; i++) {
    //         nData[i] = data[n1 + i]; 
    //     }

    //     data = nData;
    //     n1 = 0;
    //     n2 = num - 1;
    // }

    // return rightObject;
    // return T();
}

/**
 * Finds the object at the left of the Quack, and returns it to the
 * caller. Unlike popL(), this operation does not alter the quack.
 *
 * @return The item at the front of the quack.
 */
template <class T>
T Quack<T>::peekL() {
    /**
     * @todo Your code here! You will need to replace the following line.
     */

    if (isEmpty()) {
        return T();
    }

    return data[n1];

    // return T();
}

/**
 * Finds the object at the right of the Quack, and returns it to the
 * caller. Unlike popR(), this operation does not alter the quack.
 *
 * @return the value of The item at the right of the quack.
 */
template <class T>
T Quack<T>::peekR() {
    /**
     * @todo Your code here! You will need to replace the following line.
     */
    if (isEmpty()) {
        return T();
    }
    return data[n2 - 1];

    // return T();
}

/**
 * Determines if the Quack is empty.
 *
 * @return bool which is true if the Quack is empty, false otherwise.
 */
template <class T>
bool Quack<T>::isEmpty() const {
    /**
     * @todo Your code here! You will need to replace the following line.
     */

    return (n1 == n2);
    
    // return true;
}
