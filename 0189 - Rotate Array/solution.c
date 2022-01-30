int gcd(int a, int b) {return a%b?gcd(b, a%b):b;}
void rotate(int* nums, int numsSize, int k){
    int n = numsSize, t = gcd(k, n); k %= n;
    for(int i = 0; i < t; i++){
        int tmp = nums[(i+k)%n], id = i;
        while(id != (i+k)%n){
            nums[(id+k)%n] = nums[id];
            id = (id-k+n)%n;
        }
        nums[(id+k)%n] = tmp;
    }
}