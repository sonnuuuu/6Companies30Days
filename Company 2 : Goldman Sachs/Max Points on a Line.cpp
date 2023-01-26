class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<=2){return points.size();}//two or less points are always in a straight line
        int infinite=0;//to handle points with infinite slope
        int ans=0;//to store the number of maxpoints in a line
        double slope;
    
    for(int i=0;i<points.size()-1;i++){//iterating over points
        unordered_map<double,int> mp;//to store the occurance of a slope
        for(int j=i;j<points.size();j++){//checking slope of the point with other points
            
            if(points[j][0]==points[i][0]){//if x coordinates are same
                infinite++; //increment for infinite slope
                ans=max({ans,infinite});//update answer
            }
            else{//if slope is not infinite
                slope=(double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);//calculate slope
                mp[slope]++;//update map
                ans=max({ans,mp[slope]+1});//update answer
            }   
        }
        infinite=0;//make it zero after iterating
    }    
    return ans;
    }
};
