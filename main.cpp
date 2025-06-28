// #include "Models/Rubikscube1D.cpp"
// #include "Models/RubiksCubeBitboard.cpp"
#include "Solvers/IDDFS_solver.cpp"
#include "Solvers/DFS_solver.cpp"
#include "Solvers/BFS_solver.cpp"
// #include "Solvers/IDAStar_Solver.cpp"
#include "Solvers/IDAStar_Edge_Solver.cpp"

// #include "Pattern_DB/Permut_indexer.h"
// #include "Pattern_DB/Corner_Pattern_DB.h"
// #include "Pattern_DB/Corner_DB_Maker.h"
#include "Pattern_DB/Edge_DB_Maker.h"
#include "Pattern_DB/Edge_pattern_DB.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
   // RubiksCube1d Cube;
   // vector<RubiksCube::MOVE> v=Cube.randomShuffleCube(6);
   //  Cube.print();
   //  for (int i=0; i<v.size(); i++)
   //  cout<<RubiksCube::getMove(v[i])<<" ";
   //  cout<<endl;
    //
    // IDDFS_solver<RubiksCube1d,Hash1d> d1(Cube,6);
    // auto start = chrono::high_resolution_clock::now();
    // vector<RubiksCube::MOVE> v1=d1.solve();
    // auto end = chrono::high_resolution_clock::now();
    // auto duration = duration_cast<chrono::milliseconds>(end - start);
    // cout<<"Execution time: "<<duration.count()<<endl;
    // for (int i=0; i<v1.size(); i++) {
    //     cout<<RubiksCube::getMove(v1[i])<<" ";
    // }
    // cout<<endl;


    // string fileName = "/Users/manishtripathy/CLionProjects/RubikscubesolverV1/Databases/cornerDBnibble.txt";
    // long double x=0;
    // for (int i=0;i<5;i++) {
    //     RubiksCubeBitboard cube;
    //     auto shuffleMoves = cube.randomShuffleCube(13);
    //     IDAstarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
    //     auto start = chrono::high_resolution_clock::now();
    //     auto moves = idaStarSolver.solve();
    //     auto end = chrono::high_resolution_clock::now();
    //     auto duration = duration_cast<chrono::milliseconds>(end - start);
    //     x=x+duration.count();
    //     cout<<"i "<<i<<endl;
    // }
    // cout<<std::fixed<<std::setprecision(10)<<x/5000<<endl;



    // string fileName = "/Users/manishtripathy/CLionProjects/RubikscubesolverV1/Databases/cornerDBnibble.txt";
    // CornerDBMaker dbMaker(fileName, 0x77);
    // dbMaker.bfsAndStore();
    //
    // ofstream test("/Users/manishtripathy/CLionProjects/RubikscubesolverV1/Databases/test.txt");
    // if (!test) {
    //     cerr << "Directory path does not exist or is invalid!" << endl;
    // }
   //  long double x=0;
   // for (int i=0;i<5;i++) {
   //     RubiksCube1d cube;
   //     auto shuffleMoves = cube.randomShuffleCube(11);
   //     // cube.print();
   //     // for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
   //     // cout << "\n";
   //     // //
   //     IDAstarSolver<RubiksCube1d, Hash1d> idaStarSolver(cube, fileName);
   //     auto start = chrono::high_resolution_clock::now();
   //     auto moves = idaStarSolver.solve();
   //     auto end = chrono::high_resolution_clock::now();
   //     auto duration = duration_cast<chrono::milliseconds>(end - start);
   //     x=x+duration.count();
   //     cout<<"i "<<i<<endl;
   //     // idaStarSolver.rubiksCube.print();
   //     // for (auto move: moves) cout << cube.getMove(move) << " ";
   //     // cout << "\n";
   // }
   //  cout<<std::fixed<<std::setprecision(10)<<x/5000<<endl;

    //  array<uint8_t,7> arr={11,10,9,8,7,6,5};
    // PermutationIndexer<12,7> permIndexer;
    // uint32_t rank = permIndexer.rank(arr);
    // cout << ((rank+1)*128) << endl;

// for (int i=0;i<100001;i++) {
//     RubiksCubeBitboard Cube;
//     vector<RubiksCube::MOVE> v=Cube.randomShuffleCube(2);
//     // for (int i=0;i<12;i++) {
//     //     cout<<"i :"<<i<<endl;
//     //     string s=Cube.getEdgeColorString(i);
//     //     cout<<"s :"<<s<<endl;
//     //  cout<<Cube.getEdgeIndex(i)<<endl;
//     // }
//     array<uint8_t, 7> edgePerm;
//     PermutationIndexer<12,7> permIndexer;
//     for (int i=0;i<12;i++) {
//         int x=Cube.getEdgeIndex(i);
//         if (x!=8) {
//             assert(x>=0 && x<=6);
//             edgePerm[x]=i;
//         }
//     }
//     for (int j=0;j<7;j++) {
//         if (!(edgePerm[j]>=0 && edgePerm[j]<=11)) {
//             for (int k=0; k<v.size(); k++)
//                 cout<<RubiksCube::getMove(v[k])<<" ";
//                     cout<<endl;
//             throw std::runtime_error("Invalid edge index");
//         }
//     }
//     // uint32_t rank = permIndexer.rank(edgePerm);
//     // cout<<rank<<endl;
// }


    // string fileName = "/Users/manishtripathy/CLionProjects/RubikscubesolverV1/Databases/edgeDBnibble.txt";
    // ofstream test("/Users/manishtripathy/CLionProjects/RubikscubesolverV1/Databases/test.txt");
    // if (!test) {
    // cerr << "Directory path does not exist or is invalid!" << endl;
    // }
    // Edge_DB_Maker dbMaker(fileName, 0x77);
    // dbMaker.bfsAndStore();
    // RubiksCube1d cube;
    // cube.b();
    // cube.r();
    // cube.print();

    // RubiksCube1d cube;
    // auto shuffleMoves = cube.randomShuffleCube(10);
    // cube.print();
    // for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    //
    // IDAStar_EdgeSolver<RubiksCube1d, Hash1d> idaStarEdge(cube, fileName);
    // auto moves = idaStarEdge.solve();
    //
    // idaStarEdge.rubiksCube.print();
    // for (auto move: moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    string fileName = "/Users/manishtripathy/CLionProjects/RubikscubesolverV1/Databases/edgeDBnibble.txt";
    long double x=0;
    for (int i=0;i<5;i++) {
        RubiksCube1d cube;
        auto shuffleMoves = cube.randomShuffleCube(11);
        IDAStar_EdgeSolver<RubiksCube1d, Hash1d> idaStarSolver(cube, fileName);
        auto start = chrono::high_resolution_clock::now();
        auto moves = idaStarSolver.solve();
        auto end = chrono::high_resolution_clock::now();
        auto duration = duration_cast<chrono::milliseconds>(end - start);
        x=x+duration.count();
        cout<<"i "<<i<<endl;
    }
    cout<<std::fixed<<std::setprecision(10)<<x/5000<<endl;


    return 0;// TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}