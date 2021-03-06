# Scalable Computing - Week 2 Lab
# Loading Data Tables into R and Performing basic analysis
# Jamie Darcy - 26/09/2016

#Set Working Directory
setwd('C:/Users/jdarcy/Documents/GitHub/Scalable-Computing/R')

#read the file in
file <- file.path("SC-Lab2","mpstat.txt")
mydata <- read.table(file, header = TRUE)

#Print colnames from datafile
print(colnames(mydata))

#plot the idle time of this CPU
plot(main="CPU Usage - Idle Time", mydata$X.idle)
x11()

#Plot the busy time of this CPU - (100 - idle)
busytime <-100-mydata$X.idle
plot(main="CPU Usage - Busy Time", busytime)


#Find the min, max and mean of the data
print(summary(busytime))
#or print it out one by one
cat("Mean busy time : ", mean(busytime))
cat("Min busy time : ", min(busytime))
cat("Max busy time : ", max(busytime))

#boxplot data
boxplot(busytime, main="CPU Usage") 

#scaterplot data
plot(busytime, mydata$X.idle, main="Scatterplot CPU Usage", 
     xlab="Car Weight ", ylab="Miles Per Gallon ", pch=19) 


plot(density(busy))
