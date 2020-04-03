class MyHashSet
{
    long arr[16000], base;

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        for (int i = 0; i < 16000; i++)
            arr[i] = 0;
        base = sizeof(long);
    }

    void add(int key)
    {
        int index = key / base, rem = key % base;
        arr[index] = arr[index] | (1 << rem);
    }

    void remove(int key)
    {
        int index = key / base, rem = key % base;
        arr[index] = arr[index] & (0xFFFFFFFF ^ (1 << rem));
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int index = key / base, rem = key % base;
        if (0 ^ (arr[index] & (1 << rem)))
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
