#include <iostream>
#include "List.h"
#include "Player.h"
int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
    << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----

    std::unique_ptr<List<Player>> table = makeList<Player>();
    table->addFront(new Player(1, "Yousif"));
    table->addFront(new Player(2, "Tom"));
    table->addFront(new Player(4, "Mary"));
    table->addFront(new Player(5, "Chase"));
    table->print();

    table->addAnywhere(1, new Player(3, "Alice"));

    table->print();

    table->reverse();

    table->print();

    table->deleteAnywhere(1);
    table->print();

    std::unique_ptr<List<Player>> otherTable = makeList<Player>();
    otherTable->addFront(new Player(20, "Larry"));
    otherTable->addFront(new Player(30, "Tracey"));
    table->concat(otherTable.get());
    table->print();




    return 0;
}