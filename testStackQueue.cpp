#include <iostream>

#include "cs221util/catch.hpp"
#include "queue.h"
#include "stack.h"
using namespace std;

TEST_CASE("stack::basic functions", "[weight=1][part=stack]") {
    // cout << "Testing Stack..." << endl;
    Stack<int> intStack;
    vector<int> result;
    vector<int> expected;
    for (int i = 10; i > 0; i--) {
        expected.push_back(i);
    }
    for (int i = 1; i <= 10; i++) {
        intStack.push(i);
    }
    while (!intStack.isEmpty()) {
        result.push_back(intStack.pop());
    }
    REQUIRE(result == expected);
}

TEST_CASE("queue::basic functions", "[weight=1][part=queue]") {
    Queue<int> intQueue;
    vector<int> result;
    vector<int> expected;
    for (int i = 1; i <= 10; i++) {
        expected.push_back(i);
    }
    for (int i = 1; i <= 10; i++) {
        intQueue.enqueue(i);
    }
    while (!intQueue.isEmpty()) {
        result.push_back(intQueue.dequeue());
    }
    REQUIRE(result == expected);
}


TEST_CASE("stack::peek", "[weight=1][part=stack]") {
    Stack<int> intStack;
    for (int i = 1; i <= 10; i++) {
        intStack.push(i);
    }
    int result = intStack.peek();
    cout << "peek result: " << result << endl;
    int expected = 10;
    REQUIRE(result == expected);
}

TEST_CASE("quack::pushR", "[weight=1][part=quack]") {
    Quack<int> intQuack;
    for (int i = 1; i <= 5; i++) {
        intQuack.pushR(i);
    }
    //REQUIRE(intQuack.size() == 5);
    intQuack.pushR(6); // pushR should add 6 to the quack
    //REQUIRE(intQuack.size() == 6);
    int result = intQuack.popR(); // popR should remove 6 from the quack
    int expected = 6;
    REQUIRE(result == expected);
}


TEST_CASE("quack::pushR", "[weight=1][part=quack]") {
    Quack<int> intQuack;
    for (int i = 1; i <= 5; i++) {
        intQuack.pushR(i);
    }
    //REQUIRE(intQuack.size() == 5);
    intQuack.pushR(6); // pushR should add 6 to the quack
    //REQUIRE(intQuack.size() == 6);
    int result = intQuack.popR(); // popR should remove 6 from the quack
    int expected = 6;
    REQUIRE(result == expected);
}

TEST_CASE("quack::pushR", "[weight=1][part=quack]") {
    Quack<int> intQuack;
    for (int i = 1; i <= 5; i++) {
        intQuack.pushR(i);
    }
    //REQUIRE(intQuack.size() == 5);
    intQuack.pushR(6); // pushR should add 6 to the quack
    //REQUIRE(intQuack.size() == 6);
    int result = intQuack.popR(); // popR should remove 6 from the quack
    int expected = 6;
    REQUIRE(result == expected);
}





