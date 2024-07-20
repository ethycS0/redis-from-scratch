// Theory
    // 2 Ways to store Key-Value pairs in servers
    //     1. Sorting Data Structures O(log(n)) [Used for realtional databases]
    //     2. Hashing Data Structures  O(1) [Used in top-level databases]

    // Hashtables: Keys are hashed into integer hash values and sloted as hash(key) % size.
    //     Benefits: 
    //         1. Turn non-integer keys to slot indexes
    //         2. Ensure slot indexes are uniformely distributed
    //     What if 2 keys have same hashes:
    //         1. Open addressing: Find another slot if it’s already occupied. [Linear, Quadratic Probing] [Double Hashing]
    //         2. Chaining: Each slot points to a collection of colliding keys. [Linked Lists] [ad hoc chaining
    //                                                                                             std::vector<std::vector<T>> m;
    //                                                                                             m.resize(1024);
    //                                                                                             m[hash(key) % m.size()].push_back(pair); ]
            // Hashtables can be resized similiar to dynamic arrays like std::vector
            // Load Factor = Keys/Slots
            //     1. Open Adressing: below 1, detoriates near limit
            //     2. Chaining: No hard limit, Linear search length with load factor
            // Lazy Deletion with Open Addressing

