class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        Set<Integer>mp=new HashSet<Integer>();
        List<Integer>st=new ArrayList<Integer>();
        for(int i=0;i<nums.length;++i)
        {
            if(mp.contains(nums[i]))
            st.add(nums[i]);
            else
            mp.add(nums[i]);
        }
        return st;
    }
}