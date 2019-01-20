#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

template <class T>
class KeyValue {
    public:
        string key;
        T value;

        KeyValue(string _key, T _value){
            key = _key;
            value = _value;
        }
};

template <class T>
class HashTable {
    private:
        int size;
        vector<vector<KeyValue<T>>> buckets;

        int getHashIndex(string key){
            hash<string> hasher;
            unsigned long long hashInt = hasher(key);
            return hashInt % size;
        }

    public:
        HashTable(){
            size = 32;
            buckets.resize(size);
        }

        void set(string key, T value){
            int index = getHashIndex(key);

            vector<KeyValue<T>> keyValues = buckets.at(index);

            bool found = false;
            int index_secondary = 0;

            for(auto keyValue : keyValues){
                if (keyValue.key == key){
                    found = true;
                    break;
                }
                index_secondary++;
            }

            if (found){
                buckets.at(index).at(index_secondary) = KeyValue<T>(key, value);
            } else {
                buckets.at(index).push_back(KeyValue<T>(key, value));
            }
        }

        T get(string key){
            int index = getHashIndex(key);

            try {
                vector<KeyValue<T>> keyValues = buckets.at(index);

                if (buckets.size() == 0) throw "Element was not found.";

                T value;

                bool found = false;

                for(auto keyValue : keyValues){
                    if (keyValue.key == key){
                        value = keyValue.value;
                        found = true;
                        break;
                    }
                }

                if (found){
                    return value;
                } else {
                    throw "Element was not found.";
                }
            } catch(const char *string){
                throw;
            }
        }

        void unset(string key){
            int index = getHashIndex(key);

            vector<KeyValue<T>> keyValues = buckets.at(index);

            int index_secondary = 0;

            for(auto keyValue : keyValues){
                if (keyValue.key == key){
                    buckets.at(index).erase(buckets.at(index).begin() + index_secondary);
                    break;
                }
                index_secondary++;
            }
        }

        void keyValues(){
            cout << "Printing all key values:" << endl;
            for (auto bucket : buckets){
                if (bucket.size() > 0){
                    for (auto keyValue : bucket){
                        cout << keyValue.key << ": " << keyValue.value << endl;
                    }
                }
            }
        }
};