#include <bits/stdc++>
using namespace std;

class job {
	public:
		int bt;
		int ct;
		int tat;
		int wt;
        int pty;

        bool operator < (const job &job1) const{

			if(pty==job1.pty){
				return bt<job1.bt;
			}

			return pty>job1.pty;
		}
};

// 3 5 10 4 2 1 1

class priority{
    public:
		job* jobs;
		int n;

		float aveWait, aveTAT;

		priority(int n) {
		    aveTAT = 0;
		    aveWait = 0;
			this -> n = n;
			jobs = new job[n];
		}

        void schedule() {

            sort(jobs, jobs + n);

            for(int i = 0; i < n; i++) {
                if(i == 0)
					jobs[i].ct = jobs[i].bt;
				else 
					jobs[i].ct = jobs[i - 1].ct + jobs[i].bt;
				
				jobs[i].tat = jobs[i].ct;
				jobs[i].wt = jobs[i].tat - jobs[i].bt;
				
				aveTAT += jobs[i].tat;
				aveWait += jobs[i].wt;
            }

            // for(int i = 0; i < n; i++) {
            //     cout << jobs[i].pty << " ";
            // }
        }

        void takeinput() {
			cout << "Enter the burst times and the priority of the jobs: " << endl;
			for(int i = 0; i < n; i++) {
				cin >> jobs[i].bt >> jobs[i].pty;
			}

			schedule();
		}

        void printTable() {
			cout << endl << endl << endl;
			cout << "Priority   " << "Burst Time    " << "Completion Time       " << "TAT          " << "Wait Time" << endl << endl; 
			for(int i = 0; i < n; i++) {
				cout << jobs[i].pty << '\t' << '\t' << jobs[i].bt << '\t' << '\t' << jobs[i].ct << '\t' << '\t' << jobs[i].tat << '\t' << '\t' << jobs[i].wt << '\t' << endl;
			}
			
			cout << "The average TAT time is: " <<  aveTAT << endl;
			cout << "The average wait time is: " << aveWait << endl;
		}
};

int main() {
	cout << "Enter the number of jobs: " << endl;
	int j;
	cin >> j;


	priority cpu(j);
	cpu.takeinput();
	cpu.printTable();
}