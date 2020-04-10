#include <vector>
using namespace std;
class PriorityQueue{
    vector<int> PQ;
 public:
    PriorityQueue(){
    }
    
    void insert(int element){
        PQ.push_back(element);
        int currentIndex = PQ.size() - 1;
        int parentIndex = (currentIndex - 1)/2;
        while(currentIndex > 0 && PQ[parentIndex] > PQ[currentIndex]){
            PQ[currentIndex] = PQ[parentIndex];
            PQ[parentIndex] = element;
            currentIndex = parentIndex;
            parentIndex = (parentIndex - 1 ) / 2;
        }
    }

    int removeMin() {
        // Complete this function
      int ans = PQ[0];
      PQ[0] = PQ[PQ.size()-1];
      PQ.pop_back();
      int i = 0;
      int CI1 = 1, CI2 =2;
      int last_index = PQ.size();
      while(CI2 < last_index){
        if (PQ[i] > min(PQ[CI1], PQ[CI2])){
          if (min(PQ[CI1], PQ[CI2]) == PQ[CI1]){
            int temp = PQ[i];
            PQ[i] = PQ[CI1];
           	PQ[CI1] = temp;
            i = CI1;
            CI1 = (2*i)+1;
            CI2 = (2*i)+2;
          } else{
            int temp = PQ[i];
            PQ[i] = PQ[CI2];
           	PQ[CI2] = temp;
            i = CI2;
            CI1 = 2*i+1;
            CI2 = 2*i+2;
          }
        } else{
          break;
        }
      }
      return ans;
    }

    int getSize() const{
        return PQ.size();
    }

    bool isEmpty() const{
        return PQ.size() == 0;
    }

    int getMin() const{
        if (isEmpty()){
            return 0;
        } 
        return PQ[0];
    }
    void printTree(){
        for (int i=0; i<PQ.size(); i++){
            cout << PQ[i] << " ";
        }
        cout << endl;
    }
};