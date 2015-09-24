#include <cstdio>
#include <queue>
#include <vector>

#define SIZE 3

int pattern_type[SIZE][SIZE][SIZE*SIZE+1];
int pattern_area[SIZE][SIZE];

struct Point{
	int x;
	int y;
};

void search_pattern(int startx, int starty, int layer){
	pattern_area[startx][starty]=1;
	std::queue<Point> avalpoints;
	std::vector<Point> neighbors;
	Point tempp;
	tempp.x=startx-1;tempp.y=starty-1;neighbors.push_back(tempp);
	tempp.x=startx;tempp.y=starty-1;neighbors.push_back(tempp);
	tempp.x=startx+1;tempp.y=starty-1;neighbors.push_back(tempp);
	tempp.x=startx-1;tempp.y=starty;neighbors.push_back(tempp);
	tempp.x=startx+1;tempp.y=starty;neighbors.push_back(tempp);
	tempp.x=startx-1;tempp.y=starty+1;neighbors.push_back(tempp);
	tempp.x=startx;tempp.y=starty+1;neighbors.push_back(tempp);
	tempp.x=startx+1;tempp.y=starty+1;neighbors.push_back(tempp);
	for (int i=0;i<neighbors.size;++i){
		if (neighbors[i].x<0||neighbors[i].x>=SIZE||neighbors[i].y<0||neighbors[i].y>=SIZE){
			continue;
		}
		else if (pattern_area[neighbors[i].x][neighbors[i].y]==0){
			Point t;
			t.x=neighbors[i].x;t.y=neighbors[i].y;
			avalpoints.push(t);
		}
		else{
			Point vec_ori2nei;
			vec_ori2nei.x=neighbors[i].x-startx;vec_ori2nei.y=neighbors[i].y-starty;
			int tx=neighbors[i].x, ty=neighbors[i].y;
			while(tx>=0&&tx<SIZE&&ty>=0&&ty<SIZE){
				if (pattern_area[tx][ty]==0)
					break;
				tx+=vec_ori2nei.x;
				ty+=vec_ori2nei.y;
			}
			if (tx>=0&&tx<SIZE&&ty>=0&&ty<SIZE){
				Point temp;
				temp.x=tx;temp.y=ty;
				avalpoints.push(temp);
			}
		}
	}
}























