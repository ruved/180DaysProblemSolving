class Solution {
public:
    vector<int> pivotArray(vector<int>& n, int p) 
{
	for(int d{2}; d<2*size(n); d<<=1)
		for(auto b{begin(n)}, m{b}, e{b}; b<end(n); b=e)
		{
			m = min(b+d/2, end(n)),
			e = min(b+d,   end(n));
			auto l = lower_bound(b, m, p),
				 h = upper_bound(m, e, p);
			rotate(l, m, h);
		}
	return n;
}
};