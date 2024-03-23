// https://leetcode.com/problems/integer-to-roman

class Solution{ //(1 <= num <= 3999)
    public String intToRoman(int num) { 
        String unita[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; 
        String decine[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        String centinaia[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        String migliaia[] = {"", "M", "MM", "MMM"};
        
        return migliaia[num/1000]+centinaia[(num%1000)/100]+decine[(num%100)/10]+unita[(num%10)];
    } 
}