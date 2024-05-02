 void nexts(vector<int> &h, vector<int> &ns)
    {
        stack<int> s;
        ns[h.size() - 1] =h.size();
        s.push(h.size() - 1);
        for (int i = h.size() - 2; i >= 0; i--)
        {
            while (!s.empty() && h[s.top()] >= h[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                ns[i] = h.size();
            }
            else
            {
                ns[i] = s.top();
            }
            s.push(i);
        }
    }
    void pres(vector<int> &h, vector<int> &ps)
    {
        stack<int> s;
        ps[0] = -1;
        s.push(0);
        for (int i = 1; i < h.size(); i++)
        {
            while (!s.empty() && h[s.top()] > h[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                ps[i] = -1;
            }
            else
            {
                ps[i] = s.top();
            }
            s.push(i);
        }
    }
