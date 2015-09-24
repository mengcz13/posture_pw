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

void search_pattern(int orix, int oriy, int startx, int starty, int layer){
	pattern_type[orix][oriy][layer]+=1;
	pattern_area[startx][starty]=1;
	std::queue<Point> avalpoints;
	for (int i=0;i<SIZE;++i)
		for (int j=0;j<SIZE;++j){
			if (startx==i&&starty==j||pattern_area[i][j]==1)
				continue;
			else{
				bool flag=true;
				for (int ii=0;ii<SIZE;++ii)
					for (int jj=0;jj<SIZE;++jj){
						if (pattern_area[ii][jj]==0){
							if (!(ii==i&&jj==j)&&(ii-startx)*(ii-i)<=0&&(jj-starty)*(jj-j)<=0&&(ii-startx)*(jj-j)==(jj-starty)*(ii-i))
								flag=false;
						}
					}
				if (flag){
					Point temp;
					temp.x=i;temp.y=j;
					avalpoints.push(temp);
				}
			}
		}
	while (!avalpoints.empty()){
		int nx=avalpoints.front().x;
		int ny=avalpoints.front().y;
		pattern_area[nx][ny]=1;
		search_pattern(orix,oriy,nx,ny,layer+1);
//		pattern_area[nx][ny]=0;
		avalpoints.pop();
	}
	pattern_area[startx][starty]=0;
	return;
}

int main(){
	for (int i=0;i<SIZE;++i)
		for (int j=0;j<SIZE;++j){
			pattern_area[i][j]=0;
			for (int k=0;k<SIZE*SIZE+1;++k)
				pattern_type[i][j][k]=0;
		}
	for (int i=0;i<SIZE;++i)
		for (int j=0;j<SIZE;++j)
			search_pattern(i,j,i,j,1);
	for (int i=0;i<SIZE;++i)
		for (int j=0;j<SIZE;++j){
			printf("point(%d,%d)\n",i,j);
			for (int k=1;k<SIZE*SIZE+1;++k)
				printf("layer:%d	%d\n",k,pattern_type[i][j][k]);
		}
	return 0;
}

