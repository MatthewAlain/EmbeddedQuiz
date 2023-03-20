Answers

Q2 a) The function f(Ai) is a numerical encoding from Decimal to Base62. Below is an index showing the Decimal value of the digits used for the Base62 encoding.
In each column, the left side number shows the Decimal value of the corresponding right side Base62 digit.

D-B62

0-C	|	21-5	|	42-4
1-7	|	22-D	|	43-Y
2-x	|	23-3	|	44-j
3-i	|	24-B	|	45-S
4-c	|	25-6	|	46-e
5-P	|	26-H	|	47-U
6-M	|	27-0	|	48-h
7-G	|	28-O	|	49-I
8-v	|	29-u	|	50-R
9-z	|	30-p	|	51-J
10-A	|	31-8	|	52-g
11-Z	|	32-E	|	53-a
12-y	|	33-2	|	54-f
13-T	|	34-1	|	55-F
14-N	|	35-W	|	56-t
15-o	|	36-9	|	57-r
16-d	|	37-s	|	58-K
17-m	|	38-q	|	59-l
18-w	|	39-L	|	60-b
19-n	|	40-Q	|	61-k
20-V	|	41-X

Q2 b)
f(30001) = GIF
f(55555) = NOi
f(77788) = VNQ

Q2 c) Given that the transformation is from Decimal to Base62 any unique Decimal input should have a unique Base62 output. However, if the input is constrained 
to five Decimal digits the maximum output before an overflow would occur is at f(99999) = HCF. Likewise, if the output only allows for three digits the maximum 
output would occur at kkk. Converted back to Decimal kkk is equal to 238327 Decimal. Any input past 238327 would likely result in repeat outputs.

Q2 d) Included in the repository in the Question_2 folder is the code used to verify and find the value of the Base62 digits. I downloaded the sample data as quiz.csv.