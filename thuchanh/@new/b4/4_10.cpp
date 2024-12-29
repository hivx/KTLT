#include <bits/stdc++.h>
using namespace std;

typedef unordered_map<string, int> HashMap;
const int MAX_N = 1000;
const double EPS = 1e-9;

int N, Q;
vector<vector<string>> documents, queries;
unordered_map<string, double> idf; // Thay đổi idf từ vector sang HashMap
HashMap df; // Số lượng văn bản chứa từ t

// Hàm tách chuỗi theo dấu phẩy
vector<string> split(const string &s) {
    vector<string> result;
    stringstream ss(s);
    string word;
    while (getline(ss, word, ',')) {
        result.push_back(word);
    }
    return result;
}

// Tiền xử lý IDF
void preprocess_idf() {
    for (int i = 0; i < N; i++) {
        unordered_set<string> unique_words;
        for (const string &word : documents[i]) {
            unique_words.insert(word);
        }
        for (const string &word : unique_words) {
            df[word]++;
        }
    }

    for (const auto &entry : df) {
        string word = entry.first;
        int doc_count = entry.second;
        idf[word] = log2((double)N / doc_count);
    }
}

// Tính TF-IDF điểm của một văn bản d với truy vấn query
double compute_score(const vector<string> &doc, const vector<string> &query) {
    HashMap freq;
    int max_freq = 0;

    // Tính f(t, d) và maxf(d)
    for (const string &word : doc) {
        freq[word]++;
        max_freq = max(max_freq, freq[word]);
    }

    double score = 0.0;
    for (const string &q_word : query) {
        if (freq.find(q_word) != freq.end()) {
            double tf = 0.5 + 0.5 * (double)freq[q_word] / max_freq;
            score += tf * idf[q_word];
        }
    }

    return score;
}

int main() {
    // Đọc số lượng văn bản
    cin >> N;
    documents.resize(N);
    cin.ignore();

    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        documents[i] = split(line);
    }

    // Đọc số lượng truy vấn
    cin >> Q;
    queries.resize(Q);
    cin.ignore();

    for (int i = 0; i < Q; i++) {
        string line;
        getline(cin, line);
        queries[i] = split(line);
    }

    // Tiền xử lý IDF
    preprocess_idf();

    // Xử lý từng truy vấn
    for (int q = 0; q < Q; q++) {
        int best_doc = -1;
        double best_score = -1e9;

        for (int d = 0; d < N; d++) {
            double score = compute_score(documents[d], queries[q]);
            if (score > best_score || (fabs(score - best_score) < EPS && d < best_doc)) {
                best_score = score;
                best_doc = d;
            }
        }

        cout << best_doc + 1 << "\n"; // In chỉ số (1-based index)
    }

    return 0;
}
