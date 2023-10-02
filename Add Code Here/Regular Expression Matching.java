public class Solution {
    public static boolean isMatch(String s, String p) {
        int m = s.length();
        int n = p.length();

        // Create a DP table with dimensions (m+1) x (n+1)
        boolean[][] dp = new boolean[m + 1][n + 1];

        // Empty pattern matches empty string
        dp[0][0] = true;

        // Fill in the first row of the DP table
        for (int j = 1; j <= n; j++) {
            if (p.charAt(j - 1) == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill in the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p.charAt(j - 1) == s.charAt(i - 1) || p.charAt(j - 1) == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p.charAt(j - 1) == '*') {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s.charAt(i - 1) == p.charAt(j - 2) || p.charAt(j - 2) == '.'));
                }
            }
        }

        return dp[m][n];
    }

    public static void main(String[] args) {
        // Input from the user
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the input string s: ");
        String s = scanner.nextLine();
        System.out.print("Enter the pattern string p: ");
        String p = scanner.nextLine();

        // Check if the input string matches the pattern
        if (isMatch(s, p)) {
            System.out.println("Output: true");
        } else {
            System.out.println("Output: false");
        }
    }
}
