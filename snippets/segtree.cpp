class segtree{
public:
	using S = int;
	int n,log,sz;
	vector<S> v;

	S e(){
		return 0;
	}

	S op(S a,S b){
		return a+b;
	}

	void update(int i){
		v[i]=op(v[2*i],v[2*i+1]);
	}

	segtree(vector<S> d){
		n=d.size();
		log = 0;
		while((1<<log)<n)log++;
		sz = (1<<log);
		v = vector<S> (2*sz,e());

		for(int i=0;i<n;i++)v[i+sz]=d[i];
		for(int i=sz-1;i>=1;i--)update(i);
	}

	S get(int i){
		return v[i+sz];
	}

	void set(int i,S x){
		i+=sz;
		v[i]=x;
		for(int bit=log;bit>0;bit--)update(i>>bit);
	}

	S prod(int l,int r){
		l+=sz;
		r+=sz;
		S sml=e(),smr=e();
		while (l<r)
		{
			if(l&1)sml=op(sml,v[l++]);
			if(r&1)smr=op(smr,v[--r]);
			l>>=1;
			r>>=1;
		}
		return op(sml,smr);
	}
};
