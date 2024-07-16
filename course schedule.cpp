#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_courses(vector <vector<int>> courses){
sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort by deadline date
        });
        int days = 0;//tracking how many days worked 
        int count = 0;// cpourse taken 
        priority_queue<int> pq;// to track which taken with there durations
        // iterate over the vector of inputs 
        for (auto& i : courses) {
            // worked on formula worked date plus number of date to do course sum to less then the deadline we consider that couse else leave it and if then push it in the queue
            if (days + i[0] <= i[1]) {
                days += i[0];
                pq.push(i[0]);
                count++;
            } else if (!pq.empty() && pq.top() > i[0]) {
                // if end date reached but the top is taking the less time then new course we remove it add the new course and then update the date worked accordingly
                days -= pq.top();
                pq.pop();
                days += i[0];
                pq.push(i[0]);
            }
        }
        return count;// ans
}

int main(){
	// taking in puts
	int n;
	cin >> n;
	vector<pair<int, int>> time_table;
	for( int i=0;i<n;i++){
		int last_date,duration;
		cin >> duration>> last_date;
		//here i am changed the formate of courses[i] = {duration,last_date} to {last_date,duration} for the use of sorting algorithm without any advance method 
		time_table.push_back({last_date,duration});
	}
	int ans = max_courses(time_table);
	cout << ans;
}