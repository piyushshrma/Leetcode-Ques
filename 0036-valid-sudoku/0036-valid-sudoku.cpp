class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(isdigit(b[i][j])){

                    //sameRow
                    for(int r=0;r<9;r++){
                        if(b[r][j]==b[i][j]&&i!=r){
                            return false;
                        }
                    }

                    //sameCol
                    for(int c=0;c<9;c++){
                        if(b[i][c]==b[i][j]&&j!=c){
                            return false;
                        }
                    }

                    //sameSqaure
                    int r=i/3;
                    int c=j/3;

                    //0,0
                    if(r==0&&c==0){
                        for(int x=0;x<3;x++){
                            for(int y=0;y<3;y++){
                                if(b[x][y]==b[i][j] && i!=x && j!=y){
                                    return false;
                                }
                            }
                        }
                    }
                    //0,1
                    if(r==0&&c==1){
                        for(int x=0;x<3;x++){
                            for(int y=3;y<6;y++){
                                if(b[x][y]==b[i][j] && i!=x && j!=y){
                                    return false;
                                }
                            }
                        }
                    }
                    //0,2
                    if(r==0&&c==2){
                        for(int x=0;x<3;x++){
                            for(int y=6;y<9;y++){
                                if(b[x][y]==b[i][j] && i!=x && j!=y){
                                    return false;
                                }
                            }
                        }
                    }

                    //1,0
                    if(r==1&&c==0){
                        for(int x=3;x<6;x++){
                            for(int y=0;y<3;y++){
                                if(b[x][y]==b[i][j] && i!=x && j!=y){
                                    return false;
                                }
                            }
                        }
                    }
                    //1,1
                    if(r==1&&c==1){
                        for(int x=3;x<6;x++){
                            for(int y=3;y<6;y++){
                                if(b[x][y]==b[i][j] && i!=x && j!=y){
                                    return false;
                                }
                            }
                        }
                    }
                    //1,2
                    if(r==1&&c==2){
                        for(int x=3;x<6;x++){
                            for(int y=6;y<9;y++){
                                if(b[x][y]==b[i][j] && i!=x && j!=y){
                                    return false;
                                }
                            }
                        }
                    }

                    //2,0
                    if(r==2&&c==0){
                        for(int x=6;x<9;x++){
                            for(int y=0;y<3;y++){
                                if(b[x][y]==b[i][j] && i!=x && j!=y){
                                    return false;
                                }
                            }
                        }
                    }
                    //2,1
                    if(r==2&&c==1){
                        for(int x=6;x<9;x++){
                            for(int y=3;y<6;y++){
                                if(b[x][y]==b[i][j] && i!=x && j!=y){
                                    return false;
                                }
                            }
                        }
                    }
                    //2,2
                    if(r==2&&c==2){
                        for(int x=6;x<9;x++){
                            for(int y=6;y<9;y++){
                                if(b[x][y]==b[i][j] && i!=x && j!=y){
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};