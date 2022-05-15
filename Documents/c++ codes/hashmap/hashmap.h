#include<string>
using namespace std;

template<typename V>
class mapNode{
    public:
        string key;
        V value;
        mapNode<V>* next;

        mapNode(string key, V value){
            this->key = key;
            this->value = value;
            next = NULL;
        }

        ~mapNode(){
            delete next;
        }
};

template<typename V>
class Bucket{
    public:  
        mapNode<V>** bucketArray;
        int count;
        int bucketSize;

        Bucket(){
            count = 0;
            bucketSize = 5;
            bucketArray = new mapNode<V>*[bucketSize];
            for(int i=0; i<bucketSize; i++){
                bucketArray[i] = NULL;
            }
        }       
        
        int size(){
            return count;
        }

        V getValue(string key){
            int bucketIndex = getBucketIndex(key);
            mapNode<V>* head = bucketArray[bucketIndex];

            while(head != NULL){
                if(head->key == key){
                    return head->value;
                }
                head = head->next;
            }

            return 0;
        }

        private:
            int getBucketIndex(string key){
                int hashcode, coeff = 1;
                for(int i=key.length()-1; i>=0; i--){
                    hashcode += (key[i] - '0') * coeff;
                    coeff *= 41;  // we use prime no. in hashing generally "abc" = 'a'*p^2 + 'b'*p^1 + 'c'*p^0 , p based. 
                    coeff = coeff % bucketSize;  // to keep coeff in range of integers as without it 
                    hashcode = hashcode % bucketSize; //there is high chances of overflow
                }
                return hashcode % bucketSize;
            }

            void rehash(){
                mapNode<V>** temp = bucketArray;
                bucketArray = new mapNode<V>*[2*bucketSize];
                int oldSize = bucketSize;
                bucketSize *= 2;
                for(int i=0; i<bucketSize; i++){
                    bucketArray[i] = NULL;
                }
                count = 0;
                for(int i=0; i<oldSize; i++){
                    mapNode<V>* head = temp[i];
                    while(head != NULL){
                        insert(head->key, head->value);
                        head = head->next;
                    }
                }

                for(int i=0; i<oldSize; i++){
                    delete temp[i];
                }
                delete [] temp;
            }
        public:

            double loadFactor(){
                return double((1.0*count)/bucketSize);
            }
            void insert(string key, V value){   //insert
                int bucketIndex = getBucketIndex(key);
                mapNode<V>* head = bucketArray[bucketIndex];

                while(head != NULL){
                    if(head->key == key){
                        head->value = value;
                        return;
                    }else{
                        head = head->next;
                    }
                }
                head = bucketArray[bucketIndex]; //as head was changed in while iteration so we need fresh value
                mapNode<V>* node = new mapNode<V>(key, value);
                node->next = head;
                bucketArray[bucketIndex] = node;
                count++; //to count no. of buckets created
                if(loadFactor() > 0.7){
                    rehash();
                }
            }

        V removeKey(string key){
            int bucketIndex =getBucketIndex(key);
            mapNode<V>* head = bucketArray[bucketIndex];
            mapNode<V>* prev = NULL;

            while(head != NULL){
                if(head->key == key){
                    if(prev == NULL){
                        bucketArray[bucketIndex] = head->next;
                    }else{
                        prev->next = head->next;
                    }
                    V value = head->value;
                    delete head;
                    count--;
                    return value;
                }
                prev = head;
                head = head->next;
            }

            return 0;
        }

        ~Bucket(){
            for(int i=0; i<bucketSize; i++){
                delete bucketArray[i];
            }
            delete [] bucketArray;
        }

};