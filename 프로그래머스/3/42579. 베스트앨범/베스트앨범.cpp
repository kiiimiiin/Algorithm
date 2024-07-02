#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define X first
#define Y second

using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.X != b.X) return a.X > b.X; // plays가 큰 순으로
    return a.Y < b.Y; // 고유넘버가 작은순으로
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> m; 
    
    for(int i = 0 ; i < genres.size(); i++){
        m[genres[i]] += plays[i];
    }
    
    vector<pair<string,int>> s_genres(m.begin(), m.end()); // 장르, play 총합
    sort(s_genres.begin(), s_genres.end(), [](auto& a, auto& b){return a.Y > b.Y;});
    
    for(auto g : s_genres){
        vector<pair<int, int>> songs; // plays, 고유번호
        
        for(int i = 0 ; i < genres.size(); i++){
            if(g.X == genres[i]) songs.push_back({plays[i], i});    
        }
        
        int size = songs.size();
        if(size == 1){
            answer.push_back(songs[0].Y);
        }else{
            sort(songs.begin(), songs.end(), cmp);
            answer.push_back(songs[0].Y);
            answer.push_back(songs[1].Y);
        }
    }
    
    
    return answer;
}

/* 
    1.장르 내 노래 재생 합이 높은 장르 먼저 수록 (장르별 2개만 수록한다.)
        1.1 장르 내 노래 재생이 높은 노래 수록
        1.2 같으면 고유 번호가 낮은 노래 먼저 수록
        
    sudo : 
    벡터 순회로 multi map 특정 장르에 대한 총합구하여 sort
    sort한 장르에 대한 플레이수 및 고유번호 추출하여 높은 우선순위 2개의 고유번호 ans에 push 
*/