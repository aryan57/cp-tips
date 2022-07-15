class dsu{
public:
	vector<int> p,sz;
	dsu(int n){
		p = vector<int> (n);
		sz = vector<int> (n);
		
		for(int i=0;i<n;i++){
			p[i]=i;
			sz[i]=1;
		}
	}
	
	int get(int i){
		return (p[i] = (p[i]==i?i:get(p[i])));
	}
	int set(int x,int y){
		x=get(x);
		y=get(y);
		if(x==y)return x;
		
		if(sz[x]<sz[y])swap(x,y);
		p[y]=x;
		sz[x]+=sz[y];
		return x;
	}
};
