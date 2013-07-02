// Without lazy

#define lc (id<<1)
#define rc (id<<1|1)
#define mid (l+r>>1)

void wash(int id) {
	// Merge lc and rc
}

void born(int l, int r, int id) {
	if (l == r) {
		// Init leaf
		return;
	}
	born(l, mid, lc);
	born(mid+1, r, rc);
	wash(id);
}

void upd(int l, int r, int id, int p, int v) {
	if (l == r) {
		// Update leaf
		return;
	}
	if (p <= mid) upd(l, mid, lc, p, v);
	else upd(mid+1, r, rc, p, v);
	wash(id);
}
