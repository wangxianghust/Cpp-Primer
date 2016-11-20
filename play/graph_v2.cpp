#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <queue>
// #include <list>
// #include <numeric>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::sort;
using std::queue;
using std::begin;
using std::end;
// using std::list;

// Initial Graph size
#define row 17
#define column 17
#define graphVertexNum 17
#define weightNum row*(row -1)/2
// #define threhold 0.5

vector< vector<int> > result;

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
template<int columnNum>
bool connectivityJudge(double A[][columnNum]) {
	queue<int> q;
	bool visit[columnNum];
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

// A is G , M is G', edge is ordered weight, d is degree, Vid is vertex id set
// template<unsigned graphVertexNum>
// vector< vector<int> > denseSubgraph(int A[][graphVertexNum], double M[][graphVertexNum], Edge edge[], double threhold, vector<int> Vid) {
void denseSubgraph(int A[][graphVertexNum], double M[][graphVertexNum], Edge edge[], double threhold, vector<int> Vid) {
	// Construct the new M
	int matrixSize = Vid.size();
	cout << "matrixSize test :  " << matrixSize << endl;
	double subM[matrixSize][matrixSize];
	sort(Vid.begin(), Vid.end());
	for (int i = 0; i < matrixSize; ++i) {
		for (int j = i + 1; j < matrixSize; ++j) {
			subM[i][j] = M[ Vid[i] ][ Vid[j] ];
			subM[j][i] = subM[i][j];
			// cout << subM[i][j] << " ";
		}
	}

	for (int i = 0; i < matrixSize; ++i){
		subM[i][i] = 1;
	}

	// cout << "///subM is ///" << endl;
	// for (auto &i : subM) {
	// 	cout << endl;
	// 	for (auto j : i) {
	// 		cout << j << " ";
	// 	}
	// }
	// cout << endl;

	// Construct the new edge array
	int subEdgeSize = matrixSize*(matrixSize -1)/2;
	Edge subEdge[subEdgeSize];
	int subEdgeIndex = 0;
	for(auto i : Vid) {
		cout << i << endl;
	}
	for(auto i = Vid.begin(); i != Vid.end(); ++i) {
		for(auto j = i+1; j != Vid.end(); ++j) {
			int iNum = *i;
			int jNum = *j;
			int indexOfEdge = graphVertexNum*iNum - iNum*(iNum+1)/2 + jNum-iNum-1;
			subEdge[subEdgeIndex] = edge[indexOfEdge];
			cout << "///Edge index test : " << "indexOfEdge " << indexOfEdge  << endl;
			cout << edge[indexOfEdge].start << " " << edge[indexOfEdge].end << " " << edge[indexOfEdge].weight << endl;
			++subEdgeIndex;
		}
	}

	sort(subEdge, subEdge + subEdgeSize, cmp);
	for(auto i : subEdge)
		cout << "/////" << "edge Set  " << i.start << "  " << i.end << "  " << i.weight << endl;

	for (int i = 0; i < subEdgeSize; ++i) {
		////////////////// This is a function to judge the connectivity : start/////////////
		bool isConnectivity;
		queue<int> q;
		bool visit[matrixSize];
		int count = 0;
		// initialization the visit array
		memset(visit, 0, sizeof(visit));

		q.push(0);

		while(!q.empty()) {
			int v = q.front();
			visit[v] = true;
			q.pop();
			++count;
			
			for(int i = 0; i < matrixSize; ++i) {
				if(subM[v][i] != 0) {
					if(!visit[i]) {
						q.push(i);
						visit[i] = true;
					}
				} 
			}	
		}

		if(count == matrixSize) {
			isConnectivity = true;
		} else {
			isConnectivity = false;
		}

		///////////////////////This is a function to judge the connectivity : end/////////////////

		if( isConnectivity ) {
			cout << "if connectivityJudge: " << isConnectivity << endl;
			/// edge start is vector location
			int startIndexOfVid = 0;
			int endIndexOfVid = 0;
			cout << "Delete edge : " << subEdge[i].start << "---" << subEdge[i].end << endl;
			for(auto m = Vid.begin(); m != Vid.end(); ++m) {
				if( *m == subEdge[i].start ) break;
				++ startIndexOfVid;
			}
			for(auto m = Vid.begin(); m != Vid.end(); ++m) {
				if( *m == subEdge[i].end ) break;
				++ endIndexOfVid;
			}
			int rowIndex = startIndexOfVid;  //As for sunGraph, the index will overflow, start==MatrixValue.id_1
			int columnIndex = endIndexOfVid;
			cout << "Delete /// row :" << rowIndex << " column : " << columnIndex << endl;
			// delete the edge i<-->j
			subM[rowIndex][columnIndex] = 0;
			subM[columnIndex][rowIndex] = 0;
			cout << "After fix the matrix " << endl;
			for (int i = 0; i < matrixSize; ++i) {
				for (int j = 0; j < matrixSize; ++j) {
					cout << subM[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		} else {
			cout << "else connectivityJudge: " << isConnectivity << endl;
			for (int i = 0; i < matrixSize; ++i) {
				cout << endl;
				for (int j = 0; j < matrixSize; ++j) {
					cout << subM[i][j] << " ";
				}
			}
			cout << endl;
			cout << "we get seperate graph " << endl;
			break;
		}
	}

	////  Find two seperate part , Use BFS  ///////
	queue<int> q;
	bool visit[matrixSize];
	memset(visit, 0, sizeof(visit));

	/// choose any id from id set
	// int id_0 = *(Vid.begin());
	// q.push(id_0);
	// visit[id_0] = true;
	q.push(0);
	visit[0] = true;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int i = 0; i < matrixSize; ++i) {
			if(subM[v][i] != 0) {
				if(!visit[i]) {
					q.push(i);
					visit[i] = true;
				}
			} 
		}	

		// for(auto id = Vid.begin(); id != Vid.end(); ++id) {
		// 	if(subM[v][*id] != 0) {
		// 		if(!visit[*id]) {
		// 			q.push(*id);
		// 			visit[*id] = true;
		// 		}
		// 	}
		// }

	}



	/// get one subGraph  ///
	vector<int> vertex;
	for (int i = 0; i < matrixSize; ++i) {
		if(visit[i] == true) {
			vertex.push_back( Vid[i] );
		}
	}

	// vector<int> vertex;
	// for(auto id = Vid.begin(); id != Vid.end(); ++id) {
	// 	if(visit[*id] == true) {
	// 		vertex.push_back(*id);
	// 	}
	// }

	for(auto i : vertex)
		cout << i << " ";
	cout << endl;

	int subEdgeNum = 0;
	for(auto i = vertex.begin(); i != vertex.end(); ++i) {
		for(auto j = i+1; j != vertex.end(); ++j) {
			if(A[*i][*j]) {
				cout << "edge is : " << *i << "--->" << *j << endl;
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
		result.push_back(vertex);
		// return result;
	} else {
		if(vertex.size() > 1) {
			denseSubgraph(A, M, edge, threhold, vertex);
		} 
		else if(vertex.size() == 1) {
			cout << "print a vertex" << endl;
			result.push_back(vertex);
		}
	}

	/// get another one subGraph  //////////////////////
	vector<int> vertexAnother;
	for (int i = 0; i < matrixSize; ++i) {
		if(visit[i] == false) {
			vertexAnother.push_back( Vid[i] );
		}
	}
	cout << "/////////////////////////////////////////////another test";
	for(auto i : vertexAnother)
		cout << i << " ";
	cout << endl;

	int subEdgeNumAnother = 0;
	for(auto i = vertexAnother.begin(); i != vertexAnother.end(); ++i) {
		for(auto j = i+1; j != vertexAnother.end(); ++j) {
			if(A[*i][*j]) {
				cout << "edge is : " << *i << "--->" << *j << endl;
				++ subEdgeNumAnother;
			}
		}
	}
	cout << "subEdgeNum is " << subEdgeNumAnother << endl;
	int subVertexNumAnother = vertexAnother.size();
	double densityAnother = 0;
	densityAnother = 2.0*subEdgeNumAnother/( subVertexNumAnother*(subVertexNumAnother-1) );
	if(densityAnother >= threhold) {
		cout << "densityAnother is " << densityAnother << " fix our hope." << endl;
		// int subGraphA[subVertexNum][subVertexNum] = {0};
		result.push_back(vertexAnother);
		// return result;
	} else {
		if(vertexAnother.size() > 1) {
			denseSubgraph(A, M, edge, threhold, vertexAnother);
		} 
		else if(vertexAnother.size() == 1) {
			cout << "Another print a vertex" << endl;
			result.push_back(vertexAnother);
			// return result;
		}
	}

	/////////////////////////////////////////////////////////////////////////////////////////////
	

}




int main() {
	// const int weightNum = row*(row -1)/2;
	Edge edge[weightNum];

	// int B[row][column] = { 
	// 	{0,1,1,0,0,0}, 
	// 	{1,0,0,1,0,0}, 
	// 	{1,0,0,1,0,0}, 
	// 	{0,1,1,0,1,0}, 
	// 	{0,0,0,1,0,1}, 
	// 	{0,0,0,0,1,0} 
	// };

	// int C[row][column] = { 
	// 	{0,1,1,1,0,0}, 
	// 	{1,0,0,1,0,0}, 
	// 	{1,0,0,1,0,1}, 
	// 	{1,1,1,0,1,0}, 
	// 	{0,0,0,1,0,1}, 
	// 	{0,0,1,0,1,0} 
	// };

	int A[row][column] = { 
{0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0},
{1,0,0,0,1,0,1,1,1,1,0,0,0,0,0,0,0},
{1,0,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0},
{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
{1,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0},
{1,1,1,0,1,1,0,1,0,1,0,1,1,0,0,0,0},
{1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0},
{1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0},
{1,1,0,0,1,0,1,0,0,0,0,1,0,0,1,1,0},
{0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0},
{0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,1,0},
{0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},

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

	cout << "M is " << endl;
	for (auto &i : M) {
		cout << endl;
		for (auto j : i) {
			cout << j << " ";
		}
	}
	cout << endl;

	// sort(edge, edge + weightNum, cmp);

	// for (auto i : edge) {
	// 	cout << i.start << " " << i.end << " " << i.weight << endl;
	// }

	// cout << "connection test : " << connectivityJudge(A) << endl;

	///// Delete the edge /////
	vector<int> Vid;
	for(int i = 0; i < graphVertexNum; ++i) {
		Vid.push_back(i);
	}
	double threhold = 0.3;
	denseSubgraph(A, M, edge, threhold, Vid);
	cout << "The density graph is : " << endl;
	for(auto i = result.begin(); i != result.end(); ++i) {
		for(auto j = (*i).begin(); j != (*i).end(); ++j) {
			cout << *j << " ";
		}
		cout << endl;
	}
}