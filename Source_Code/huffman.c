void Huffman(){
	for(int i = 1 ; i <= n-1 ; i++){
		u = PQ_delete();
		v = PQ_delete();
		w = make_a_new_node();
		w->left = u;
		w->right = v;
		w->freq = u->freq + v->freq;
		PQ_insert(w);
	}
	w = PQ_delete();
	

}