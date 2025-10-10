impl Solution {
    pub fn maximum_energy(energy: Vec<i32>, k: i32) -> i32 {
        let mut result = i32::MIN;
        let mut sums = vec![0;energy.len()];
        for idx in 0..k as usize {
            let mut sum = 0;
            for idx2 in (idx..energy.len()).step_by(k as usize) {
                sum += energy[idx2];
                sums[idx2] = sum;
            }            
        }
        let k = k as usize;
        for idx in 0..sums.len() {
            let mut sum = sums[idx+k*((sums.len()-1-idx)/k)];
            if idx >= k {sum -= sums[idx-k]}
            result = result.max(sum);
        }
        result
    }
}
