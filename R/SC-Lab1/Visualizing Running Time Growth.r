#Visualizing Running Time Growth
#Using R, generate a single plot showing the running time growth of the following f(n) measures as n grows in the range 0 ≤ n ≤ 30 


#fill a vector with 1000 integers in a range 1:1000 again call the vector
n <- c(1:100)
plot(n^3 + n^2 + 2*n)
x11()
plot(n^2 + 3 * n + 1)
x11()
plot(log(n)+n)
x11()
plot(n * log (n))