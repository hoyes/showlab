struct CueData {
    1: double number,
    2: string name,
}


service ShowService {
    i32 addCueWithNumber(1: double number, 2: string name);
    i32 addCueAtLocation(1: i32 location, 2: string name);
    list<CueData> getCues();
    CueData getCue(1: i32 id);
    void deleteCue(1: i32 id);
    void changeNumber(1: i32 id, 2: double number);
    void changeName(1: i32 id, 2: string name);
    
    void newShow();
}
