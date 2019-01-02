#include <queue>
#include <map>
#include <iostream>

#include "graph.cpp"

using namespace std;

typedef map<Node*, bool> clearedMap;

/*
Return true if you have defeated the boss, false if they are unbeatable and the player must give up
NOTE: If you are too weak to defeat the boss, then don't try! You will be defeated and gain 0 Exquisite Chocolate points!

@param map      This graph contains everything you need to traverse over
@param bossNode Here resides the boss you must defeat once you are strong enough
*/
bool findBoss(Graph& map, Node* bossNode) {
    clearedMap cleared;
    queue<Node*> toVisit;
    queue<Node*> tooStrong;
    Node* playerNode = map.getPlayerNode();
    cout << playerNode->getStrength() << endl;

    // TODO: Follow the comments and finish this function!

    // Add initial neighbors to be visited
    //toVisit.push(playerNode);
    for (Node * neighbor: playerNode->neighbors) {
        if (playerNode->getStrength() > neighbor->getStrength()) toVisit.push(neighbor);
        else tooStrong.push(neighbor);
    }

    while(!toVisit.empty()) {
        // Check if we can teleport directly to the boss and win
        Node * cur = toVisit.front();
        toVisit.pop();
        cout << cur->getStrength() << endl;

        if (map.getPlayerNode()->getStrength() > bossNode->getStrength()) {
            map.movePlayer(map.getPlayerNode(), bossNode);
            return true;
        }

        if (map.getPlayerNode()->getStrength() > cur->getStrength()) {
            cleared[map.getPlayerNode()] = true;
            map.movePlayer(map.getPlayerNode(), cur);
            for (Node * neighbor: cur->neighbors) {
                if (!cleared[neighbor]) {
                    if (cur->getStrength() > neighbor->getStrength()) {
                        toVisit.push(neighbor);
                    }
                    else {
                        tooStrong.push(neighbor);
                    }
                    cleared[neighbor] = true;
                }
            }
        }

        unsigned size = tooStrong.size();
        for (unsigned i = 0; i < size; i++) {
            if (tooStrong.front()->getStrength() < map.getPlayerNode()->getStrength()) {
                toVisit.push(tooStrong.front());
                tooStrong.pop();
            }
            else {
                tooStrong.push(tooStrong.front());
                tooStrong.pop();
            }
        }
    }

    // If nowhere left to go or if we are strong enough, try beating the boss
    return false;
}
