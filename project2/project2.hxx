class Bitcoin {
public:
    int ath, currVal;
    void set_values (int, int);
    int diff(){ return ath - currVal;}
};
void Bitcoin::set_values(int x, int y){
    ath = x;
    currVal = y;
}
