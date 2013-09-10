template<typename T>
class Splay {
public:
    struct Node {
        Node* fa_;
        Node* chd_[2];
        int size_;
        T val_;
        Node(const T& val) : fa_(NULL), size_(1), val_(val) {
            chd_[0] = NULL;
            chd_[1] = NULL;
        }
        inline void update() {
            size_ = size(chd_[0]) + 1 + size(chd_[1]);
        }
    };

    Splay() : root_(NULL) {
    }
    int size() const {
        return size(root_);
    }
    inline static int size(const Node* p) {
        return p == NULL ? 0 : p->size_;
    }
    inline static int direct(const Node* p) {
        return p->fa_ != NULL and p->fa_->chd_[0] == p ? 0 : 1;
    }
    inline static void link(Node* fa, Node* chd, int dir) {
        if (fa != NULL) fa->chd_[dir] = chd;
        if (chd != NULL) chd->fa_ = fa;
    }

    Node* assign(const T* begin, const T* end) {
        if (begin >= end) return NULL;
        const T* middle = begin + (end - begin) / 2;
        Node* newbie = new Node(*middle);
        Node* l = assign(begin, middle);
        Node* r = assign(middle + 1, end);
        link(newbie, l, 0);
        link(newbie, r, 1);
        newbie->update();
        root_ = newbie;
        return newbie;
    }

    Node* select(int k) const {
        if (k >= size()) return NULL;
        for (Node* p = root_; ; ) {
            int left_size = size(p->chd_[0]);
            if (left_size == k) return p;
            if (k < left_size) {
                p = p->chd_[0];
            } else {
                k -= left_size + 1;
                p = p->chd_[1];
            }
        }
    }

    void insert(int k, const T& val) {
        Node* kth = select(k);
        Node* newbie = new Node(val);
        if (kth != NULL) {
            link(newbie, kth->chd_[0], 0);
            link(kth, newbie, 0);
        } else {
            link(newbie, root_, 0);
            root_ = newbie;
        }
        splay(newbie, NULL);
    }

    void splay(Node* cur, Node* top) {
        while (cur->fa_ != top) {
            if (cur->fa_->fa_ == top) {
                rotate(cur);
            } else if (direct(cur) == direct(cur->fa_)) {
                rotate(cur->fa_);
                rotate(cur);
            } else {
                rotate(cur);
                rotate(cur);
            }
        }
        cur->update();
    }

private:
    inline void rotate(Node* x) {
        Node* fa = x->fa_;
        int dir = direct(x);
        link(fa, x->chd_[dir^1], dir);
        link(fa->fa_, x, direct(fa));
        link(x, fa, dir^1);
        fa->update();
        if (x->fa_ == NULL) root_ = x;
    }

    Node* root_;
};
