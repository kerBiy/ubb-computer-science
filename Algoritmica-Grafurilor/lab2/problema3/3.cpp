#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> matrice;
const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};

void lee(size_t start_x, size_t start_y) {
    queue<pair<size_t, size_t>> coada;
    coada.push(make_pair(start_x, start_y));
    matrice[start_x][start_y] = 2;

    while (!coada.empty()) {
        size_t i = coada.front().first, j = coada.front().second;
        coada.pop();
        for (int k = 0; k < 4; k++) {
            size_t vecin_i = i + di[k], vecin_j = j + dj[k];

            if (vecin_i < matrice.size() && vecin_j < matrice[i].size() &&
                matrice[vecin_i][vecin_j] == 0) {
                matrice[vecin_i][vecin_j] = matrice[i][j] + 1;
                coada.push(make_pair(vecin_i, vecin_j));
            }
        }
    }
}
vector<pair<size_t, size_t>> traseu(size_t final_x, size_t final_y) {
    vector<pair<size_t, size_t>> trasee;
    size_t i = final_x, j = final_y;

    while (matrice[i][j] != 2) {
        trasee.push_back(make_pair(i, j));

        for (int k = 0; k < 4; k++) {
            size_t vecin_i = i + di[k], vecin_j = j + dj[k];

            if (vecin_i < matrice.size() && vecin_j < matrice[i].size() &&
                matrice[vecin_i][vecin_j] == matrice[i][j] - 1) {
                i = vecin_i;
                j = vecin_j;
                break;
            }
        }
    }
    trasee.push_back(make_pair(i, j));
    reverse(trasee.begin(), trasee.end());

    return trasee;
}
int main() {
    ifstream in("labirint_1.txt");
    string line;
    size_t sx = 0, sy = 0, fx = 0, fy = 0;
    vector<vector<int>> copie;
    if (in.is_open()) {
        size_t i = 0;
        while (getline(in, line)) {
            vector<int> row;
            for (size_t j = 0; j < line.length(); ++j) {
                char ch = line[j];
                if (ch == ' ') {
                    row.push_back(0);
                } else if (ch == '1') {
                    row.push_back(1);
                } else if (ch == 'S') {
                    sx = i;
                    sy = j;
                    row.push_back(0);
                } else if (ch == 'F') {
                    fx = i;
                    fy = j;
                    row.push_back(0);
                }
            }
            matrice.push_back(row);
            copie.push_back(row);
            ++i;
        }
        in.close();
    } else {
        cout << "Nu s-a putut deschide fisierul." << endl;
        return 1;
    }

    lee(sx, sy);
    vector<pair<size_t, size_t>> trs;
    trs = traseu(fx, fy);

    for (size_t i = 0; i < copie.size(); i++) {
        for (size_t j = 0; j < copie[i].size(); j++) {
            if (find(trs.begin(), trs.end(), make_pair(i, j)) != trs.end()) {
                cout << "*";
            } else {
                cout << (copie[i][j] == 1 ? '1' : ' ');
            }
        }
        cout << endl;
    }

    return 0;
}