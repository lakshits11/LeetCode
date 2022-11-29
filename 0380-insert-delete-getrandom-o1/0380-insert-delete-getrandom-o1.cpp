class RandomizedSet
{
public:
    unordered_set<int> ss;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (ss.find(val) != ss.end())
        {
            return false;
        }

        ss.insert(val);
        return true;
    }

    bool remove(int val)
    {
        if (ss.find(val) == ss.end())
        {
            return false;
        }
        unordered_set<int>::iterator it = ss.find(val);
        ss.erase(it);
        return true;
    }

    int getRandom()
    {
        unordered_set<int>::iterator it = ss.begin();
        std::advance(it, rand()%ss.size());
        int x = *it;
        return x;
    }
};