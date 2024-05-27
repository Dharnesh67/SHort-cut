void generate_permutations(string prefix, string remaining) {
    if (remaining.empty()) {
        cout << prefix << endl;
        return;
    }

    for (int i = 0; i < remaining.length(); ++i) {
        generate_permutations(prefix + remaining[i], remaining.substr(0, i) + remaining.substr(i + 1));
    }
}
