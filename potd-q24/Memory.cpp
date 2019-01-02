#include "Memory.h"
#include <iostream>
#include <iomanip>
#include "Node.h"
#include <vector>
#include <utility>

using namespace std;

/**
Frees the given memory address. Returns if the free was successful or not
Be sure to merge adjacent free blocks when possible
*/
bool Memory::free(unsigned address) {
    Node* current = head;
    while (current != NULL) {
        if (current->address == address) {
            // Your code there
            current->inUse = false;
            if (current->next != NULL && !(current->next->inUse)) {
                Node * temp = current->next;
                current->next = current->next->next;
                if (current->next->next != NULL) {current->next->next->previous = current;}
                delete temp;
            }
            if (current->previous != NULL && !(current->previous->inUse)) {
                Node * temp = current;
                current->previous->next = current->next;
                if (current->next != NULL) current->next->previous = current->previous;
                delete temp;
            }
            return true;
        }
        current = current->next;
    }

    return false;
}


/**
Reorganizes memory structure so that all of the allocated memory is grouped at the bottom (0x0000) and there is one large
chunk of free memory above.

Note: We do not care about the order of the allocated memory chunks
*/
void Memory::defragment() {
    Node* current = head;
    while (current != NULL) {

        if (current->inUse) {
            // Do nothing
        } else {
            // TODO: Find the next chunk of allocated memory and shift it down to current's address
            // We recommend using the helper function `findNextAllocatedMemoryChunk
            Node * nextInUse = findNextAllocatedMemoryChunk(current);
            if (nextInUse == NULL) {return;}
            if (current == head) {head = nextInUse;}

            unsigned temp;
            if (nextInUse->next != NULL) {
                temp = nextInUse->next->address - nextInUse->address;
            }
            else {
                temp = maxAddress - nextInUse->address;
            }

            Node * tempprev = current->previous;

            current->previous = nextInUse;
            if (current->next == nextInUse) {
                current->next = nextInUse->next;
                if (current->next != NULL) {
                    current->next->previous = current;
                }
            }
            nextInUse->next = current;
            nextInUse->previous = tempprev;
            if (nextInUse->previous != NULL) {
                nextInUse->previous->next = nextInUse;
            }

            nextInUse->address = current->address;
            current->address = temp + nextInUse->address;

            if (current->next != NULL && !(current->next->inUse)) {
                Node * temp = current->next;
                current->next = current->next->next;
                if (current->next->next != NULL) {current->next->next->previous = current;}
                delete temp;
            }
            current = current->previous;
        }
        current = current->next;
    }

    // TODO: Finally merge all of the free blocks of memory together
}
