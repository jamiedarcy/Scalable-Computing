# Determining n0 thresholds
# Determine the n0 thresholds such that the following complexity measures are true.

# O(n2 + 4n + 8) < O(n3)
#2. O(n3 + 3n + 1) < O(n4)
#3. O(n2 + 16n + 11) < O(n3 + 4n)
#4. O(n2 + 4n + 16) < O(n3)

n <- c(1:10)
plot(n^2 + 4*n + 8)
lines(n^3)
x11()
plot(n^3 + 3 * n + 1)
lines(n^4)
x11()
plot(n^2 + 16*n +11)
lines(n^3+4*n)
x11()
plot(n^2 + 4*n + 16 )
lines(n^3)
