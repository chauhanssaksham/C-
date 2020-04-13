class edge{
    int source;
    int destination;
    int weight;
    public: 
        edge(int source, int destination, int weight){
            this->source = source;
            this->destination = destination;
            this->weight = weight;
        }
        int getSource(){
            return this->source;
        }
        int getDestination(){
            return this->destination;
        }
        int getWeight(){
            return this->weight;
        }
        bool operator<(const edge &E) const{
            return weight < E.weight;
        }
};