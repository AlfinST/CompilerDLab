1. If your states are q0, q1, q2 they will be represented as follows (in the table)
	q0 = 2^0 = 1
	q1 = 2^1 = 2
	q2 = 2^2 = 4
2. Similarly union of states will be represented as - 
	q0,q1 = 2^0 + 2^1 = 3
	q1, q2 = 2^1 + 2^2 = 6
	q0,q1,q2 = 2^0 + 2^1 + 2^2 = 7
3. Do not give any condition for "phi"...
	Not Epsilons!!
4. Follow zero based indexing everywhere
5. Program assumes that if "Number of states are = n", then they are numbered as q0, q1, q2 ... q(n-1)

#### Original Source : https://gist.github.com/kipawa/10fec56cab1f8d0c33a9

### The bugs in the source was fixed and a better printing methd was added by me :P
