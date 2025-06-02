#include "Models/Rubikscube1D.cpp"
#include "Solvers/IDDFS_solver.cpp"
#include "Solvers/DFS_solver.cpp"
#include "Solvers/BFS_solver.cpp"
#include "Solvers/IDAStar_Solver.cpp"


// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
   RubiksCube1d Cube;
   vector<RubiksCube::MOVE> v=Cube.randomShuffleCube(6);
    Cube.print();
    for (int i=0; i<v.size(); i++)
    cout<<RubiksCube::getMove(v[i])<<" ";
    cout<<endl;

    IDDFS_solver<RubiksCube1d,Hash1d> d1(Cube,6);
    auto start = chrono::high_resolution_clock::now();
    vector<RubiksCube::MOVE> v1=d1.solve();
    auto end = chrono::high_resolution_clock::now();
    auto duration = duration_cast<chrono::milliseconds>(end - start);
    cout<<"Execution time: "<<duration.count()<<endl;
    for (int i=0; i<v1.size(); i++) {
        cout<<RubiksCube::getMove(v1[i])<<" ";
    }
    cout<<endl;




    return 0;// TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}