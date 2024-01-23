#include "ofApp.h"
#include <vector>
#include <algorithm>
#include <random>
#include <filesystem>

double width = 50;
double margin = 10;
int num_x;
int num_y;


enum Side {UP, DOWN, LEFT, RIGHT};
struct Node {
    int i,j;
    
    std::vector<int> adj;
    std::vector<int> walls;
    
    Node(int ii, int jj) {
        i = ii;
        j = jj;
        
        walls.resize(4);
        for (auto &w : walls) w=1;
    }
    
    void draw() {
        double x1 = margin+i*width;
        double y1 = margin+j*width;
        double x2 = x1+width;
        double y2 = y1+width;
        ofSetColor(ofColor::white);
        if (walls[UP]) ofDrawLine(x1,y1,x2,y1);
        if (walls[DOWN]) ofDrawLine(x1,y2,x2,y2);
        if (walls[LEFT]) ofDrawLine(x1,y1,x1,y2);
        if (walls[RIGHT]) ofDrawLine(x2,y1,x2,y2);
    }
    
    void drawFilled() {
        double x1 = margin+i*width;
        double y1 = margin+j*width;
        ofSetColor(ofColor::red);
        int m = width/3;
        ofDrawRectangle(x1+m, y1+m, width-2*m, width-2*m);
    }
};

std::vector<Node> graph;
std::vector<int> visited;

void remove_wall(int index1, int index2)
{
    auto &n1 = graph[index1];
    auto &n2 = graph[index2];
    
    if (n1.i==n2.i && n1.j==n2.j-1) {
        n1.walls[DOWN]=0;
        n2.walls[UP]=0;
    } else if (n1.i==n2.i && n1.j==n2.j+1) {
        n1.walls[UP]=0;
        n2.walls[DOWN]=0;
    } else if(n1.i-1==n2.i && n1.j==n2.j) {
        n1.walls[LEFT]=0;
        n2.walls[RIGHT]=0;
    } else if (n1.i+1==n2.i && n1.j==n2.j) {
        n1.walls[RIGHT]=0;
        n2.walls[LEFT]=0;
    } else {
        std::cout << "error: these nodes are not adjucent nodes." << std::endl;
    }
}

bool check_connected(int index1, int index2){
    auto &n1 = graph[index1];
    auto &n2 = graph[index2];
    
    if (n1.i==n2.i && n1.j==n2.j-1) {
        return n1.walls[DOWN]==0;
    } else if (n1.i==n2.i && n1.j==n2.j+1) {
        return n1.walls[UP]==0;
    } else if(n1.i-1==n2.i && n1.j==n2.j) {
        return n1.walls[LEFT]==0;
    } else if (n1.i+1==n2.i && n1.j==n2.j) {
        return n1.walls[RIGHT]==0;
    }
    return false;
}

std::random_device rd;
std::mt19937 g(rd());

void DFS(int index)
{
    // Write you DFS code here
}

std::vector<int> solution;
bool DFS_solver(int index, int destination)
{
    // Write you DFS solver here
    
    return false;
}

void solve()
{
    visited.clear();
    visited.resize(graph.size());
    solution.clear();
    DFS_solver(0, num_x*num_y-1);
}

//--------------------------------------------------------------
void ofApp::setup(){
    num_x = (ofGetWidth()-2*margin)/width;
    num_y = (ofGetHeight()-2*margin)/width;
    graph.clear();
    for (int i=0;i<num_x;i++) {
        for (int j=0;j<num_y;j++) {
            graph.emplace_back(i,j);
            if (i>0) graph.back().adj.push_back((i-1)*num_y+j);
            if (j>0) graph.back().adj.push_back(i*num_y+j-1);
            if (i<num_x-1) graph.back().adj.push_back((i+1)*num_y+j);
            if (j<num_y-1) graph.back().adj.push_back(i*num_y+j+1);
        }
    }
    visited.clear();
    visited.resize(graph.size());
}

int show_solution = 0;
//--------------------------------------------------------------
void ofApp::update(){
    DFS(0);
    solve();
    //current_index = DFS2(current_index);
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (auto &n : graph) n.draw();
    if (show_solution) for (auto i : solution) graph[i].drawFilled();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key=='s') show_solution=1-show_solution;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    setup();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
