// 208. Implement Trie (Prefix Tree)

type Trie struct {
	S map[rune]*Trie
	C int
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{S: make(map[rune]*Trie)}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	k := this

	for _, v := range word {
		if _, ok := k.S[v]; !ok {
			c := Constructor()
			k.S[v] = &c
		}
		k = k.S[v]
	}
	k.C += 1
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	k := this
	for _, v := range word {
		if l, ok := k.S[v]; ok {
			k = l
		} else {
			return false
		}
	}
	return k.C >= 1
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {

	k := this
	for _, v := range prefix {
		if l, ok := k.S[v]; ok {
			k = l
		} else {
			return false
		}
	}
	return true

}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */