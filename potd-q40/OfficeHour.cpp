#include <iostream>
#include "OfficeHour.h"
using namespace std;

/*
Given the current Office Hour queue and the currently on-duty staffers, return
how long the nth student will need to wait before a Staffer can reach them
Return -1 if there are no staff available to help the nth student

@param queue A queue containing the students currently waiting for help
@param onDutyStaff  A vector of Staffers currently on duty
@param nthStudent   The student for whom we are calculating a wait time
@return             How many minutes the nth student will have to wait before getting help
*/
int waitTime(queue<Student> queue, vector<Staffer> onDutyStaff, int nthStudent) {
    if (onDutyStaff.size() == 0) {
    	return -1;
    }

    vector<bool> staffAvailabilty;
    vector<int> staffTime;
    for (auto s: onDutyStaff) {
    	staffAvailabilty.push_back(true);
    	staffTime.push_back(0);
    }

    int count = 1;
    Student curStudent = queue.front();
    while (count < nthStudent) {
    	curStudent = queue.front();
    	queue.pop();

    	int lowestidx = -1;
    	int curBestStaffTime = -1;

    	for (unsigned i = 0; i < onDutyStaff.size(); i++) {
    		if (onDutyStaff[i].getEnergyLevel() > 0) {
    			lowestidx = i;
    			curBestStaffTime = staffTime[i];
    			break;
    		}
    		if ( (i == onDutyStaff.size() - 1) && lowestidx == -1) {
    			return -1;
    		}
    	}
    	
    	for (unsigned i = lowestidx; i < onDutyStaff.size(); i++) {
    		if (staffTime[i] < curBestStaffTime && onDutyStaff[i].getEnergyLevel() > 0) {
    			curBestStaffTime = staffTime[i];
    			lowestidx = i;
    		}
    	}
    	string question = curStudent.getQuestionType();
    	int studentTime = curStudent.getTimeNeeded();
    	cout << onDutyStaff[lowestidx].getEnergyLevel() << endl;
    	int timeNeeded = onDutyStaff[lowestidx].answerQuestion(question, studentTime);
    	staffTime[lowestidx] += timeNeeded;
    	count++;
    }
    
    int answer = -1;

    for (unsigned i = 0; i < onDutyStaff.size(); i++) {
    	if (onDutyStaff[i].getEnergyLevel() > 0) {
    		answer = staffTime[i];
    		break;
    	}
    	if ( (i == onDutyStaff.size() - 1) && answer == -1) {
    		return -1;
    	}
    }
    for (unsigned i = 1; i < staffTime.size(); i++) {
    	if (staffTime[i] < answer && onDutyStaff[i].getEnergyLevel() > 0) {
    		answer = staffTime[i];
    	}
    }
    return answer;
}
