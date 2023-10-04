
class MyHashMap
{
public:
    int v[1000000 + 1];
    MyHashMap()
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        memset(v, -1, sizeof(v));
    }

    void put(int key, int value)
    {
        v[key] = value;
    }

    int get(int key)
    {
        return v[key];
    }

    void remove(int key)
    {
        v[key] = -1;
    }
};
