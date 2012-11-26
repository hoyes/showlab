struct CueData {
    1: string uid,
    2: double number,
    3: string name,
}


service ShowService {
    string addCueWithNumber(1: double number, 2: string name);
    string addCueAtLocation(1: string location, 2: string name);
    list<CueData> getCues();
    CueData getCue(1: string id);
    void deleteCue(1: i32 id);
    void changeNumber(1: i32 id, 2: double number);
    void changeName(1: i32 id, 2: string name);
    
    void addAudioActionById(1: string cueid, 2: string filename);
    void addAudioActionByNumber(1: i32 num, 2: string filename);
    
    void newShow();
    
    void reset();
    void go();
    void standbyUid(1: string id);
    void standbyNum(1: double number);    
}
