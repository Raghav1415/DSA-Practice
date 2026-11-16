char* digitSum(char* s, int k) {
    int n = strlen(s);

    while (n > k) {
        char* next = (char*)malloc((n * 2 + 1) * sizeof(char));
        int pos = 0;

        for (int i = 0; i < n; i += k) {
            int sum = 0;

            for (int j = i; j < i + k && j < n; j++) {
                sum += s[j] - '0';
            }

            pos += sprintf(next + pos, "%d", sum);
        }

        next[pos] = '\0';
        s = next;
        n = pos;
    }

    return s;
}