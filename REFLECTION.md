# Reflection questions

QUESTION 1) Why does concat only need to work between two lists of the same representation? What would
   you have to do differently, or what would go wrong, if you tried to make it work between a
   LinkedList and an ArrayList?

ANSWER 1) The concat function only needs to work with two lists of the same representation because otherwise, conversions between ArrayList and LinkedList are required. To do this, a new list would need to be created, then the specific values in the original representation of the list would need to be copied over to the other representation of the list. This takes up both time complexity (for loop for copying the values) and space complexity (new list used).


QUESTION 2) Walk through reverse() on your linked list: name the three pointers you need alive at once,
   and explain why losing track of any one of them mid-loop corrupts the list.

ANSWER 2) the three pointers needed for the reverse() function to work are a next pointer (originally not pointing to anything), a previous pointer (originally null), and a current pointer (originally pointing to head). While going through the list, the next points to the node after current, the next of current points to the same node as previous, previous points to the same node as current, and current points to the same node as next. After the loop ends (when current points to null pointer), the head pointer points to the same node as previous. This causes the nodes to point to each other in the opposite way, then, by moving the head pointer, it fully reverses it.

QUESTION 3) addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for
   position in each, and what does your implementation do if a caller passes a position outside
   it?

ANSWER 3) The valid range for position is 0 to size. If a caller passes a position outside of that range, an error message is printed basically telling them that. It doesn't crash the program or anything though.

QUESTION 4) In LinkedList::concat, why did you need to walk to the end of the list first, when addFront
   and deleteFront never needed to? What would change about concat’s performance if
   LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere
   if you added one back?

ANSWER 4) The reason why I needed to walk to the end of the list first in the concat function is because we're adding it to the end, and LinkedLists can't do random access. addFront and deleteFront never needed to because those involve changing where the head pointer is. If linkedlist had a tail pointer, there wouldn't be a need to traverse the list since we know where the end of it is. If there was a tail pointer, adding and removing at the ends using addAnywhere or deleteAnywhere would need to be updated, along with making sure tail pointer is pointing to the end of the reversed list with reverse().

QUESTION 5) Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what
   has to shift and in which direction, and why shifting in the wrong direction would overwrite
   data you still need.

ANSWER 5) In the addAnywhere function in ArrayList, everything after the position where the new value will go needs to be shifted to the right before the value is actually added. Shifting in the wrong direction can overwrite data because it'd be kind of like usig deleteAnywhere since a value is overwritten. However, the value would still be added at the position, possibly overwriting more data.

QUESTION 6) Point to the exact line in your main.cpp where a Reverse card actually changes the direction of
   play, and explain what would visibly break in the game if that call were missing.

ANSWER 6) Line 42 in main.cpp is the exact line where the reverse card actually changes the direction of play. The order of the game would visibly break if that line wasn't there.