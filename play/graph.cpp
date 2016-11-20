#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <queue>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::sort;
using std::queue;
using std::begin;
using std::end;

#define row 6
#define column 6
#define weightNum row*(row -1)/2

struct Edge
{
	int start;
	int end;
	double weight;
};

// struct compare function for sort
bool cmp(Edge e1, Edge e2) {
	return e1.weight < e2.weight;
}

// connection judge, using BFS
bool connectivityJudge(double A[][column]) {
	queue<int> q;
	bool visit[row];
	int count = 0;
	// initialization the visit array
	memset(visit, 0, sizeof(visit));

	q.push(0);

	while(!q.empty()) {
		int v = q.front();
		visit[v] = true;
		q.pop();
		++count;
		
		for(int i = 0; i < column; ++i) {
			if(A[v][i] != 0) {
				if(!visit[i]) {
					q.push(i);
					visit[i] = true;
				}
			} 
		}	
	}

	if(count == column) {
		return true;
	} else {
		return false;
	}

}

// A is G , M is G', edge is ordered weight, d is degree
void denseSubgraph(int A[][column], double M[][column], Edge edge[], double threhold) {
	for (int i = 0; i < weightNum; ++i) {
		if(connectivityJudge(M) ) {
			int rowIndex = edge[i].start;
			int columnIndex = edge[i].end;
			// delete the edge i<-->j
			M[rowIndex][columnIndex] = 0;
			M[columnIndex][rowIndex] = 0;
			cout << " weightNum : " << i << endl;
		} else {
			for (int i = 0; i < row; ++i) {
				cout << endl;
				for (int j = 0; j < column; ++j) {
					cout << M[i][j] << " ";
				}
			}
			cout << endl;
			cout << "we get seperate graph " << endl;
			break;
		}
	}

	////  Find two seperate part ///////
	queue<int> q;
	bool visit[row];
	int count = 0;
	memset(visit, 0, sizeof(visit));

	q.push(0);
	visit[0] = true;
	while(!q.empty()) {
		int v = q.front();
		
		q.pop();
		++count;
		
		for(int i = 0; i < column; ++i) {
			if(M[v][i] != 0) {
				if(!visit[i]) {
					q.push(i);
					visit[i] = true;
				}
			} 
		}	
	}



	///  get one subGraph  ///
	vector<int> vertex;
	for (int i = 0; i < row; ++i) {
		if(visit[i] == true) {
			vertex.push_back(i);
		}
	}
	for(auto i : vertex)
		cout << i << " ";
	cout << endl;

	int subEdgeNum = 0;
	for(auto i = vertex.begin(); i != vertex.end(); ++i) {
		for(auto j = i+1; j != vertex.end(); ++j) {
			if(A[*i][*j]) {
				++ subEdgeNum;
			}
		}
	}
	cout << "subEdgeNum is " << subEdgeNum << endl;
	int subVertexNum = vertex.size();
	double density = 0;
	density = 2.0*subEdgeNum/( subVertexNum*(subVertexNum-1) );
	if(density >= threhold) {
		cout << "density is " << density << " fix our hope." << endl;
		// int subGraphA[subVertexNum][subVertexNum] = {0};
		
	}

}




int main() {
	// const int weightNum = row*(row -1)/2;
	Edge edge[weightNum];

	int A[row][column] = { 
		{1,1,1,0,0,0}, 
		{1,1,0,1,0,0}, 
		{1,0,1,1,0,0}, 
		{0,1,1,1,1,0}, 
		{0,0,0,1,1,1}, 
		{0,0,0,0,1,1} 
	};

	double M[row][column] = {0};
	for (int i = 0; i < row; ++i) {
		for (int j = i + 1; j < column; ++j) {
			// now calculate M[i][j]
			double sum = 0;
			double column_left = 0;
			double column_right = 0;
			for (int k = 0; k < row; ++k) {
				sum += A[k][i]*A[k][j];
				column_left += pow(A[k][i], 2);
				column_right += pow(A[k][j], 2);
			}
			M[i][j] = sum/( sqrt(column_left) * (sqrt(column_right)) );
			M[j][i] = M[i][j];
		}
	}

	int num = 0;
	for (int i = 0; i < row; ++i) {
		for (int j = i + 1; j < column; ++j) {
			edge[num].start = i;
			edge[num].end = j;
			edge[num].weight = M[i][j];
			++ num;
		}
	}

	for (auto &i : M) {
		cout << endl;
		for (auto j : i) {
			cout << j << " ";
		}
	}
	cout << endl;

	sort(edge, edge + weightNum, cmp);

	for (auto i : edge) {
		cout << i.start << " " << i.end << " " << i.weight << endl;
	}

	// cout << "connection test : " << connectivityJudge(A) << endl;

	///// Delete the edge /////
	denseSubgraph(A, M, edge, 0.5);
}