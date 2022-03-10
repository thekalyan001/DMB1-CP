//https://leetcode.com/problems/longest-palindromic-substring/
//https://www.youtube.com/watch?v=UflHuQj6MVA
//Naive
Generate all substring and check
Code
//https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
O(n^n *n) n^n for generating all substr, and O(nfor check all substr whether palindrome or not)


Dp 
O(n^n) 


fill the dp
ham check krennge for every indivisual element size 1 ke liye
then well check for every size 2 element


then iterate for every size k to n length element agar start digit and end digit same hai
&& beech wala string palindome hai to make that dp box true
eg- i=start, j=end
if(s[i]==s[j] && dp[i+1][j-1]) // i+1->j-1 beech ka substring
dp[i][j]=1; //yes it is palindrome



O(n)Manechars algorithm


#include <bits/stdc++.h>
using namespace std;

// Function to print a substring
// str[low..high]
void printSubStr(
	string str, int low, int high)
{
	for (int i = low; i <= high; ++i)
		cout << str[i];
}

int longestPalSubstr(string str)
{
	int n = str.size();

	// table[i][j] will be false if substring str[i..j] is not palindrome.
	// Else table[i][j] will be true
	bool table[n][n];

	memset(table, 0, sizeof(table));

	// All substrings of length 1 are palindromes
	int maxLength = 1;

	for (int i = 0; i < n; ++i)
		table[i][i] = true;

	// check for sub-string of length 2.
	int start = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (str[i] == str[i + 1]) {
			table[i][i + 1] = true;
			start = i;
			maxLength = 2;
		}
	}

	// Check for lengths greater than 2. k is length of substring
	for (int k = 3; k <= n; ++k) {
		// Fix the starting index
		for (int i = 0; i < n - k + 1; ++i) {
			// Get the ending index of substring from starting index i and length k
			int j = i + k - 1;

			//s[i] == s[j]  if boundary value matches, and dp[i + 1][j - 1] andr wala is palindrome
			if (table[i + 1][j - 1] && str[i] == str[j]) {
				table[i][j] = true;

				if (k > maxLength) {//update the maximum length
					start = i;
					maxLength = k;
				}
			}
		}
	}

	cout << "Longest palindrome substring is: ";
	printSubStr(str, start, start + maxLength - 1);

	// return length of LPS
	return maxLength;
}

int main()
{
	string str = "forgeeksskeegfor";
	cout << "\nLength is: "
		<< longestPalSubstr(str);
	return 0;
}
