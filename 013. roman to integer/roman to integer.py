# https://leetcode.com/problems/roman-to-integer/description/

class Solution:
    def romanToInt(self, s):
        n=0
        read=0
        i=1

        while i<len(s):
            c=s[i]
            p=s[i-1]
            intC=self.romanCharToInt(c)
            intP=self.romanCharToInt(p)
            
            if ( (c=="V" or c=="X") and p=="I") or \
               ( (c=="L" or c=="C") and p=="X") or \
               ( (c=="D" or c=="M") and p=="C"):
                n+=intC-intP
                i+=2
                read+=2                
            else:
                n+=intP
                read+=1
                i+=1
        
        if read==len(s)-1:
            n+=self.romanCharToInt(s[len(s)-1])
        
        return n
    
    def romanCharToInt(self, x):
        if x=="I": return 1
        elif x=="V": return 5
        elif x=="X": return 10
        elif x=="L": return 50
        elif x=="C": return 100
        elif x=="D": return 500
        elif x=="M": return 1000
        return -1