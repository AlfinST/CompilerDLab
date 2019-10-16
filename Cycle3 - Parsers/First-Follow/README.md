## In Program
  AddProductionToList adds to Productions_List the Production and  
  Creates a Table like:
|Variable_Numeber|Production_Number|Production|
|:-----:|:-----:|:-----:|
|0|0|A+A|
|0|1|A*A|
|0|2|A/A|
|1|0|id|
|.|.|.|
|.|.|.|

  Variabel List is a table like:
Variable_Number		|		Variable
:----------:|:------------:
0			|		S
1			|		A		
2			|		B
.			|		.
.			|		.

## For Calculating First:

- For a production rule X → ∈,
    - First(X) = { ∈ }

- For any terminal symbol ‘a’
    - First(a) = { a }

- For a production rule X → Y1Y2Y3
        
        Calculating First(X)
        
        If ∈ ∉ First(Y1), then First(X) = First(Y1)
        If ∈ ∈ First(Y1), then First(X) = { First(Y1) – ∈ } ∪ First(Y2Y3)
        
        Calculating First(Y2Y3)
        
        If ∈ ∉ First(Y2), then First(Y2Y3) = First(Y2)
        If ∈ ∈ First(Y2), then First(Y2Y3) = { First(Y2) – ∈ } ∪ First(Y3)
        
        Similarly, we can make expansion for any production rule X → Y1Y2Y3…..Yn.

## For Calcuating Follow:
    
- For the start symbol S, place $ in Follow(S).
- For any production rule A → αB,
                        Follow(B) = Follow(A)
- For any production rule A → αBβ,
    - If ∈ ∉ First(β), then Follow(B) = First(β)
    - If ∈ ∈ First(β), then Follow(B) = { First(β) – ∈ } ∪ Follow(A)

## Important Notes:
- ### Note-01:
        ∈ may appear in the first function of a non-terminal.
        ∈ will never appear in the follow function of a non-terminal.
        
- ### Note-02:
        Before calculating the first and follow functions, eliminate Left Recursion from the grammar, if present.

- ### Note-03:
    
        We calculate the follow function of a non-terminal by looking where it is present on the RHS of a production rule.
