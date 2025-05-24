# Fibonacci Rápido

## 📄 Descrição do problema

Calcule o valor de Fib(N) módulo 10^9+7, onde a sequência de Fibonacci é definida por:

- Fib(0) = 0
- Fib(1) = 1
- Fib(n) = Fib(n-1) + Fib(n-2), para n ≥ 2

O valor de N pode ser muito grande, até 10^18, então é necessário um algoritmo eficiente para calcular Fib(N) sem exceder o tempo.

---

## 💡 Solução

Para calcular Fibonacci de números grandes rapidamente, não podemos usar métodos recursivos simples ou iteração linear — eles seriam lentos e impraticáveis para N até 10^18.

A solução é usar **exponenciação rápida de matrizes**.

### Matriz base da Fibonacci:

\[
A = 
\begin{bmatrix}
1 & 1 \\
1 & 0
\end{bmatrix}
\]

Temos que:

\[
A^n = 
\begin{bmatrix}
Fib(n+1) & Fib(n) \\
Fib(n) & Fib(n-1)
\end{bmatrix}
\]

Logo, para calcular Fib(N), basta calcular \(A^{N-1}\) e pegar o elemento \(A^{N-1}_{0,0} = Fib(N)\).

### Passos da solução:

1. **Construir a matriz base \(A\)**.
2. **Fazer a exponenciação rápida de matriz usando o método "fast exponentiation"**:
   - Se \(e\) é o expoente, calcule \(A^e\) em \(O(\log e)\) multiplicações.
3. **Tratar o caso especial quando N = 0**, retornando 0 diretamente.
4. **Aplicar o módulo \(10^9 + 7\)** em todas as operações para evitar overflow.
