public class Solution {
    public int CarFleet(int target, int[] position, int[] speed) {
        Dictionary<double, double> timeToDest = new Dictionary<double, double>();
        int[][] pair = new int[position.Length][];
        double temp = 0;

        for (int i = 0; i < position.Length; i++) {
            pair[i] = new int[] { position[i], speed[i] };
        }
        Array.Sort(pair, (a, b) => b[0].CompareTo(a[0]));

        for (int i = 0; i < position.Length; i++) {
            double time = (double)(target - pair[i][0]) / pair[i][1];
        
            if (time > temp) {
                timeToDest.Add(time, i);
                temp = time;
            }
        }
        return timeToDest.Count;
    }
}