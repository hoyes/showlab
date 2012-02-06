struct CueData {
    1: string number,
    2: string name,
}


service ShowService {
    i32 addCue(1: CueData data, 2: i32 location);
    list<CueData> getCues();
    CueData getCue(1: i32 id);
    void deleteCue(1: i32 id);
    void changeNumber(1: i32 id, 2: string number);
    void changeName(1: i32 id, 2: string name);
    
}
